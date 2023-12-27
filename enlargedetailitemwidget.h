#ifndef ENLARGEDETAILITEMWIDGET_H
#define ENLARGEDETAILITEMWIDGET_H

#include <QWidget>

namespace Ui {
class EnlargeDetailItemWidget;
}

class EnlargeDetailItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EnlargeDetailItemWidget(QWidget *parent = nullptr);
    ~EnlargeDetailItemWidget();

private:
    Ui::EnlargeDetailItemWidget *ui;

private:
    void initView();
    void addEnlargeMaskView();

};

#endif // ENLARGEDETAILITEMWIDGET_H
