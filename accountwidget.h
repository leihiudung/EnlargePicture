#ifndef ACCOUNTWIDGET_H
#define ACCOUNTWIDGET_H

#include <QWidget>

namespace Ui {
class AccountWidget;
}

class AccountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AccountWidget(QWidget *parent = nullptr);
    ~AccountWidget();
signals:
    void loggedSignal();
private:
    Ui::AccountWidget *ui;
    bool emailEditValuable = false;
    bool passwordEditValuable = false;

private:
    void initView();
};

#endif // ACCOUNTWIDGET_H
