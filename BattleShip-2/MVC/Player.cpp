//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"

int BattleShip::Player::num_instances = 0;

BattleShip::Player::Player(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view): id(num_instances-1), view(view),  board(gameAttributes.getNumRows(), gameAttributes.getNumCols()){
    num_instances+=1;
    }

const std::string &BattleShip::Player::getName() const {
    return name;
}

void BattleShip::Player::setName(const std::string &name){
    this->name=name;
}

const BattleShip::Board &BattleShip::Player::getBoard() const {
    return board;
}

BattleShip::Board &BattleShip::Player::getBoard() {
    return board;
}

const int BattleShip::Player::getId() const {
    return id;
}

bool BattleShip::Player::operator==(const BattleShip::Player &rhs) const {
    if (name==rhs.name && id==rhs.id && shipHealths==rhs.shipHealths){
        if (opponent==rhs.opponent){
            if (board.getHiddenVersion()==rhs.board.getHiddenVersion() && board.getVisibleVersion()==rhs.board.getVisibleVersion()){
                return true;
            }
        }
    }
    return false;
}

bool BattleShip::Player::operator!=(const BattleShip::Player &rhs) const {
    return !((*this) == rhs);
}


bool BattleShip::Player::allShipsSunk() const {
    for (std::pair<char,int> ship: shipHealths) {
        if (ship.second != 0) {
            return false;
        }
    }

    return true;
}

BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col) {
    if (opponent->board.at(row,col).containsShip()){
        if (opponent->shipHealths[opponent->board.at(row,col).getContents()]==1){
            return AttackResult(true, true, opponent->board.at(row,col).getContents());
        }
        else {
            return AttackResult(true, false, opponent->board.at(row, col).getContents());
        }
    }
    return AttackResult(false, false, opponent->board.at(row,col).getContents());
}

BattleShip::Player &BattleShip::Player::getOpponent() {
    return *opponent;
}

const BattleShip::Player &BattleShip::Player::getOpponent() const {
    return *opponent;
}

void BattleShip::Player::setOpponent(BattleShip::Player &opponent) {
    this->opponent=&(opponent);
}

bool BattleShip::Player::hit(char shipChar) {

}
