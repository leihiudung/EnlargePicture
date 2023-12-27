#include "timagelabel.h"

#include <QPainter>

#include <QPixmap>
#include <QColor>

TImageLabel::TImageLabel(QWidget *parent)
    : QLabel{parent}
{
    QPixmap pixmap(":/res/img/cat_dog");
    setPixmap(pixmap);
}

void TImageLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event); // 调用基类的绘图事件处理

    QPainter painter(this);
    QPen pen = painter.pen();
    QBrush brush = painter.brush();
    QFont font = painter.font();

    if (paintMask) {
        painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

        // 绘制深色半透明图层
        QColor overlayColor(0, 0, 0, 130); // 深色，带有一些透明度
        painter.fillRect(rect(), overlayColor); // 绘制深色半透明矩形覆盖层

        QString text = "放大中";
        QColor textColor(255, 255, 255); // 白色文字
//        QFont font("Mircrosoft YaHei", 13, QFont::Bold); // 自定义字体和大小
        painter.setFont(QFont("Microsoft YaHei", 13, QFont::Bold));
        painter.setPen(textColor);
        painter.drawText(rect(), Qt::AlignCenter, text); // 在中心绘制文字


    } else {

    }

    painter.setFont(font);
    painter.setPen(pen);
    painter.setBrush(brush);

}
