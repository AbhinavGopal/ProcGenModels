#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

int main(int argc, char** argv) {
  BattleShip::Controller control= BattleShip::Controller();

  if (argc>2){
    control.setupGame(argv[1], atoi(argv[2]));
  }
  else {
    char* ch=argv[1];
    std::cout<<ch;
    control.setupGame(std::string(ch));
  }
  control.playGame();

  return 0;
}