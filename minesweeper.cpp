#include "minesweeper.h"
#include <QDebug>

Minesweeper::Minesweeper(int boardSize) {
    this->board = new vector<Cell*>;
    this->boardSize = boardSize;
    this->mineCount = boardSize+1;
    this->flagCount = boardSize+1;

    newGame();
}

void Minesweeper::newBoard(){
    this->board->clear();
    for(int i = 0; i < boardSize*boardSize; i++) {
        board->push_back(new Cell());
    }
}

void Minesweeper::newGame() {
    newBoard();
    plantMines();
    placeMineCellCount();
}

void Minesweeper::plantMines() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, boardSize*boardSize);
    for(int i = 0; i <= mineCount; i++){
        Cell* cell = board->at(dist(mt));
        cell->setMine(true);
    }
}

void Minesweeper::placeMineCellCount() {
    /*
     * loops through the board and counts every neighbouring
     * mine cell for every cell.
     * the counted mines are saved in the currents cell neighbour attribut
     */
    for(int y = 0; y < boardSize; y++) {
        for(int x = 0; x < boardSize; x++) {
            Cell* current = board->at(y * boardSize + x);
            if(current->isMine()) continue;
            for(int j = -1; j <= 1; j++){
                for(int i = -1; i <= 1; i++){
                    if(y+j < 0 || y+j >= boardSize || x+i < 0 || x+i >= boardSize || (i == 0 && j == 0)) continue;
                    Cell* neighbour = board->at((y+j) * boardSize + (x+i));
                    if(neighbour->isMine()) current->addNeighbour();
                }
            }
        }
    }
}

int Minesweeper::getBoardSize(){
    return this->boardSize;
}

void Minesweeper::printField() {
    /*
     * prints 2 fields side by side
     * on the left, the mine placements
     * on the right, the counted adjacent mines per cell
     */
    cout << "|-------------------|";
    for(int y = 0; y < boardSize;y++){
        cout << "|";
        for(int x = 0; x < boardSize;x++){
            cout << board->at(y * boardSize + x)->isMine();
        }
        cout << "|";
        for(int x = 0; x < boardSize;x++){
            cout << board->at(y * boardSize + x)->getNeighbours();
        }
        cout<< "|";
        cout << endl;
    }
    std::cout << "|-------------------|" << endl;
}
