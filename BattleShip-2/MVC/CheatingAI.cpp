//
// Created by mfbut on 3/11/2019.
//
#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"

BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view): AiPlayer(gameAttributes, view) {
}

std::unique_ptr<BattleShip::Move> BattleShip::CheatingAI::getMove() {
    for (int j=0; j<getBoard().getNumCols();j++){
        for (int i=0; i<getBoard().getNumRows();i++){
            if (opponent->getBoard().at(i,j).getContents()!='*'&& !(opponent->getBoard().at(i,j).HasBeenFiredAt())){
                std::unique_ptr<BattleShip::Attack> ptr= std::make_unique<BattleShip::Attack>(*this, i, j);
                return ptr;
            }

        }

    }
    exit(4);
}
