#include <QApplication>
#include "jpconjmain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    jpconjmain w;
    w.show();
    
    return a.exec();
}
