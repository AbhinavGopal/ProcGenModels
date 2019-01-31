#import <stdio.h>
#import <stdlib.h>
#import <stdbool.h>
#include "Board.h"
#include "win.h"
bool isWin(Board Board){
    return(hwin(Board)||vwin(Board)||dwin(Board));
}
bool hwin(Board Board){
    int NumInARow=0;
    char letter;
    for(int i=0;i<Board.r;i++){
        for (int j=0;j<Board.c;j++){
            if (Board.display[i][j]==Board.BlankChar){
                NumInARow=0;
                continue;
            }
            else if (Board.display[i][j]!=letter){
                letter=Board.display[i][j];
                NumInARow=1;
            }
            else{
                letter=Board.display[i][j];
                NumInARow++;
            }
            if (NumInARow==Board.number){
                return true;
            }
        }
        NumInARow=0;
    }
    return false;
}

bool vwin(Board Board){}

bool dwin(Board Board){}