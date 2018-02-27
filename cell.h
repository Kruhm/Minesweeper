#ifndef MINESWEEPER_CELL_H
#define MINESWEEPER_CELL_H


class Cell {
private:
    bool mine;
    bool flag;
    bool visibility;
    int neighbours;
public:
    Cell();
    bool isMine();
    bool isFlagged();
    bool isVisible();
    void addNeighbour();
    void setMine(bool mine);
    void setVisibility(bool visibility);
    int getNeighbours();
};


#endif //MINESWEEPER_CELL_H
