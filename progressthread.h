#ifndef PROGRESSTHREAD_H
#define PROGRESSTHREAD_H

#include <QObject>

class ProgressThread : public QObject
{
    Q_OBJECT
public:
    explicit ProgressThread(QObject *parent = nullptr);

protected:
    void run();

signals:

};

#endif // PROGRESSTHREAD_H
