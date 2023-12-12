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
    explicit SelectedPicItemWidget(const QString &imgPath, QWidget *parent = nullptr);
    ~SelectedPicItemWidget();

private:
    Ui::SelectedPicItemWidget *ui;
    QString imgPath;

private:
    void initView();
};

#endif // SELECTEDPICITEMWIDGET_H
