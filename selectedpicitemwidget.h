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
    void paintEvent(QPaintEvent *event);

signals:
    void comfirnEnlargeParamSignal(int i, int j, int z);
    void closeSelectedPicItem();

public slots:
    void enlargeFinishSlot();

private:
    Ui::SelectedPicItemWidget *ui;
    QString imgPath;
    float m_fScale;

private:
    void initView();

};

#endif // SELECTEDPICITEMWIDGET_H
