#include <QApplication>
#include "app.h"

int main(int argc, char* argv[]) {
    QApplication a(argc,argv);
    App b;
    b.print();
    b.show();
    return a.exec();
}
