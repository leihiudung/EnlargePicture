#ifndef RESETPASSWORDWIDGET_H
#define RESETPASSWORDWIDGET_H

#include <QWidget>

namespace Ui {
class ResetPasswordWidget;
}

class ResetPasswordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResetPasswordWidget(QWidget *parent = nullptr);
    ~ResetPasswordWidget();

private:
    Ui::ResetPasswordWidget *ui;

private:
    void initView();
};

#endif // RESETPASSWORDWIDGET_H
