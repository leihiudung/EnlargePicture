#ifndef RETRIEVEPASSWORDWIDGET_H
#define RETRIEVEPASSWORDWIDGET_H

#include <QWidget>

namespace Ui {
class RetrievePasswordWidget;
}

class RetrievePasswordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RetrievePasswordWidget(QWidget *parent = nullptr);
    ~RetrievePasswordWidget();

private:
    Ui::RetrievePasswordWidget *ui;

private:
    void initView();
};

#endif // RETRIEVEPASSWORDWIDGET_H
