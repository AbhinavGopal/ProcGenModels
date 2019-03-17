//
// Created by mfbut on 3/10/2019.
//

#include "Attack.h"


BattleShip::Attack::Attack(BattleShip::Player &attacker, int row, int col): BattleShip::Move(attacker), row(row), col(col) {
}

void BattleShip::Attack::enact(BattleShip::Model &model, BattleShip::View &view) {
    AttackResult result = moveMaker.fireAt(row, col);
    view.showPlayersBoard(moveMaker);
    view.showPlacementBoard(moveMaker);
    view.showResultOfAttack(moveMaker, result);
}

const int BattleShip::Attack::getRow() const {
    return row;
}

const int BattleShip::Attack::getCol() const {
    return col;
}

bool BattleShip::Attack::isValid() const {
    return false;
}
