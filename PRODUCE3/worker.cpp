#include "worker.h"
#include <QDebug>

QMutex worker::mutex_;
QString worker::buffer;

worker::worker(QString _id, int _time, MainWindow *x, QObject *parent) :
    QThread(parent)
  , id(_id)
  , time_(_time)
  , k(x)
{

}

void worker::run()
{
    if(id == " ")
        consume();
    else
        produce();
}

void worker::produce()
{
    while(!isInterruptionRequested())
    {
        mutex_.lock();
        if(buffer.size() % 80 == 0)
            buffer += '\n';
        buffer += id;
        qDebug() << "SIZE " << buffer.size();
        emit k->updateProgressBar((buffer.size()/(double)k->buffSize)*100); // emit the signal
        k->updateUi(buffer);
        mutex_.unlock();
        if (buffer.size() == 480) {
            thread()->quit();
            break;
        }
        msleep(time_);
    }
}

void worker::consume()
{
    while(!isInterruptionRequested())
    {
        if(buffer.size() >= 3)
        {
            mutex_.lock();
            buffer.remove(buffer.size()-3,3);
            emit k->updateProgressBar((buffer.size()/(double)k->buffSize)*100); // emit the signal
            k->updateUi(buffer);
            mutex_.unlock();
            if (buffer.size() == 480) {
                thread()->quit();
                break;
            }
            msleep(time_);
        }
    }
}
