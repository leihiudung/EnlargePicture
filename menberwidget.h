#ifndef MENBERWIDGET_H
#define MENBERWIDGET_H

#include <QWidget>
class QLabel;
class QPaintEvent;

namespace Ui {
class MenberWidget;
}

class MenberWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenberWidget(QWidget *parent = nullptr);
    ~MenberWidget();
    void paintEvent(QPaintEvent* event);

private:
    Ui::MenberWidget *ui;
    QLabel *recomLabl;

private:
    void initView();
};

#endif // MENBERWIDGET_H
