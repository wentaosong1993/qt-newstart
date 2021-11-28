#include "listview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    listview w;
    w.show();

    return a.exec();
}
