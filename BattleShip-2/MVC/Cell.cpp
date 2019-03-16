//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker) :
contents (contents), hiddenMarker (hiddenMarker),  hitMarker (hitMarker), missMarker (missMarker){};

BattleShip::Cell::Cell(char contents) :
        contents (contents), hiddenMarker ('*'),  hitMarker ('X'), missMarker ('O'){};

char BattleShip::Cell::getContents() const {
    return contents;
}

void BattleShip::Cell::setContents(char contents) {
    this->contents = contents;
}

char BattleShip::Cell::getContentsIfHidden() const {
    if (firedAt) {
        if (containsShip()) {
            return hitMarker;
        }
        else {
            return missMarker;
        }
    }
    else {
        return hiddenMarker;
    }
}

char BattleShip::Cell::getContentsIfVisible() const {
    return contents;
}

bool BattleShip::Cell::HasBeenFiredAt() const {
    return firedAt;
}

void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt) {
    firedAt = hasBeenFiredAt;
}

bool BattleShip::Cell::containsShip() const {
    return contents != '*';                 //forward declare
}