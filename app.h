#ifndef MINESWEEPER_APP_H
#define MINESWEEPER_APP_H

#include <iostream>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QButtonGroup>

#include <QPushButton>

#include "minesweeper.h"

class App : public QMainWindow {
    Q_OBJECT
private:
    Minesweeper* minesweeper;

    QHBoxLayout* hlayout;
    QButtonGroup* bgrp;

public:
    App(QWidget* parent = 0);
    virtual ~App();
    void print();

    void setupUI();
};


#endif //MINESWEEPER_APP_H
