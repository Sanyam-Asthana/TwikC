#include <stdbool.h>
#include "grid.h"
#include "win_logic.h"

int hasPlayerWon(char playerWhoseTurnIsNow, Link allLinks[], int numberOfLinks) {
    bool visitedCells[GRID_SIZE][GRID_SIZE] = {false};
    Point cellsToCheck[GRID_SIZE * GRID_SIZE];
    int startIterator = 0, endIterator = 0;

    if (playerWhoseTurnIsNow == 'R') {
        for (int column = 0; column < GRID_SIZE; column++) {
            if (grid[0][column] == 'R') {
                cellsToCheck[endIterator++] = (Point){0, column};
                visitedCells[0][column] = true;
            }
        }
    } else {
        for (int row = 0; row < GRID_SIZE; row++) {
            if (grid[row][0] == 'B') {
                cellsToCheck[endIterator++] = (Point){row, 0};
                visitedCells[row][0] = true;
            }
        }
    }

    while (startIterator < endIterator) {
        Point current = cellsToCheck[startIterator++];

        if (playerWhoseTurnIsNow == 'R' && current.row == GRID_SIZE - 1) return 1;
        if (playerWhoseTurnIsNow == 'B' && current.column == GRID_SIZE - 1) return 1;

        for (int i = 0; i < numberOfLinks; i++) {
            if (allLinks[i].color != playerWhoseTurnIsNow) continue;

            int nextRow = -1, nextColumn = -1;

            if (allLinks[i].row1 == current.row && allLinks[i].column1 == current.column) {
                nextRow = allLinks[i].row2;
                nextColumn = allLinks[i].column2;
            }
            else if (allLinks[i].row2 == current.row && allLinks[i].column2 == current.column) {
                nextRow = allLinks[i].row1;
                nextColumn = allLinks[i].column1;
            }

            if (nextRow != -1 && !visitedCells[nextRow][nextColumn]) {
                visitedCells[nextRow][nextColumn] = true;
                cellsToCheck[endIterator++] = (Point){nextRow, nextColumn};
            }
        }
    }

    return 0;
}
