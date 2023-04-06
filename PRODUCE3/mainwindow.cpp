#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::updateProgressBar, this, &MainWindow::updateBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUi(QString buff)
{
    ui->label->setText(buff);
}

void MainWindow::updateBar(int x)
{
    ui->progressBar->setValue(x);
}
