#ifndef SELECTEDPICITEMWIDGET_H
#define SELECTEDPICITEMWIDGET_H

#include <QWidget>
#include <QLabel>

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
    void confirmCloseSelectedPicItem();

public slots:
    void enlargeFinishSlot();
    void confirmActionSlot();

private:
    Ui::SelectedPicItemWidget *ui;
    QLabel *maskLabel;
    QString imgPath;
    float m_fScale;

private:
    void initView();
    void addLayerMask(bool flag);

};

#endif // SELECTEDPICITEMWIDGET_H
