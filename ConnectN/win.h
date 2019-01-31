//
// Created by Abhinav Gopal on 2019-01-29.
//

#ifndef CONNECTN_WIN_H
#define CONNECTN_WIN_H
#include <stdio.h>
#include <stdbool.h>
#include "Board.h"

bool isWin(Board board);
bool hwin(Board board);
bool vwin(Board board);
bool dwin(Board board);

#endif //CONNECTN_WIN_H
