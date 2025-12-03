#include <stdio.h>
#include "io_utils.h"
#include <stdlib.h>
#include "holi.h"

void clearScreen()
{
    #ifdef _WIN32 // Detects the Operating System and runs the appropriate command to clear the terminal screen
        system("cls");
    #else
        system("clear");
    #endif
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void printBanner()
{
    // Banner
    printf(BOLD_BLUE " _____          _ _     ____ \n");
    printf(BOLD_GREEN "|_   _|_      _(_) | __/ ___|\n");
    printf(BOLD_YELLOW "  | | \\ \\ /\\ / / | |/ / |    \n");
    printf(BOLD_ORANGE "  | |  \\ V  V /| |   <| |___ \n");
    printf(BOLD_RED "  |_|   \\_/\\_/ |_|_|\\_\\____|\n" RESET);
}
