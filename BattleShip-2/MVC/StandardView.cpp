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
    std::cout << "What type of game do you want to play?\n1. Human vs Human\n2. Human vs AI\n3. AI vs AI\nYour choice:\n";
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
    out <<"Player "<< i << " Please enter your name:\n";
    std::string name;
    in>>name;

    return name;
}

ShipPlacement BattleShip::StandardView::getShipPlacement(const BattleShip::Player &player, char shipChar, int shipLen) {
    auto vec = player.getBoard().getVisibleVersion();
    out<<player.getName()<<"'s Board\n";
    for (std::string s : vec) {
        out<<s<<std::endl;
    }
    out<< player.getName()<<", do you want to place "<<shipChar<<" horizontally or vertically?\nEnter h for horizontal or v for vertical\nYour choice:\n";
    char direction;
    int rowStart;
    int colStart;
    in>>direction;
    out << player.getName() << ", enter the row and column you want to place "<<shipChar<< " which is "<< shipLen<<" long, at with a space in between row and col:\n";
    in>>rowStart;
    in>>colStart;
    int rowEnd;
    int colEnd;
    if (direction=='h'){
        rowEnd=rowStart;
        colEnd=colStart+shipLen - 1;
    }
    else{
        rowEnd=rowStart+shipLen - 1;
        colEnd=colStart;
    }
    return ShipPlacement(rowStart, colStart, rowEnd, colEnd);
}

void BattleShip::StandardView::updateShipPlacementView(const BattleShip::Player& player) {
    out<<player.getName()<<" 's Board\n";
    printBoardAsVisible(player.getBoard());
    out<<"\n";
}

std::pair<int, int> BattleShip::StandardView::getFiringCoordinate(const BattleShip::Player& attacker) {
    std::pair<int, int> coords;
    out << attacker.getName() << ", where would you like to fire?\n";
    in >> coords.first >> coords.second;
    return coords;
}

void BattleShip::StandardView::showWinner(const Player& winner) {
    out << winner.getName() << " won the game!";
}

void BattleShip::StandardView::showResultOfAttack(const BattleShip::Player &attacker, const BattleShip::AttackResult &attackResult) {
    if (attackResult.hit) {
        out << attacker.getName() << " hit " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar << "!" << std::endl;
        if (attackResult.destroyed) {
            out << attacker.getName() << " destroyed " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar << "\n" << std::endl;
        }
        else{
            out<<'\n';
        }
    }
    else {
        out << "Missed.\n" << std::endl;
    }
}

void BattleShip::StandardView::printBoard(const std::vector<std::string>& board)  {
    for (std::string st : board) {
        for (char ch : st) {
            out << ch;
        }
        out << std::endl;
    }
}

void BattleShip::StandardView::printBoardAsObscured(const BattleShip::Board &board) {
    std::vector<std::string> vec = board.getHiddenVersion();
    printBoard(vec);
}

void BattleShip::StandardView::printBoardAsVisible(const BattleShip::Board &board) {
    std::vector<std::string> vec = board.getVisibleVersion();
    printBoard(vec);
}

void BattleShip::StandardView::showPlayersBoard(const BattleShip::Player &player) {
    out<<player.getName()<<"'s Firing Board\n";
    printBoardAsObscured(player.getOpponent().getBoard());
    out<<"\n";
}

void BattleShip::StandardView::showPlacementBoard(const BattleShip::Player &player) {
    out<<player.getName()<<"'s Placement Board\n";
    printBoardAsVisible(player.getBoard());
}

int BattleShip::StandardView::getAiChoice() {
    out << "What AI do you want?\n1. Cheating AI\n2. Random AI\n3. Hunt Destroy AI\nYour choice:\n";
    int choice;
    in >> choice;
    return choice;
}

void BattleShip::StandardView::clearInput() {
    char ch=' ';
    while (ch==' '){
        in>>ch;
    }

}
