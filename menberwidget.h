#ifndef MENBERWIDGET_H
#define MENBERWIDGET_H

#include <QWidget>

namespace Ui {
class MenberWidget;
}

class MenberWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenberWidget(QWidget *parent = nullptr);
    ~MenberWidget();

private:
    Ui::MenberWidget *ui;
};

#endif // MENBERWIDGET_H
