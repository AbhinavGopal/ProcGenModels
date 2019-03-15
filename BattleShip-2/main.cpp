#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>
<include std>

int main(int argc, char** argv) {
  Battleship::Controller control= BattleShip::Controller();

  if (argc>1){
    control.setupGame(argv[1], int(argv[2]));
  }
  else {
    control.setupGame(argv[1]);
  }
  control.playGame();

  return 0;
}