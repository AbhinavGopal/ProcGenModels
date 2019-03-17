//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"

BattleShip::Board::Board(int numRows, int numCols, char blankChar) : blankChar (blankChar) {
    boardState = std::vector<std::vector<Cell>> (numRows);
    int i=0;
    int j;
    while(i < numRows) {
        j=0;
        while (j < numCols) {
            boardState[i].push_back(Cell(blankChar));
            j++;
        }
        i++;
    }

}

BattleShip::Board::Board(int numRows, int numCols) : blankChar ('*') {
    boardState = std::vector<std::vector<Cell>> (numRows);
    int l=boardState.size();
    l+=1;
    int i=0;
    int j;
    while (i < numRows) {
        j=0;
        while(j < numCols) {
            boardState[i].push_back(Cell(blankChar));
            j++;
        }
        i++;
    }


}

int BattleShip::Board::getNumRows() const {
    return boardState.size();
}

int BattleShip::Board::getNumCols() const {
    return boardState.front().size();
}

std::vector<std::string> BattleShip::Board::getHiddenVersion() const{
    std::string str = "";
    std::vector<std::string> vec (getNumRows() + 1);
    str += "  ";
    for (int i = 0; i < getNumCols(); i++) {
        str += std::to_string(i);
        str += " ";
    }
    vec[0] = str;
    str = "";
    for (int i = 0; i < getNumRows(); i++) {
        str += std::to_string(i);
        str += " ";
        for (int j = 0; j < getNumCols(); j++) {
            str += boardState[i][j].getContentsIfHidden();
            str += " ";
        }
        vec[i + 1] = str;
        str = "";
    }
    return vec;
}

std::vector<std::string> BattleShip::Board::getVisibleVersion() const{
    std::string str = "";
    std::vector<std::string> vec (getNumRows() + 1);
    str += "  ";
    for (int i = 0; i < getNumCols(); i++) {
        str += std::to_string(i);
        str += " ";
    }
    vec[0] = str;
    str = "";
    for (int i = 0; i < getNumRows(); i++) {
        str += std::to_string(i);
        str += " ";
        for (int j = 0; j < getNumCols(); j++) {
            str += boardState[i][j].getContentsIfVisible();
            str += " ";
        }
        vec[i + 1] = str;
        str = "";
    }
    return vec;
}

bool BattleShip::Board::inBounds(int row, int col) const {
    bool a = !(row < 0 || col < 0 || row >= getNumRows() || col >= getNumCols());
    return a;
}

BattleShip::Cell& BattleShip::Board::at(int i, int j) {
    return boardState[i][j];
}

const BattleShip::Cell& BattleShip::Board::at(int i, int j) const {
    return boardState[i][j];
}

bool BattleShip::Board::inBounds(const ShipPlacement& shipPlacement) const {
    for (int i = shipPlacement.rowStart; i <= shipPlacement.rowEnd; i++) {
        for (int j = shipPlacement.colStart; j <= shipPlacement.colEnd; j++) {
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