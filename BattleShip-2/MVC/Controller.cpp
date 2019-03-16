//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
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
    std::unique_ptr<StandardView> view = std::make_unique<BattleShip::StandardView>();
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile, int seed) {
    BattleShip::PlayerConfiguration config = view->getPlayerConfiguration();
    model.loadGameConfigurationFromFile(GameConfigurationFile);

    if (config.numHumanPlayers > 0) {
        for (int i = 0; i < config.numHumanPlayers; i++) {
            view->getPlayerName(i+1);
            model.addPlayer<HumanPlayer>(*view);
            //for each ship getShipPlacement, then checkShipPlacement

        }
    }
    else if (config.numAiPlayers > 0) {
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

    BattleShip::Model model= BattleShip::Model();

}

void BattleShip::Controller::setupGame() {
   BattleShip::Model model= BattleShip::Model();
   hasBeenSetUp=true;
}

void BattleShip::Controller::playGame() {
    while (!model.isGameOver()){

    }
}
