//
// Created by mfbut on 3/10/2019.
//

#include <algorithm>
#include "ShipPlacement.h"

ShipPlacement::ShipPlacement() {
    rowStart = 0;
    rowEnd = 0;
    colStart = 0;
    colEnd = 0;
}

ShipPlacement::ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd) {
    this->rowStart = rowStart;
    this->colStart = colStart;
    this->rowEnd = rowEnd;
    this->colEnd = colEnd;
}

void ShipPlacement::normalize() {
    if (rowStart > rowEnd) {
        int tmp = rowStart;
        rowStart = rowEnd;
        rowEnd = tmp;
    }
    if (colStart > colEnd) {
        int tmp = colStart;
        colStart = colEnd;
        colEnd = tmp;
    }
}