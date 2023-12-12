#ifndef ENLARGEWIDGET_H
#define ENLARGEWIDGET_H

#include <QWidget>
class QMouseEvent;

namespace Ui {
class EnlargeWidget;
}

class EnlargeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EnlargeWidget(QWidget *parent = nullptr);
    ~EnlargeWidget();

private:
    Ui::EnlargeWidget *ui;

private:
    void initView();
    void initItem(const QString &imgPath);
    void initItem(const QString &str, const QString &picmap);

public slots:
    void selectPicBtnSlot(bool checked);

};

#endif // ENLARGEWIDGET_H
