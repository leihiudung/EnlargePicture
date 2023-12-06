#include "widget.h"
#include "ui_widget.h"


#include <QGraphicsDropShadowEffect>

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);

    //设置窗体透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //设置无边框
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //实例阴影shadow
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(0, 8);
    //    shadow->setYOffset(6);
    //设置阴影颜色
    shadow->setColor(QColor(0, 0, 0, 70));
    //设置阴影圆角
    shadow->setBlurRadius(43);
    //给嵌套QWidget设置阴影
    ui->useable_widget->setGraphicsEffect(shadow);
    //给垂直布局器设置边距(此步很重要, 设置宽度为阴影的宽度)
    ui->gridLayout->setMargin(40);

    initView();
}

widget::~widget()
{
    delete ui;
}

void widget::initView()
{
    QPixmap iconaaa(":/images/nav_icon");
    iconaaa = iconaaa.scaled(30, 30);
    ui->icon_label->setAlignment(Qt::AlignCenter);
    ui->icon_label->setPixmap(iconaaa);
    qDebug("%f", ui->icon_label->width());

    ui->min_btn->setStyleSheet("QToolButton{border-image:url(:/images/navi_min_icon) 0 0 42 0;}"
                                 "QToolButton:hover{border-image:url(:/images/navi_min_icon) 14 0 28 0;}"
                                 "QToolButton:pressed{border-image:url(:/images/navi_min_icon) 28 0 14 0;}"
                                 "QToolButton:disabled{border-image:url(:/images/navi_min_icon) 42 0 0 0;}");

    ui->close_btn->setStyleSheet("QToolButton{border-image:url(:/images/navi_close_icon) 0 0 42 0;}"
                                 "QToolButton:hover{border-image:url(:/images/navi_close_icon) 14 0 28 0;}"
                                "QToolButton:pressed{border-image:url(:/images/navi_close_icon) 28 0 14 0;}"
                                 "QToolButton:disabled{border-image:url(:/images/navi_close_icon) 42 0 0 0;}");
}
