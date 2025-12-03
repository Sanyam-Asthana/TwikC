#include <stdio.h>
#include "grid.h"
#define FOREVER 1
#include "io_utils.h"
#include "holi.h"
#include <stdlib.h>
#include "grid_logic.h"
#include "links.h"

int handleInputAndGrid(char colorWhoseTurnIsNow)
{
    int rowInput = 0;
    char columnInput = '\0';

    const char* colorName = (colorWhoseTurnIsNow == 'R') ? "Red" : "BLUE";
    const char* colorAnsi = (colorWhoseTurnIsNow == 'R') ? RED : BLUE;

    while (FOREVER) {

      printf("\n%s%s's turn | Format: [row column]\n", colorAnsi, colorName);
      printf("%sEnter \"404\" to Exit..\n\n" RESET, colorAnsi);

      scanf("%d", &rowInput);
      if(rowInput == 404)
      {
        return 1;
      }

      scanf(" %c", &columnInput);
      clearInputBuffer();

      int columnIndex = (int)columnInput - 'a';

      if (rowInput >= 0 && rowInput <= GRID_SIZE - 1 &&  columnIndex >= 0 && columnIndex <= GRID_SIZE - 1 && grid[rowInput][columnIndex] == '.' && !(rowInput == 0 && columnIndex == 0) && !(rowInput == 0 && columnIndex == GRID_SIZE - 1) && !(rowInput == GRID_SIZE - 1 && columnIndex == 0) && !(rowInput == GRID_SIZE - 1 && columnIndex == GRID_SIZE - 1) && !(colorWhoseTurnIsNow == 'R' && (columnIndex == 0 || columnIndex == GRID_SIZE - 1)) && !(colorWhoseTurnIsNow == 'B' && (rowInput == 0 || rowInput == GRID_SIZE - 1))) {

            gridChangeColorOfCell(rowInput, columnIndex, colorWhoseTurnIsNow);
            checkForPossibleLinks(rowInput, columnIndex, colorWhoseTurnIsNow);

        break;
      }
      printf("Invalid Input!\n");

    }

    return 0;
}
