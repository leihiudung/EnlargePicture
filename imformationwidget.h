#ifndef IMFORMATIONWIDGET_H
#define IMFORMATIONWIDGET_H

#include <QWidget>

namespace Ui {
class ImformationWidget;
}

class ImformationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImformationWidget(QWidget *parent = nullptr);
    ~ImformationWidget();
    void imformationMessage(const QString &title, const QString &content);

private:
    Ui::ImformationWidget *ui;
    QString titleStr;
    QString contentStr;


private:
    void initView();

signals:
    void confirmAction();

};

#endif // IMFORMATIONWIDGET_H
