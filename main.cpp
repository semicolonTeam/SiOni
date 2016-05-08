#include "winhome.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    winHome w;
    w.show();

    return a.exec();
}
