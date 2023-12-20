#include "icontxtqpushbutton.h"

#include <QDebug>
#include <QPainter>

#include "icontxtqlabel.h"

IconTxtQPushButton::IconTxtQPushButton(QWidget *parent)
    : QPushButton{parent}
{
    oriWidth = this->width();
    oriHeight = this->height();
}

void IconTxtQPushButton::setTextColor(QColor color)
{
    if (color.isValid() && color!=textColor){
        textColor = color;
        setStyleSheet("color : "+color.name()+";");
    }
}

QColor IconTxtQPushButton::getTextColor()
{
    return textColor;
}

void IconTxtQPushButton::setTextAndColor(const QString &text, QColor color)
{
    setTextColor(color);
    setText(text);
}

QSize IconTxtQPushButton::minimumSizeHint() const
{
    qDebug() << QWidget::minimumSizeHint();
    return QWidget::minimumSizeHint();
}

QSize IconTxtQPushButton::sizeHint() const
{
    qDebug() << QWidget::sizeHint();
    return QWidget::sizeHint();
}

void IconTxtQPushButton::paintEvent(QPaintEvent *event)
{
    //QElapsedTimer timer;
    //timer.start();
/**
    QPainter painter(this);
    QRectF rect(10.0, 10.0, 100, 90.0);
    painter.setPen(Qt::red);
//    painter.drawRect(rect);
    painter.setPen(QColor(68, 68, 68, 255));

    QFont font("Microsoft YaHei", 20, QFont::Bold, true);
                                             //设置下划线
//    font.setUnderline(true);
    //设置上划线
//    font.setOverline(true);
    //设置字母大小写
    font.setCapitalization(QFont::SmallCaps);
    //设置字符间的间距
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
    //使用字体
//    painter.setFont(font);
//    painter.setPen(Qt::green);
    painter.drawText(rect, Qt::AlignCenter, tr("选择照片"));

//    QFont newFont = font();
//    float fontSize = IconTxtQLabel::getWidgetMaximumFontSize(this, this->text());
//    newFont.setPointSizeF(fontSize);
//    setFont(newFont);
    */
    Q_UNUSED(event)

    if(this->text().isEmpty())
        return;

    qDebug() << oriWidth;
    float j = oriWidth * 1.0 / this->width() - 1;

    QRectF rectangle(0, 0, this->width(), this->height());
    QRectF boundingRect;
    QTextOption o;
    o.setWrapMode(QTextOption::WrapAnywhere);
    o.setAlignment(Qt::AlignVCenter);

    QPainter painter(this);
    QFont font = painter.font();
    font.setFamily("Microsoft YaHei"); //字体

    for(int i = MIN_FONT_SIZE; i < MAX_FONT_SIZE; i++)
    {
        font.setPixelSize(i);
        painter.setFont(font);
        boundingRect = painter.boundingRect(rectangle, this->text(), o);
        if(!rectangle.contains(boundingRect))
        {
            font.setPixelSize((i - 1) == 0 ? MIN_FONT_SIZE : (i - 1));
            painter.setFont(font);
            break;
        }
    }

//    painter.drawText(rectangle, this->text(), o);

    oriWidth = this->width();
    oriHeight = this->height();

    QPushButton::paintEvent(event);

}
