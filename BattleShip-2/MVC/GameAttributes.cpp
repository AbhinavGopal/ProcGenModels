//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include "Utility.h"
#include "GameAttributes.h"

BattleShip::GameAttributes::GameAttributes() {
    shipAttributes=std::map<char, int>();
    numRows = 10;
    numCols = 10;
    shipAttributes.insert(std::pair<char,int>('C', 5));
    shipAttributes.insert(std::pair<char,int>('B', 4));
    shipAttributes.insert(std::pair<char,int>('D', 3));
    shipAttributes.insert(std::pair<char,int>('S', 3));
    shipAttributes.insert(std::pair<char,int>('P', 2));
}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols) {
    shipAttributes=std::map<char, int>();
    this->numRows = numRows;
    this->numCols = numCols;
    shipAttributes.insert(std::pair<char,int>('C', 5));
    shipAttributes.insert(std::pair<char,int>('B', 4));
    shipAttributes.insert(std::pair<char,int>('D', 3));
    shipAttributes.insert(std::pair<char,int>('S', 3));
    shipAttributes.insert(std::pair<char,int>('P', 2));
}

BattleShip::GameAttributes::GameAttributes(std::istream& in) {
    shipAttributes=std::map<char, int>();
    in >> this->numRows;
    in >> this->numCols;
    int numShips;
    in>>numShips;
    shipAttributes.insert(std::pair<char,int>('C', 5));
    char ch= ' ';
    int len;
    for (int i=0;i<numShips;i++){
        in>>ch;
        in>>len;
        shipAttributes.insert(std::pair<char,int>(ch,len));
    }
}

int BattleShip::GameAttributes::getNumRows() const {
    return numRows;
}

void BattleShip::GameAttributes::setNumRows(int numRows) {
    this->numRows = numRows;
}

int BattleShip::GameAttributes::getNumCols() const {
    return numCols;
}

void BattleShip::GameAttributes::setNumCols(int numCols) {
    this->numCols = numCols;
}

int BattleShip::GameAttributes::getShipSize(const char ShipChar) const {
    return shipAttributes.at(ShipChar);
}

const std::map<char, int> &BattleShip::GameAttributes::getShipAttributes() const {
    return shipAttributes;
}
