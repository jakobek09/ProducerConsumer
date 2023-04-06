#include "mainwindow.h"
#include "worker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString buffer = "";
    worker *worker1 = new worker("A",300,&w);
    worker *worker2 = new worker("B",200,&w);
    worker *worker3 = new worker("C",100,&w);
    worker *worker4 = new worker(" ",200,&w);

    worker1->start();
    worker2->start();
    worker3->start();
    worker4->start();


    return a.exec();
}
