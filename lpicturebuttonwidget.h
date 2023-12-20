#ifndef LPICTUREBUTTONWIDGET_H
#define LPICTUREBUTTONWIDGET_H

#include <QWidget>
#include <QPushButton>

class LPictureButtonWidget : public QPushButton
{
    Q_OBJECT
public:
    explicit LPictureButtonWidget(QWidget *parent = nullptr);
    /* This method overwrite stylesheet */
    void setTextColor(QColor color);
    QColor getTextColor();

    void setTextAndColor(const QString &text, QColor color=QColor::Invalid);

    // QWidget interface
    QSize minimumSizeHint() const;
    QSize sizeHint() const;


protected:
    void paintEvent(QPaintEvent *event);

private:
    QColor textColor;

};

#endif // LPICTUREBUTTONWIDGET_H
