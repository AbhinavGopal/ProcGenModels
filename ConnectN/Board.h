#ifndef CONNECTN_BOARD_H
#define CONNECTN_BOARD_H
#include <stdio.h>
#include <stdbool.h>
typedef struct Board_struct{
    char** display;
    int r;
    int c;
    char BlankChar;
    int number;
    char * path;
}Board;
Board init(int r, int c, char BlankChar, char * path);
void PrintBoard(Board board);
void CleanUpBoard(Board * board);
#endif //CONNECTN_BOARD_H
