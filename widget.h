#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
class QListWidgetItem;

QT_BEGIN_NAMESPACE
namespace Ui {
class widget;
}
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

private:
    Ui::widget *ui;

private:
    void initView();
    void initItem(const QString &str, const QString &picmap);
    void initItemWidget();
    void itemClicked(QListWidgetItem *item);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置
};

#endif // WIDGET_H
