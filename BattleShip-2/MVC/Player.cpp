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


