#ifndef ACCOUNTDETAILWIDGET_H
#define ACCOUNTDETAILWIDGET_H

#include <QWidget>

namespace Ui {
class AccountDetailWidget;
}

class AccountDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AccountDetailWidget(QWidget *parent = nullptr);
    ~AccountDetailWidget();

private:
    Ui::AccountDetailWidget *ui;

private:
    void initView();
};

#endif // ACCOUNTDETAILWIDGET_H
