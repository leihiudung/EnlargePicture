#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class widget;
}
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

private:
    Ui::widget *ui;

private:
    void initView();
};

#endif // WIDGET_H
