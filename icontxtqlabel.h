#ifndef ICONTXTQLABEL_H
#define ICONTXTQLABEL_H

#include <QLabel>
#include <QColor>

class IconTxtQLabel : public QLabel
{
    Q_OBJECT
public:
    explicit IconTxtQLabel(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    static float getWidgetMaximumFontSize(QWidget *widget, QString text);

    /* This method overwrite stylesheet */
    void setTextColor(QColor color);
    QColor getTextColor();
    void setTextAndColor(const QString &text, QColor color = QColor::Invalid);
signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
    QColor textColor;


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    // QWidget interface
public:
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

};

#endif // ICONTXTQLABEL_H
