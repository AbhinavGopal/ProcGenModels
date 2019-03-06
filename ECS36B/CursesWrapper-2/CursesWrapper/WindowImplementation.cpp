//
// Created by mfbut on 2/24/2019.
//
#include "WindowImplementation.h"
#include "ncurses.h"
#include <cstdio>
#include <iostream>
/*
 * I've already added the cut to initialize curses if it hasn't been called
 * and to create the window. You may still need to do more initialization if
 * you have other members
 */
Curses::WindowImplementation::WindowImplementation(int numRows, int numCols, int startRow, int startCol) :
cursesWindow(nullptr, delwin), adv(false) {
    if (!stdscr) {
        initscr();
    }
    cursesWindow = std::unique_ptr<WINDOW, decltype(delwin)*>(newwin(numRows, numCols, startRow, startCol), delwin);
}

Curses::WindowImplementation::WindowImplementation(int numRows, int numCols) : WindowImplementation(numRows,
                                                                                                    numCols,
                                                                                                    0,
                                                                                                    0) {
    
}

//the unique pointer will automatically delete itself
//but if you dynamically allocate any more space for this
//problem make sure to free it here.
Curses::WindowImplementation::~WindowImplementation() {
    
}

char Curses::WindowImplementation::getWindowChar(int row, int col) {
    return mvwinch(cursesWindow.get(),row,col);
}

char Curses::WindowImplementation::getWindowChar() {
    return winch(cursesWindow.get());
}

char Curses::WindowImplementation::getCharInput(int row, int col) {
    return mvwgetch(cursesWindow.get(), row,col);
}

char Curses::WindowImplementation::getCharInput() {
    return wgetch(cursesWindow.get());
}

std::string Curses::WindowImplementation::getStringInput(int row, int col) {
    char ch = getCharInput(row, col);
    std::string str = "";
    while (ch != '\n') {
        str += ch;
        ch = getCharInput();
    }
    return str;
    
}

std::string Curses::WindowImplementation::getStringInput() {
    return getStringInput(getCurRow(), getCurCol());
}

void Curses::WindowImplementation::addCharacter(int row, int col, char value) {
    mvwaddch(cursesWindow.get(), row, col, value);
    if (!adv){
        if (getCurCol()==getmaxx(cursesWindow.get())-1){
        }
        else if (getCurCol()!=0) {
            wmove(cursesWindow.get(), getCurRow(), getCurCol() - 1);
        }
        else{
            wmove(cursesWindow.get(), getCurRow()-1, getmaxx(cursesWindow.get())-1);
        }
    }
}

void Curses::WindowImplementation::addCharacter(char value) {
    waddch(cursesWindow.get(), value);
    if (!adv){
        if (getCurCol()==getmaxx(cursesWindow.get())-1){
        }
        else if (getCurCol()!=0) {
            wmove(cursesWindow.get(), getCurRow(), getCurCol() - 1);
        }
        else{
            wmove(cursesWindow.get(), getCurRow()-1, getmaxx(cursesWindow.get())-1);
        }
    }
}

void Curses::WindowImplementation::addString(int row, int col, const std::string& str) {
    mvwaddstr(cursesWindow.get(), row, col, str.c_str());
    if (!adv){
        if (getCurCol()==getmaxx(cursesWindow.get())-1){
        }
        else if (getCurCol()!=0) {
            wmove(cursesWindow.get(), getCurRow(), getCurCol() - 1);
        }
        else{
            wmove(cursesWindow.get(), getCurRow()-1, getmaxx(cursesWindow.get())-1);
        }
    }
//    if (!adv){
//        if (getCurCol()==getmaxx(cursesWindow.get())-1){
//        }
//        else if (getCurCol()!=0) {
//            wmove(cursesWindow.get(), getCurRow(), getCurCol() - 1);
//        }
//        else{
//            wmove(cursesWindow.get(), getCurRow()-1, getmaxx(cursesWindow.get())-1);
//        }
//    }
}


void Curses::WindowImplementation::addString(const std::string& str) {
    waddstr(cursesWindow.get(), str.c_str());
    if (!adv){
        if (getCurCol()==getmaxx(cursesWindow.get())-1){
        }
        else if (getCurCol()!=0) {
            wmove(cursesWindow.get(), getCurRow(), getCurCol() - 1);
        }
        else{
            wmove(cursesWindow.get(), getCurRow()-1, getmaxx(cursesWindow.get())-1);
        }
    }
}

int Curses::WindowImplementation::getRowStart() const {
    return getbegy(cursesWindow.get());
}

int Curses::WindowImplementation::getColStart() const {
    return getbegx(cursesWindow.get()) ;
}

int Curses::WindowImplementation::getNumRows() const {
    return getmaxy(cursesWindow.get());
}

int Curses::WindowImplementation::getNumCols() const {
    return getmaxx(cursesWindow.get());
}

int Curses::WindowImplementation::getCurRow() const {
    return getcury(cursesWindow.get());
}

int Curses::WindowImplementation::getCurCol() const {
    return getcurx(cursesWindow.get());
}

void Curses::WindowImplementation::moveCursor(int row, int col) {
    wmove(cursesWindow.get(), row, col);
}

void Curses::WindowImplementation::moveCursorLeft(int amount) {
    if (getCurCol()-amount>0){
        wmove(cursesWindow.get(), getCurRow(), getCurCol()-amount);}
    else{
        wmove(cursesWindow.get(), getCurRow(), 0);
    }
}

void Curses::WindowImplementation::moveCursorRight(int amount) {
    if (getCurCol()+amount<=(getNumCols()-1)){
        wmove(cursesWindow.get(), getCurRow(), getCurCol()+amount);}
    else{
        wmove(cursesWindow.get(), getCurRow(), getNumCols()-1);
    }
}

void Curses::WindowImplementation::moveCursorUp(int amount) {
    amount=amount%(getNumRows());
    if ((getCurRow()-amount)>=0){
        wmove(cursesWindow.get(), getCurRow()-amount, getCurCol());}
    else{
        wmove(cursesWindow.get(),0,getCurCol());
    }
}

void Curses::WindowImplementation::moveCursorDown(int amount) {
    amount=amount%(getNumRows());
    if ((getCurRow()+amount)<getNumRows()-1){
        wmove(cursesWindow.get(), getCurRow()+amount, getCurCol());}
    else{
        wmove(cursesWindow.get(), getNumRows()-1, getCurCol());
    }
}

void Curses::WindowImplementation::setAdvanceCursorOn() {
    adv=true;
}

void Curses::WindowImplementation::setAdvanceCursorOff() {
    adv=false;
}

Curses::RowReference Curses::WindowImplementation::at(int row) {
    return RowReference(*this,row);
}

Curses::RowReference Curses::WindowImplementation::operator[](int row) {
    return RowReference(*this,row);
}

void Curses::WindowImplementation::refresh() {
    wrefresh(cursesWindow.get());
}

void Curses::WindowImplementation::log(std::ostream& out) {
    int row=getCurRow();
    int col=getCurCol();
    for (int i = 0; i < getNumRows(); i++) {
        for (int j = 0; j < getNumCols(); j++) {
            out << getWindowChar(i, j);
        }
        out << std::endl;
    }
    wmove(cursesWindow.get(),row,col);
}


