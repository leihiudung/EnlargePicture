#include "menberwidget.h"
#include "ui_menberwidget.h"
#include <QGraphicsDropShadowEffect>
#include <QTextDocument>
#include <QTextBlock>

MenberWidget::MenberWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenberWidget)
{
    ui->setupUi(this);
    initView();
}

MenberWidget::~MenberWidget()
{
    delete ui;
}

void MenberWidget::initView()
{
    QLabel *recomLabl = new QLabel(this);
    QPixmap myPix(":/images/member_recommand_img");
//    ui->member_stand_label->setPixmap(myPix);
//    ui->member_stand_label->setFixedSize(211, 68);

//    ui->member_stand_label->setScaledContents(true);
//    ui->member_stand_label->setStyleSheet("QLabel{border-image:url(:/images/member_recommand_img) 30 round;}");


    ui->wechat_pay_highter_btn->setStyleSheet("QPushButton{background: #63C42E;border-radius: 2px;"
                                   "width: 96px;height:30px;"
                                   "qproperty-icon: url(:/images/wechat);"
                                   "font:12px Microsoft YaHei;"
                                   "color: #fff;text-align : left;padding-left: 8px;}");

    ui->ali_pay_highter_btn->setStyleSheet("QPushButton{background: #02A9F1;border-radius: 2px;"
                                              "width: 96px;height:30px;"
                                              "qproperty-icon: url(:/images/ali);"
                                              "font:12px Microsoft YaHei;"
                                              "color: #fff;text-align : left;padding-left: 8px;}");

    ui->wechat_pay_stand_btn->setStyleSheet("QPushButton{background: #63C42E;border-radius: 2px;"
                                              "width: 96px;height:30px;"
                                              "qproperty-icon: url(:/images/wechat);"
                                              "font:12px Microsoft YaHei;"
                                              "color: #fff;text-align : left;padding-left: 8px;}");

    ui->ali_pay_stand_btn->setStyleSheet("QPushButton{background: #02A9F1;border-radius: 2px;"
                                           "width: 96px;height:30px;"
                                           "qproperty-icon: url(:/images/ali);"
                                           "font:12px Microsoft YaHei;"
                                           "color: #fff;text-align : left;padding-left: 8px;}");

    ui->wechat_pay_base_btn->setStyleSheet("QPushButton{background: #63C42E;border-radius: 2px;"
                                              "width: 96px;height:30px;"
                                              "qproperty-icon: url(:/images/wechat);"
                                              "font:12px Microsoft YaHei;"
                                              "color: #fff;text-align : left;padding-left: 8px;}");

    ui->ali_pay_base_btn->setStyleSheet("QPushButton{background: #02A9F1;border-radius: 2px;"
                                           "width: 96px;height:30px;"
                                           "qproperty-icon: url(:/images/ali);"
                                           "font:12px Microsoft YaHei;"
                                           "color: #fff;text-align : left;padding-left: 8px;}");



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

}
