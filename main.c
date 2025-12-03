#include "grid.h"
#include "holi.h"
#include <locale.h>
#include <stdio.h>
#include "io_utils.h"
#include "grid_logic.h"
#include <stdlib.h>
#include "win_logic.h"
#define FOREVER 1

int main() {

  printBanner();
  setlocale(LC_ALL, ""); // Setting up the code for non-alphanumeric unicode characters

  printf(BLINK "Press any key to start!\n" RESET);
  char placeholderChar;
  scanf("%c", &placeholderChar);

  clearInputBuffer();

  while(FOREVER) {
    int doesUserWantToExit = 0;

    printGrid();

    doesUserWantToExit = handleInputAndGrid('R');
    // printAllLinks(); This was used during debugging
    if (hasPlayerWon('R', getAllLinks(), getNumberOfLinks())) {
        printGrid();
        printf(BOLD_RED "RED WINS!\n" RESET);
        break;
    }

    if(doesUserWantToExit)
    {
        break;
    }

    printGrid();
    doesUserWantToExit = handleInputAndGrid('B');
    if (hasPlayerWon('B', getAllLinks(), getNumberOfLinks())) {
        printGrid();
        printf(BOLD_BLUE "BLUE WINS!\n" RESET);
        break;
    }
    // printAllLinks(); This was used during debugging

    if(doesUserWantToExit)
    {
        break;
    }

  }

  printf("Bye!\n");
  return 0;

}
