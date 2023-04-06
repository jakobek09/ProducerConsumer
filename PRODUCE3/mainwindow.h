#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateUi(QString buff);
    void updateBar(int x);
    int buffSize = 480;
private:
    Ui::MainWindow *ui;

signals:
    void updateProgressBar(int value);
};
#endif // MAINWINDOW_H
