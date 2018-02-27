#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H

#include <random>
#include <ctime>
#include <iostream>
#include <vector>
#include "cell.h"

using namespace std;
class Minesweeper {
private:
    vector<Cell*>* board;
    int boardSize;
    int mineCount;
    int flagCount;

public:
    Minesweeper(int boardSize);
    void newGame();
    void placeMineCellCount();
    void plantMines();
    void printField();
    void newBoard();
    int getBoardSize();
};


#endif //MINESWEEPER_MINESWEEPER_H
