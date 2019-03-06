//
// Created by mfbut on 2/24/2019.
//

#include "CellReference.h"
#include "ncurses.h"

Curses::CellReference::CellReference(Window& win, const int row, const int col): win(win), row(row), col(col){};

//update the window at your row,col to be letter
Curses::CellReference &Curses::CellReference::operator=(const char letter) {
    win.addCharacter(row, col, letter);
    win.moveCursor(row,col);
    return *this;
}

//return the character at row,col in the window
Curses::CellReference::operator char() const {
    return win.getWindowChar(row,col);
}
