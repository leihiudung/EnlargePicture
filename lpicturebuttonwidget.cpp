#include "lpicturebuttonwidget.h"
#include <QDebug>
#define FONT_PRECISION (0.5)

LPictureButtonWidget::LPictureButtonWidget(QWidget *parent)
    : QPushButton{parent}
{

}

void LPictureButtonWidget::paintEvent(QPaintEvent *event)
{
    QFont newFont = font();
//    float fontSize = DynamicFontSizeLabel::getWidgetMaximumFontSize(this, this->text());
//    newFont.setPointSizeF(fontSize);
    setFont(newFont);
    qDebug()<< "font" << newFont.pointSizeF();

    QPushButton::paintEvent(event);
}

void LPictureButtonWidget::setTextColor(QColor color){
    if (color.isValid() && color!=textColor){
        textColor = color;
        setStyleSheet("color : "+color.name()+";");
    }
}

void LPictureButtonWidget::setTextAndColor(const QString &text, QColor color){
    setTextColor(color);
    setText(text);
}

QColor LPictureButtonWidget::getTextColor(){
    return textColor;
}

/* Do not give any size hint as it it changes during paintEvent */
QSize LPictureButtonWidget::minimumSizeHint() const
{
    qDebug() << QWidget::minimumSizeHint();
    return QWidget::minimumSizeHint();
}

/* Do not give any size hint as it it changes during paintEvent */
QSize LPictureButtonWidget::sizeHint() const
{
    qDebug() << QWidget::sizeHint();
    return QWidget::sizeHint();
}
