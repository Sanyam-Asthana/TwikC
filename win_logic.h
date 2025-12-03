#include <stdio.h>
#include "links.h"

// Definition for the Point struct
typedef struct {
    int row, column;
} Point;

/**
 * @brief Checks if a player has won depending on the positions of the pegs
 * @param player The players whose turn is now
 * @param allLinks The allLinks array
 * @param numberOfLinks The numberOfLinks variable
 * @return Returns if the player has won
 */
int hasPlayerWon(char player, Link allLinks[], int numberOfLinks);
