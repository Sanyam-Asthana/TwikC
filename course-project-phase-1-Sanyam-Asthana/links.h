#include <stdio.h>


// Definition for the Link struct
typedef struct
{
    int row1, row2;
    int column1, column2;
    char color;
} Link;


/**
 * @brief Adds a link to the allLinks array
 * @param row1 Row index of the first point
 * @param row2 Row index of the second point
 * @param column1 Column index of the first point
 * @param column2 Column index of the second point
 * @param color Color whose link is to be added
 */
void addLink(int row1, int row2, int column1, int column2, char color);

/**
 * @brief Prints all the links
 */
void printAllLinks();

/**
 * @brief Checks for the possible links that could be formed because of the peg positions
 * @param row The row which is to be added
 * @param column The column which is to be added
 */
void checkForPossibleLinks(int row, int column, char color);

/**
 * @brief Calculates the orientation of three points by calculating their vector product
 * @param row1 The row index of the 1st point
 * @param row2 The row index of the 2nd point
 * @param row3 The row index of the 3rd point
 * @param column1 The column index of the 1st point
 * @param column2 The column index of the 2nd point
 * @param column3 The column index of the 3rd point
 * @return Returns 1, 0 or -1 depending on the orientation
 */
int calculateOrientation(int row1, int column1, int row2, int column2, int row3, int column3);

/**
 * @brief Returns if two possible links overlap
 * @param row1 The row index of the 1st point
 * @param row2 The row index of the 2nd point
 * @param row3 The row index of the 3rd point
 * @param row4 The row index of the 4th point
 * @param column1 The column index of the 1st point
 * @param column2 The column index of the 2nd point
 * @param column3 The column index of the 3rd point
 * @param column4 The column index of the 4th point
 */
int isLinkOverlap(int row1, int column1, int row2, int column2, int row3, int column3, int row4, int column4);

/**
 * @brief Getter function for the allLinks array
 * @return Returns the allLinks array
 */
Link *getAllLinks();

/**
 * @brief Getter function for the numberOfLinks variable
 * @return Returns the numberOfLinks variable
 */
int getNumberOfLinks();
