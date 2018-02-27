#include "app.h"

int square(int x){
    return x*x;
}

App::App(QWidget *parent): QMainWindow(parent) {
    this->hlayout = new QHBoxLayout(this);
    this->bgrp = new QButtonGroup(this);

    this->minesweeper = new Minesweeper(9);

    setupUI();
}

App::~App() {
    delete this->minesweeper;
}

void App::print() {
    this->minesweeper->printField();
}

void App::setupUI(){
    //add Buttons
    int bs = square(minesweeper->getBoardSize());
    for(int i = 0; i < bs; i++){
        QPushButton* btn = new QPushButton;
        hlayout->addWidget(btn);
        //btn->show();
        bgrp->addButton(btn);
    }

    this->setLayout(hlayout);
}

