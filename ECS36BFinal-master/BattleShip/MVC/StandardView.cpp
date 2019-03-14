//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"

BattleShip::StandardView::StandardView(): in(std::cin), out(std::cout) {
}

BattleShip::StandardView::StandardView(std::istream &in, std::ostream &out): in(in), out(out){
}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration() {
    std::cout << "What type of game do you want to play?\n1. Human vs Human\n2. Human vs AI\n3. AI vs AI\nYour choice: ";
    int answer;
    std::cin>>answer;
    switch (answer) {
        case (1):
            return PlayerConfiguration(2, 0);
            break;
        case (2):
            return PlayerConfiguration(1, 1);
            break;
        case (3):
            return PlayerConfiguration(0, 2);
            break;
        default:
            return PlayerConfiguration(0,0); //fix if extra credit offered.
    }
}

std::string BattleShip::StandardView::getPlayerName(int i) {
    out <<"Player"<< i << " Please enter your name:";
    std::string name;
    in>>name;
    return name;
}

ShipPlacement BattleShip::StandardView::getShipPlacement(const BattleShip::Player &player, char shipChar, int shipLen) {
    out<< player.getName()<<"do you want to place"<<shipChar<<"horizontally or vertically?\nEnter h for horizontal or v for vertical\nYour choice:";
    char direction;
    int rowStart;
    int colStart;
    in>>direction;
    in>>rowStart;
    in>>colStart;
    int rowEnd;
    int colEnd;
    if (direction=='h'){
        rowEnd=rowStart;
        colEnd=colStart+shipLen;
    }
    else{
        rowEnd=rowStart+shipLen;
        colEnd=colStart;
    }
    return ShipPlacement(rowStart, colStart, rowEnd, colEnd);
}