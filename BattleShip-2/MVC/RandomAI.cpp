//
// Created by mfbut on 3/11/2019.
//

#include "RandomAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : AiPlayer(
        gameAttributes, view) {
    for (int j=0; j<getBoard().getNumCols();j++){
        for (int i=0; i<getBoard().getNumRows();i++){
            firingLocations.push_back(std::pair<int,int>(i,j));
        }
    }
}

std::unique_ptr<BattleShip::Move> BattleShip::RandomAI::getMove() {
    std::pair<int,int> pair= *(chooseRandom(firingLocations, randomNumberGenerator));
    firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), pair),firingLocations.end());
    return std::make_unique<Attack>(*this, pair.first, pair.second);
}
