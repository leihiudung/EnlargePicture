#include "paymentwidget.h"
#include "ui_paymentwidget.h"

#include <QGraphicsDropShadowEffect>

PaymentWidget::PaymentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentWidget)
{
    ui->setupUi(this);
//    initView();

    connect(ui->close_btn, &QToolButton::clicked, [=](){
        close();
    });
}

PaymentWidget::~PaymentWidget()
{
    delete ui;
}

void PaymentWidget::initView()
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

    ui->close_btn->setStyleSheet("QToolButton{border-image:url(:/images/dialog_close_icon) 0 0 42 0;}"
                                 "QToolButton:hover{border-image:url(:/images/dialog_close_icon) 14 0 28 0;}"
                                 "QToolButton:pressed{border-image:url(:/images/dialog_close_icon) 28 0 14 0;}"
                                 "QToolButton:disabled{border-image:url(:/images/dialog_close_icon) 42 0 0 0;}");


    ui->qr_code_img->setStyleSheet("QLabel{border-image:url(:/images/qr_code);"
                                   "width:176px;height:176px;min-width:176px;min-height:176px;max-width:176px;max-height:176px;}");
    ui->scan_img->setStyleSheet("QLabel{border-image:url(:/images/scan_qr_code);"
                                "width:22px;height:22px;min-width:22px;min-height:22px;max-width:22px;max-height:22px;}");

}

void PaymentWidget::paymentBrand(int brand)
{
    ui->payment_type->setText(brand == 0 ? "打开手机微信" : "打开手机支付宝");
    initView();
}
