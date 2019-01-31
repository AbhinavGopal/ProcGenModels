#include <stdio.h>
#include "win.h"
#include "Board.h"
#include <ncurses.h>
int main(int argc, char* argv[]) {
    int r;
    int c;
    static int number;
    sscanf(argv[1],"%d", &c);
    sscanf(argv[2],"%d",&r);
    sscanf(argv[3],"%d",&number);
    char * filepath=argv[4];
    return 0;
}

