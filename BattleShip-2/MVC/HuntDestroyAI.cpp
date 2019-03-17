//
// Created by mfbut on 3/11/2019.
//

#include <algorithm>
#include "HuntDestroyAI.h"
#include "Attack.h"
#include "Utility.h"
//#include <set>

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
        : RandomAI(gameAttributes, view) {
}

std::unique_ptr<BattleShip::Move> BattleShip::HuntDestroyAI::getMove() {
    if (priorityFiringQueue.empty()) {
        std::pair<int,int> pair= *(chooseRandom(firingLocations, randomNumberGenerator));
        firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), pair),firingLocations.end());
        if (opponent->getBoard().at(pair.first,pair.second).containsShip()){
            if (pair.second-1>=0 && !opponent->getBoard().at(pair.first,pair.second-1).HasBeenFiredAt()){
                priorityFiringQueue.push_back(std::pair<int,int>(pair.first, pair.second-1));
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), std::pair<int,int>(pair.first, pair.second-1)),firingLocations.end());
            }
            if (pair.first-1>=0 && !opponent->getBoard().at(pair.first-1,pair.second).HasBeenFiredAt()){
                priorityFiringQueue.push_back(std::pair<int,int>(pair.first-1, pair.second));
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), std::pair<int,int>(pair.first-1, pair.second)),firingLocations.end());
            }
            if (pair.second+1<getBoard().getNumCols() && !opponent->getBoard().at(pair.first,pair.second+1).HasBeenFiredAt()){
                priorityFiringQueue.push_back(std::pair<int,int>(pair.first, pair.second+1));
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), std::pair<int,int>(pair.first, pair.second+1)),firingLocations.end());
            }
            if (pair.first+1<getBoard().getNumRows() && !opponent->getBoard().at(pair.first+1,pair.second).HasBeenFiredAt()){
                priorityFiringQueue.push_back(std::pair<int,int>(pair.first+1, pair.second));
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), std::pair<int,int>(pair.first+1, pair.second)),firingLocations.end());
            }
        }
        return std::make_unique<Attack>(*this, pair.first,pair.second);
    }
    else{
        std::pair<int, int> pair= priorityFiringQueue[0];
        priorityFiringQueue.erase(priorityFiringQueue.begin());
        if (opponent->getBoard().at(pair.first,pair.second).containsShip()){
            if (pair.second-1>=0 && !opponent->getBoard().at(pair.first,pair.second-1).HasBeenFiredAt()){
                priorityFiringQueue.push_back(std::pair<int,int>(pair.first, pair.second-1));
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), std::pair<int,int>(pair.first, pair.second-1)),firingLocations.end());
            }
            if (pair.first-1>=0 && !opponent->getBoard().at(pair.first-1,pair.second).HasBeenFiredAt()){
                priorityFiringQueue.push_back(std::pair<int,int>(pair.first-1, pair.second));
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), std::pair<int,int>(pair.first-1, pair.second)),firingLocations.end());
            }
            if (pair.second+1<getBoard().getNumCols() && !opponent->getBoard().at(pair.first,pair.second+1).HasBeenFiredAt()){
                priorityFiringQueue.push_back(std::pair<int,int>(pair.first, pair.second+1));
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), std::pair<int,int>(pair.first, pair.second+1)),firingLocations.end());
            }
            if (pair.first+1<getBoard().getNumRows() && !opponent->getBoard().at(pair.first+1,pair.second).HasBeenFiredAt()){
                priorityFiringQueue.push_back(std::pair<int,int>(pair.first+1, pair.second));
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), std::pair<int,int>(pair.first+1, pair.second)),firingLocations.end());
            }

        }
        return std::make_unique<Attack>(*this, pair.first, pair.second);

    }
}

