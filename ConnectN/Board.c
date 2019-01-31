#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "Board.h"
Board init(int r, int c, char BlankChar, char * path){
    Board initial;
    initial.r=r;
    initial.c=c;
    initial.BlankChar=BlankChar;
    initial.path= path;
    initial.display=malloc(r * sizeof(char*)) ;
    int i=0;
    while (i<r){
        initial.display[i]=malloc(c*sizeof(char));
        i++;
    }
    for (int q=0; q<r; q++){
        for (int l=0;l<r;l++){
            initial.display[q][l]=BlankChar;
        }
    }
    return initial;
}
