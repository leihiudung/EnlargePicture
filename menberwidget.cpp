#include "menberwidget.h"
#include "ui_menberwidget.h"
#include "paymentwidget.h"

#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QTextDocument>
#include <QTextBlock>
#include <QResizeEvent>
#include <QLabel>

MenberWidget::MenberWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenberWidget)
{
    ui->setupUi(this);
    initView();

    connect(ui->wechat_pay_highter_btn, &QPushButton::clicked, [=](){
        showWeChatPay();
    });

    connect(ui->wechat_pay_stand_btn, &QPushButton::clicked, [=](){
        showWeChatPay();
    });

    connect(ui->wechat_pay_base_btn, &QPushButton::clicked, [=](){
        showWeChatPay();
    });

    connect(ui->ali_pay_highter_btn, &QPushButton::clicked, [=](){
        showAliPay();
    });

    connect(ui->ali_pay_stand_btn, &QPushButton::clicked, [=](){
        showAliPay();
    });

    connect(ui->ali_pay_base_btn, &QPushButton::clicked, [=](){
        showAliPay();
    });
}

MenberWidget::~MenberWidget()
{
    delete ui;
}

void MenberWidget::paintEvent(QPaintEvent *event)
{

    qDebug() << "进入Degub" << event->rect().width();

}

void MenberWidget::initView()
{

    recomLabl = new QLabel(this);

//    ui->member_stand_label->setPixmap(myPix);
//    ui->member_stand_label->setFixedSize(211, 68);

//    ui->member_stand_label->setScaledContents(true);
//    ui->member_stand_label->setStyleSheet("QLabel{border-image:url(:/images/member_recommand_img) 30 round;}");


    ui->wechat_pay_highter_btn->setStyleSheet("QPushButton{background: #63C42E;border-radius: 2px;"
                                              "height:30px;max-height:46px;"
                                   "qproperty-icon: url(:/images/wechat);"
                                   "font:12px Microsoft YaHei;"
                                   "color: #fff;text-align : left;padding-left: 8px;}");

    ui->ali_pay_highter_btn->setStyleSheet("QPushButton{background: #02A9F1;border-radius: 2px;"
                                           "height:30px;max-height:46px;"
                                              "qproperty-icon: url(:/images/ali);"
                                              "font:12px Microsoft YaHei;"
                                              "color: #fff;text-align : left;padding-left: 8px;}");

//    ui->wechat_pay_stand_btn->setStyleSheet("QPushButton{background: #63C42E;border-radius: 2px;"
//                                              "width: 96px;height:30px;max-width: 126px;max-height:36px;"
//                                              "qproperty-icon: url(:/images/wechat);"
//                                              "font:12px Microsoft YaHei;"
//                                              "color: #fff;text-align : left;padding-left: 8px;}");

    ui->ali_pay_stand_btn->setStyleSheet("QPushButton{background: #02A9F1;border-radius: 2px;"
                                         "height:30px;max-height:46px;"
                                           "qproperty-icon: url(:/images/ali);"
                                           "font:12px Microsoft YaHei;"
                                           "color: #fff;text-align : left;padding-left: 8px;}");

    ui->wechat_pay_base_btn->setStyleSheet("QPushButton{background: #63C42E;border-radius: 2px;"
                                           "height:30px;max-height:46px;"
                                              "qproperty-icon: url(:/images/wechat);"
                                              "font:12px Microsoft YaHei;"
                                              "color: #fff;text-align : left;padding-left: 8px;}");

    ui->ali_pay_base_btn->setStyleSheet("QPushButton{background: #02A9F1;border-radius: 2px;"
                                            "height:30px;max-height:46px;"
                                            "qproperty-icon: url(:/images/ali);"
                                            "font:12px Microsoft YaHei;"
                                            "color: #fff;text-align : left;padding-left: 8px;}");

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
//    ui->wechat_pay_stand_btn->setSizePolicy(sizePolicy);


    ui->widget_9->setStyleSheet("QWidget{padding-left:9px;");

    ui->wechat_pay_highter_btn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->wechat_pay_stand_btn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->wechat_pay_base_btn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->ali_pay_highter_btn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->ali_pay_stand_btn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->ali_pay_base_btn->setCursor(QCursor(Qt::PointingHandCursor));


    //设置具体阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(219, 219, 219));
    //阴影半径
    shadow_effect->setBlurRadius(22);

//    QGraphicsDropShadowEffect *freeShadow = shadow_effect;
    //设置具体阴影
    QGraphicsDropShadowEffect *freeShadow = new QGraphicsDropShadowEffect(this);
    freeShadow->setOffset(shadow_effect->offset());
    freeShadow->setColor(shadow_effect->color());
    freeShadow->setBlurRadius(shadow_effect->blurRadius());

    QGraphicsDropShadowEffect *hightShadow = new QGraphicsDropShadowEffect(this);
    hightShadow->setOffset(shadow_effect->offset());
    hightShadow->setColor(shadow_effect->color());
    hightShadow->setBlurRadius(shadow_effect->blurRadius());

    QGraphicsDropShadowEffect *standShadow = new QGraphicsDropShadowEffect(this);
    standShadow->setOffset(shadow_effect->offset());
    standShadow->setColor(shadow_effect->color());
    standShadow->setBlurRadius(shadow_effect->blurRadius());

    QTextDocument* freeDoc = ui->member_free_browser->document();
    for(QTextBlock it = freeDoc->begin(); it != freeDoc->end(); it = it.next())
    {
        QTextCursor textCursor(it);
        QTextBlockFormat textBlockFormat = it.blockFormat();
        //set line height
        textBlockFormat.setLineHeight(22,QTextBlockFormat::FixedHeight);
        textCursor.setBlockFormat(textBlockFormat);
        ui->member_highter_browser->setTextCursor(textCursor);
    }

    QTextDocument* heighterDoc = ui->member_highter_browser->document();
    for(QTextBlock it = heighterDoc->begin(); it != heighterDoc->end(); it = it.next())
    {
        QTextCursor textCursor(it);
        QTextBlockFormat textBlockFormat = it.blockFormat();
        //set line height
        textBlockFormat.setLineHeight(22,QTextBlockFormat::FixedHeight);
        textCursor.setBlockFormat(textBlockFormat);
        ui->member_highter_browser->setTextCursor(textCursor);
    }

    QTextDocument* standDoc = ui->member_stand_browser->document();
    for(QTextBlock it = standDoc->begin(); it != standDoc->end(); it = it.next())
    {
        QTextCursor textCursor(it);
        QTextBlockFormat textBlockFormat = it.blockFormat();
        //set line height
        textBlockFormat.setLineHeight(22,QTextBlockFormat::FixedHeight);
        textCursor.setBlockFormat(textBlockFormat);
        ui->member_stand_browser->setTextCursor(textCursor);
    }

    QTextDocument* baseDoc = ui->member_base_browser->document();
    for(QTextBlock it = baseDoc->begin(); it != baseDoc->end(); it = it.next())
    {
        QTextCursor textCursor(it);
        QTextBlockFormat textBlockFormat = it.blockFormat();
        //set line height
        textBlockFormat.setLineHeight(22,QTextBlockFormat::FixedHeight);
        textCursor.setBlockFormat(textBlockFormat);
        ui->member_base_browser->setTextCursor(textCursor);
    }

//    ui->member_highter_browser->seth(120);
    ui->widget_5->setGraphicsEffect(freeShadow);
    ui->widget_6->setGraphicsEffect(hightShadow);
    ui->widget_7->setGraphicsEffect(standShadow);
    ui->widget_8->setGraphicsEffect(shadow_effect);

//    QPoint labRect = ui->member_stand_label->mapTo(ui->widget_3->pos());
//    ui->member_stand_browser->(QCursor::pos());
//    QPoint parentPos = ui->member_stand_label->mapFromParent(ui->widget_3->pos());
//        int jj = globalPos.x();


    int widthj =  ui->widget_3->width();
    qDebug() << ui->widget_3->sizeIncrement() << ";" << ui->widget_3->minimumSizeHint() << "==" << ui->member_stand_label->sizeHint().width();

    QImage recomImg(":/images/recommand_img");

    QPixmap myPix(":/images/recommand_img");
    recomLabl->setPixmap(QPixmap::fromImage(recomImg));
    recomLabl->setGeometry(33 + 174 * 3 + 10 * 3, ui->member_stand_label->height(), 66, 68);

}

void MenberWidget::showWeChatPay()
{
    PaymentWidget *widget = new PaymentWidget();
    widget->paymentBrand(0);
    widget->setWindowModality(Qt::ApplicationModal);
    widget->show();
}

void MenberWidget::showAliPay()
{
    PaymentWidget *widget = new PaymentWidget();
    widget->paymentBrand(1);
    widget->setWindowModality(Qt::ApplicationModal);
    widget->show();
}
