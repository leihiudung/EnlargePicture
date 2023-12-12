#ifndef ENLARGEWIDGET_H
#define ENLARGEWIDGET_H

#include <QWidget>

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
    void initItem();
    void initItem(const QString &str, const QString &picmap);


};

#endif // ENLARGEWIDGET_H
