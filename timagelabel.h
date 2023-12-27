#ifndef TIMAGELABEL_H
#define TIMAGELABEL_H

#include <QWidget>
#include <QLabel>

class TImageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit TImageLabel(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

public:
    bool paintMask = false;

};

#endif // TIMAGELABEL_H
