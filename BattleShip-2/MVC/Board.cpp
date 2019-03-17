//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"

BattleShip::Board::Board(int numRows, int numCols, char blankChar) : blankChar (blankChar) {
    std::vector<std::vector<Cell>> boardState(numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            boardState[i].push_back(Cell(blankChar));
        }
    }
}

BattleShip::Board::Board(int numRows, int numCols) : blankChar ('*') {
    std::vector<std::vector<Cell>> boardState(numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            boardState[i].push_back(Cell(blankChar));
        }
    }
}

int BattleShip::Board::getNumRows() const {
    return boardState.size();
}

int BattleShip::Board::getNumCols() const {
    return boardState[0].size();
}

std::vector<std::string> BattleShip::Board::getHiddenVersion() const{
    std::string str = "";
    std::vector<std::string> vec;
    for (int i = 0; i < getNumRows()-1; i++) {
        for (int j = 0; j < getNumCols()-1; j++) {
            str += boardState[i][j].getContentsIfHidden();
        }
        vec[i] = str;
        str = "";
    }
    return vec;
}

std::vector<std::string> BattleShip::Board::getVisibleVersion() const{
    std::string str = "";
    std::vector<std::string> vec;
    for (int i = 0; i < getNumRows(); i++) {
        for (int j = 0; j < getNumCols(); j++) {
            str += boardState[i][j].getContentsIfVisible();
        }
        vec[i] = str;
        str = "";
    }
    return vec;
}

bool BattleShip::Board::inBounds(int row, int col) const {
    return (row < 0 || col < 0 || row >= getNumRows() || col >= getNumCols());
}

BattleShip::Cell& BattleShip::Board::at(int i, int j) {
    return boardState[i][j];
}

const BattleShip::Cell& BattleShip::Board::at(int i, int j) const {
    return boardState[i][j];
}

bool BattleShip::Board::inBounds(const ShipPlacement& shipPlacement) const {
    for (int i = shipPlacement.rowStart; i <= shipPlacement.rowEnd; i++) {
        for (int j = shipPlacement.colStart; j <= shipPlacement.colEnd; i++) {
            if (!inBounds(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool BattleShip::Board::between(int value, int low, int high) const {
    if (value >= low && value <= high) {
        return true;
    }
    return false;
}

bool BattleShip::Board::spacesAreEmpty(const ShipPlacement& shipPlacement) const {
    for (int i = shipPlacement.rowStart; i < shipPlacement.rowEnd; i++) {
        for (int j = shipPlacement.colStart; j < shipPlacement.colEnd; j++) {
            if (boardState[i][j].getContentsIfVisible() != blankChar) {
                return false;
            }
        }
    }
    return true;
}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement& shipPlacement) const {
    return inBounds(shipPlacement);
}

void BattleShip::Board::AddShip(char shipChar, const ShipPlacement& shipPlacement) {
    for (int i = shipPlacement.rowStart; i <= shipPlacement.rowEnd; i++) {
        for (int j = shipPlacement.colStart; j <= shipPlacement.colEnd; j++) {
            boardState[i][j].setContents(shipChar);
        }
    }
}