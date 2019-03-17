//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"
#include "HumanPlayer.h"


BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : Player(
        gameAttributes, view) {

}

std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove() {
    view.showPlayersBoard(*this);
    view.showPlacementBoard(*this);
    std::pair<int,int> pair= view.getFiringCoordinate(*this);
    BattleShip::Attack move= BattleShip::Attack(*this, pair.first, pair.second);
    return std::make_unique<BattleShip::Attack>(move);
}

void BattleShip::HumanPlayer::placeShips() {
    auto itr = shipHealths.begin();
    while(itr != shipHealths.end()) {
        ShipPlacement placement = view.getShipPlacement(*this, itr->first, itr->second);
        if (getBoard().canPlaceShipAt(placement)) {
            getBoard().AddShip(itr->first, placement);
            view.updateShipPlacementView(*this);
            view.showPlacementBoard(*this);
            itr++;
        }
    }
}

void BattleShip::HumanPlayer::initializeName() {
    std::string name = getName();
    setName(name);
}


