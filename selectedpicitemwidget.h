#ifndef SELECTEDPICITEMWIDGET_H
#define SELECTEDPICITEMWIDGET_H

#include <QWidget>

namespace Ui {
class SelectedPicItemWidget;
}

class SelectedPicItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectedPicItemWidget(QWidget *parent = nullptr);
    ~SelectedPicItemWidget();

private:
    Ui::SelectedPicItemWidget *ui;

private:
    void initView();
};

#endif // SELECTEDPICITEMWIDGET_H
