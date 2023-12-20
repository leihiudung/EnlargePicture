#include "enlargethread.h"

#include <QProcess>

EnlargeThread::EnlargeThread(QObject *parent)
    : QThread{parent}
{

}

void EnlargeThread::run()
{
    QProcess process;
    //    bool flag = process.startDetached(EXE_CMD);
    process.execute(EXE_CMD);
    saveImproveHistory();
    emit finishEnlargeSignal(true);
}

void EnlargeThread::saveImproveHistory()
{

}
