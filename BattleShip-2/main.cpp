#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
  BattleShip::Controller control= BattleShip::Controller();

  if (argc>1){
    control.setupGame(argv[1], atoi(argv[2]));
  }
  else {
    control.setupGame(argv[1]);
  }
  control.playGame();

  return 0;
}