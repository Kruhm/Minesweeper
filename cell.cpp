#include "cell.h"
Cell::Cell() {
    /*
     * Minesweeper cell wrapper.
     * holds information about the amount of neighbouring mines,
     * if it is a mine or flagged
     * and if it is visible for the player
     */
    this->mine=false;
    this->flag= false;
    this->neighbours=0;
    this->visibility=false;
}

void Cell::addNeighbour() {
    this->neighbours++;
}

bool Cell::isFlagged() {
    return this->flag;
}

bool Cell::isVisible() {
    return this->visibility;
}

bool Cell::isMine() {
    return this->mine;
}

void Cell::setVisibility(bool visibility){
    this->visibility = visibility;
}

void Cell::setMine(bool mine) {
    this->mine = mine;
}

int Cell::getNeighbours() {
    return this->neighbours;
}
