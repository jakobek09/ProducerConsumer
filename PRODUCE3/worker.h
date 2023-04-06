#ifndef WORKER_H
#define WORKER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMutex>
#include <QThread>
#include "mainwindow.h"


class worker : public QThread
{
public:
    explicit worker(QString _id, int _time, MainWindow *x, QObject *parent = 0);
    void produce();
    void consume();
    void run() Q_DECL_OVERRIDE;

private:
    QString id;
    int time_;
    static QString buffer;
    static QMutex mutex_;
    MainWindow *k;
    bool stopThread = false;

};

#endif // WORKER_H
