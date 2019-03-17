//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
#include<stdio.h>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

BattleShip::Controller::Controller(): hasBeenSetUp(false) {
    model=Model();
    view = std::make_unique<BattleShip::StandardView>();
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile, int seed) {
    BattleShip::PlayerConfiguration config = view->getPlayerConfiguration();
    model.loadGameConfigurationFromFile(GameConfigurationFile);

    if (config.numHumanPlayers > 0) {
        for (int i = 0; i < config.numHumanPlayers; i++) {
            view->getPlayerName(i+1);
            model.addPlayer<HumanPlayer>(*view);
        }
    }
    if (config.numAiPlayers > 0) {
        for (int i = 0; i < config.numAiPlayers; i++) {
            int choice = view->getAiChoice();
            switch (choice) {
                case 1:
                    model.addPlayer<CheatingAI>(*view);
                    break;
                case 2:
                    model.addPlayer<RandomAI>(*view);
                    break;
                case 3:
                    model.addPlayer<HuntDestroyAI>(*view);
                    break;
                default:
                    exit(2);
            }
        }
        AiPlayer::seed_random_number_generator(seed);
    }
    model.getAttackingPlayer().setOpponent(model.getDefendingPlayer());
    model.getDefendingPlayer().setOpponent(model.getAttackingPlayer());
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile) {
    BattleShip::PlayerConfiguration config = view->getPlayerConfiguration();
    model.loadGameConfigurationFromFile(GameConfigurationFile);

    if (config.numHumanPlayers > 0) {
        for (int i = 0; i < config.numHumanPlayers; i++) {
            //std::string name= view->getPlayerName(i+1);
            model.addPlayer<HumanPlayer>(*view);
        }
    }
    if (config.numAiPlayers > 0) {
        for (int i = 0; i < config.numAiPlayers; i++) {
            int choice = view->getAiChoice();
            switch (choice) {
                case 1:
                    model.addPlayer<CheatingAI>(*view);
                    break;
                case 2:
                    model.addPlayer<RandomAI>(*view);
                    break;
                case 3:
                    model.addPlayer<HuntDestroyAI>(*view);
                    break;
                default:
                    exit(2);
            }
        }
    }
    model.getAttackingPlayer().setOpponent(model.getDefendingPlayer());
    model.getDefendingPlayer().setOpponent(model.getAttackingPlayer());
}

void BattleShip::Controller::setupGame() {
   hasBeenSetUp=true;
}

void BattleShip::Controller::playGame() {
    while (!model.isGameOver()){
        std::unique_ptr<BattleShip::Move> attack = model.getAttackingPlayer().getMove();
        attack->enact(model, *view);
        model.changeTurn();
    }
    view->showWinner(model.getDefendingPlayer());
}
