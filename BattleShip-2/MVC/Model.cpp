//
// Created by mfbut on 3/9/2019.
//

#include <fstream>
#include <algorithm>
#include "Model.h"

BattleShip::Model::Model() {
    playerTurn = 0;
    forcedGameOver = false;
}

BattleShip::Player& BattleShip::Model::getAttackingPlayer() {
    return *(players[playerTurn]);
}

const BattleShip::Player& BattleShip::Model::getAttackingPlayer() const {
    return *(players[playerTurn]);
}

BattleShip::Player& BattleShip::Model::getDefendingPlayer() {
    return *(players[(playerTurn + 1) % 2]);
}

const BattleShip::Player& BattleShip::Model::getDefendingPlayer() const {
    return *(players[(playerTurn + 1) % 2]);
}

void BattleShip::Model::loadGameConfigurationFromFile(const std::string &gameConfigurationFile) {
    std::ifstream in;
    in.open(gameConfigurationFile);
    this->gameAttributes = GameAttributes(in);
    in.close();
}

bool BattleShip::Model::isGameOver() const {
    for (int i = 0; i < 2; i++) {
        BattleShip::Player& player = *(players[i]);
        if(player.allShipsSunk()) {
            return true;
        }
    }
    return false;
}

void BattleShip::Model::changeTurn() {
    playerTurn = (playerTurn + 1) % 2;
}

void BattleShip::Model::endGame() {
    forcedGameOver = isGameOver();
}

BattleShip::Player& BattleShip::Model::getWinner() {
    if (players[0]->allShipsSunk()) {
        return *(players[1]);
    }
    else {
        return *(players[0]);
    }
}

void BattleShip::Model::SetOpponents() {
    players[0]->setOpponent(*(players[1]));
    players[1]->setOpponent(*(players[0]));
}

std::unique_ptr<BattleShip::Move> BattleShip::Model::getNextMove() {
    std::unique_ptr<BattleShip::Move> move = std::make_unique<BattleShip::Move>(getAttackingPlayer());
    return move;
}

