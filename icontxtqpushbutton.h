#ifndef ICONTXTQPUSHBUTTON_H
#define ICONTXTQPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

#define MIN_FONT_SIZE 20
#define MAX_FONT_SIZE 60


class IconTxtQPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit IconTxtQPushButton(QWidget *parent = nullptr);
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
    int oriWidth;
    int oriHeight;

};

#endif // ICONTXTQPUSHBUTTON_H
