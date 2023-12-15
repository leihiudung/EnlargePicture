#ifndef ENLARGEPARAMSELECTWIDGET_H
#define ENLARGEPARAMSELECTWIDGET_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class EnlargeParamSelectWidget;
}

class EnlargeParamSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EnlargeParamSelectWidget(QWidget *parent = nullptr);
    ~EnlargeParamSelectWidget();

signals:
    void comfirnEnlargeParamSignal(int i, int j, int z);

private:
    Ui::EnlargeParamSelectWidget *ui;
    QButtonGroup *typeGroup;
    QButtonGroup *magnificationGroup;
    QButtonGroup *qualityGroup;

    int typeIndex = 0;
    int magnificationIndex = 2;
    int qualityIndex = 0;

private:
    void initView();

private slots:
    void typeGroupClickedSlot(int);
    void magnificationGroupClickedSlot(int);
    void qualityGroupClickedSlot(int);
};

#endif // ENLARGEPARAMSELECTWIDGET_H
