#include <stdio.h>
#include "links.h"
#include "grid.h"
#define COLLINEAR 0
#define SAME_SIDE 1
#define DIFF_SIDE -1

int numberOfLinks = 0;

Link allLinks[500];

void addLink(int row1, int row2, int column1, int column2, char color)
{
    Link* currentLink = &allLinks[numberOfLinks];

    currentLink -> row1 = row1;
    currentLink -> row2 = row2;
    currentLink -> column1 = column1;
    currentLink -> column2 = column2;
    currentLink -> color = color;

    numberOfLinks++;
}

void checkForPossibleLinks(int row, int column, char color)
{
    int possibleDirectionsForRows[] = {-2, -2, -1, -1,  1,  1,  2,  2};
    int possibleDirectionsForColumns[] = {-1,  1, -2,  2, -2,  2, -1,  1};

    for (int j = 0; j < 8; j++) {
        int nextRow = row + possibleDirectionsForRows[j];
        int nextCol = column + possibleDirectionsForColumns[j];

        if (nextRow >= 0 && nextRow < GRID_SIZE &&
            nextCol >= 0 && nextCol < GRID_SIZE &&
            grid[nextRow][nextCol] == color)
        {
            int crossingFound = 0;

            for(int i = 0; i < numberOfLinks; i++)
            {
                int existingRow1 = allLinks[i].row1;
                int existingRow2 = allLinks[i].row2;
                int existingColumn1 = allLinks[i].column1;
                int existingColumn2 = allLinks[i].column2;

                if (isLinkOverlap(row, column, nextRow, nextCol, existingRow1, existingColumn1, existingRow2, existingColumn2)) {
                    printf("Cannot link! Overlaps with existing link.\n");
                    crossingFound = 1;
                    break;
                }
            }

            if (crossingFound == 0) {
                addLink(row, nextRow, column, nextCol, color);
            }
        }
    }
}

int isLinkOverlap(int row1, int column1, int row2, int column2, int row3, int column3, int row4, int column4) {

    int rows[] = {row1, row2, row3};
    int columns[] = {column1, column2, column3};

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if((rows[i] == rows[j] && i != j) && (columns[i] == columns[j] && i != j))
            {
                return 0;
            }
        }
    }

    int orientations[4];

    for(int i = 0; i < 2; i++)
    {
        orientations[i] = calculateOrientation(rows[0], rows[1], rows[i + 2], columns[0], columns[1], columns[i + 2]);
    }


    for(int i = 2; i < 4; i++)
    {
        orientations[i] = calculateOrientation(rows[0], rows[1], rows[i - 2], columns[0], columns[1], columns[i + 2]);
    }


    if (orientations[0] != orientations[1] && orientations[2] != orientations[3]) {
        return 1;
    }

    return 0;
}

int calculateOrientation(int row1, int row2, int row3, int column1, int column2, int column3)
{
    int vectorRow1 = row1 - row2;
    int vectorRow2 = row3 - row2;

    int vectorColumn1 = column1 - column2;
    int vectorColumn2 = column3 - column2;

    int vectorProduct = (vectorRow1 * vectorColumn2) - (vectorRow2 * vectorColumn1);

    if(vectorProduct == 0)
    {
        return COLLINEAR;
    }
    else
    {
        return (vectorProduct > 0) ? SAME_SIDE : DIFF_SIDE;
    }
}

void printAllLinks()
{
    for(int i = 0; i < numberOfLinks; i++)
    {
        Link currentLink = allLinks[i];
        printf("i: %d, r1: %d, r2: %d, c1: %c, c2: %c, clr: %c\n", i, currentLink.row1, currentLink.row2, currentLink.column1 + 'a', currentLink.column2 + 'a', currentLink.color);
    }
}

Link *getAllLinks()
{
    return(allLinks);
}

int getNumberOfLinks()
{
    return(numberOfLinks);
}
