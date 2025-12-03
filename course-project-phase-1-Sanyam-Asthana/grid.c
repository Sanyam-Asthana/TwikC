#include <stdio.h>
#include "grid.h"
#include "holi.h"
#include <stdlib.h>
#include "io_utils.h"
#include <string.h>
#include "links.h"

char grid[GRID_SIZE][GRID_SIZE] = GRID;

void printPeg(int rowIndex, int columnIndex)
{
    if(grid[rowIndex][columnIndex] == '.')
        printf(CYAN "· " RESET);
    else if(grid[rowIndex][columnIndex] == 'R')
        printf(BOLD_RED "● " RESET);
    else if(grid[rowIndex][columnIndex] == 'B')
        printf(BOLD_BLUE "● " RESET);
}


void gridChangeColorOfCell(int row, int column, char color)
{
    grid[row][column] = color;
}



void printGrid()
{
    clearScreen();

    char visualGrid[DISPLAY_SIZE][DISPLAY_SIZE];
    char colorGrid[DISPLAY_SIZE][DISPLAY_SIZE];

    for(int i=0; i < DISPLAY_SIZE; i++) {
        for(int j=0; j < DISPLAY_SIZE; j++) {
            visualGrid[i][j] = ' ';
            colorGrid[i][j] = ' ';
        }
    }

    for(int row =0; row < GRID_SIZE; row++) {
        for(int column = 0; column < GRID_SIZE; column++) {
            int visualRow = row * 2;
            int visualColumn = column * 2;
            if (grid[row][column] != '.') {
                visualGrid[visualRow][visualColumn] = 'P';
                colorGrid[visualRow][visualColumn] = grid[row][column];
            } else {
                visualGrid[visualRow][visualColumn] = '.';
                colorGrid[visualRow][visualColumn] = ' ';
            }
        }
    }

    for(int i=0; i<getNumberOfLinks(); i++) {
        int row1 = getAllLinks()[i].row1;
        int column1 = getAllLinks()[i].column1;
        int row2 = getAllLinks()[i].row2;
        int column2 = getAllLinks()[i].column2;
        char color = getAllLinks()[i].color;

        int midRow = row1 + row2;
        int midColumn = column1 + column2;
        char shape;

        if ((row2 - row1) * (column2 - column1) > 0) {
            shape = 'b';
        } else {
            shape = 'f';
        }

        if (visualGrid[midRow][midColumn] != ' ' && visualGrid[midRow][midColumn] != shape) {
            visualGrid[midRow][midColumn] = ' ';
        }
        else {
            visualGrid[midRow][midColumn] = shape;
            colorGrid[midRow][midColumn] = color;
        }
    }

    printf("   ");
    for(int column = 0; column < GRID_SIZE; column++) printf(BOLD_YELLOW "%c   " RESET, 'a' + column);
    printf("\n");

    for(int i = 0; i < DISPLAY_SIZE; i++) {

        if (i % 2 == 0) printf(BOLD_YELLOW "%2d " RESET, i/2);
        else            printf("   ");

        for(int j = 0; j < DISPLAY_SIZE; j++) {
            char type = visualGrid[i][j];
            char color  = colorGrid[i][j];

            char* ansiColor = RESET;
            if (color == 'R') ansiColor = BOLD_RED;
            else if (color == 'B') ansiColor = BOLD_BLUE;
            else if (color == 'W') ansiColor = BOLD_WHITE;

            if (type == 'P') {
                printf("%s●" RESET, ansiColor);
            } else if (type == '.') {
                if(i == DISPLAY_SIZE - 1 || i == 0)
                    printf(RED "○" RESET);
                else if(j == DISPLAY_SIZE - 1 || j == 0)
                    printf(BLUE "○" RESET);
                else
                    printf(GRAY "○" RESET);
            } else if (type == 'b') {
                printf("%s%s" RESET, ansiColor, LINK_L);
            } else if (type == 'f') {
                printf("%s%s" RESET, ansiColor, LINK_R);
            } else {
                printf(" ");
            }

            if (j < DISPLAY_SIZE - 1) printf(" ");
        }
        printf("\n");
    }
}
