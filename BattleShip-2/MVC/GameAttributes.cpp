//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include "Utility.h"
#include "GameAttributes.h"

BattleShip::GameAttributes::GameAttributes() {
    numRows = 10;
    numCols = 10;
    shipAttributes.insert({'C', 5});
    shipAttributes.insert({'B', 4});
    shipAttributes.insert({'D', 3});
    shipAttributes.insert({'S', 3});
    shipAttributes.insert({'P', 2});
}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols) {
    this->numRows = numRows;
    this->numCols = numCols;
    shipAttributes.insert({'C', 5});
    shipAttributes.insert({'B', 4});
    shipAttributes.insert({'D', 3});
    shipAttributes.insert({'S', 3});
    shipAttributes.insert({'P', 2});
}

BattleShip::GameAttributes::GameAttributes(std::istream& in) {
    in >> this->numRows;
    in >> this->numCols;
    shipAttributes.insert({'C', 5});
    shipAttributes.insert({'B', 4});
    shipAttributes.insert({'D', 3});
    shipAttributes.insert({'S', 3});
    shipAttributes.insert({'P', 2});
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
