#include "retrievepasswordwidget.h"
#include "ui_retrievepasswordwidget.h"

#include <QGraphicsDropShadowEffect>

RetrievePasswordWidget::RetrievePasswordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RetrievePasswordWidget)
{
    ui->setupUi(this);
    initView();

    connect(ui->close_btn, &QPushButton::clicked, [=](){
        close();
    });

    connect(ui->confirm_btn, &QPushButton::clicked, [=](){

    });

    connect(ui->cancel_btn, &QPushButton::clicked, [=](){
        close();
    });
}

RetrievePasswordWidget::~RetrievePasswordWidget()
{
    delete ui;
}

void RetrievePasswordWidget::initView()
{
    //设置窗体透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //设置无边框
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //实例阴影shadow
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(0, 4);
    //    shadow->setYOffset(6);
    //设置阴影颜色
    shadow->setColor(QColor(0, 0, 0, 70));
    //设置阴影圆角
    shadow->setBlurRadius(43);
    //给嵌套QWidget设置阴影
    ui->widget->setGraphicsEffect(shadow);
    ui->gridLayout->setMargin(40);


    //设置具体阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(219, 219, 219));
    //阴影半径
    shadow_effect->setBlurRadius(22);

    ui->email_edit->setStyleSheet("QLineEdit{background: #FCFDFF;border: 1px solid #C0C6D9;"
                                    "width:260px;height:35px;font: 12px Microsoft YaHei; };");


    ui->confirm_btn->setStyleSheet("QPushButton{border: 1px solid #4586E4;font: 14px Microsoft YaHei;color:white;background: #4586E4;"
                                   "width: 98px; height:32px;};");
    ui->confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->cancel_btn->setStyleSheet("QPushButton{border: 1px solid #C7CDDF;font: 14px Microsoft YaHei;color:#444444;background: #FFF;"
                                  "width: 98px; height:32px;};");
    ui->cancel_btn->setCursor(QCursor(Qt::PointingHandCursor));
}
