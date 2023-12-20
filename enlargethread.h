#ifndef ENLARGETHREAD_H
#define ENLARGETHREAD_H

#include <QThread>
#include <QMap>

class EnlargeThread : public QThread
{
    Q_OBJECT
public:
    explicit EnlargeThread(QObject *parent = nullptr);

public:
    QString EXE_CMD;
    QMap<QString, QString> imageInfo;

protected:
    void run();
    void saveImproveHistory();

signals:
    void finishEnlargeSignal(bool flag);
};

#endif // ENLARGETHREAD_H
