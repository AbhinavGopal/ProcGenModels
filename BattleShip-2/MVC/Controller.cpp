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
    view->getPlayerConfiguration();



}
