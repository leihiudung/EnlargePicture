#include "enlargeparamselectwidget.h"
#include "ui_enlargeparamselectwidget.h"

#include <QStyle>
#include <QButtonGroup>
#include <QGraphicsDropShadowEffect>

EnlargeParamSelectWidget::EnlargeParamSelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnlargeParamSelectWidget)
{
    ui->setupUi(this);

    initView();

    connect(ui->close_btn,&QPushButton::clicked,this,&QWidget::close); //方式一

    connect (typeGroup, SIGNAL(buttonClicked(int)), this, SLOT(typeGroupClickedSlot(int)));
    connect (magnificationGroup, SIGNAL(buttonClicked(int)), this, SLOT(magnificationGroupClickedSlot(int)));
    connect (qualityGroup, SIGNAL(buttonClicked(int)), this, SLOT(qualityGroupClickedSlot(int)));

    connect(ui->confirm_btn, &QPushButton::clicked, [=](){
        emit comfirnEnlargeParamSignal(typeIndex, magnificationIndex, qualityIndex);
        close();
    });

    connect(ui->cancel_btn, &QPushButton::clicked, [=](){
        close();
    });
}

EnlargeParamSelectWidget::~EnlargeParamSelectWidget()
{
    delete ui;
}

void EnlargeParamSelectWidget::initView()
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

    ui->confirm_btn->setStyleSheet("QPushButton{border: 1px solid #4586E4;font: 14px Microsoft YaHei;color:white;background: #4586E4;"
                                          "width: 98px; height:32px;};");
    ui->confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->cancel_btn->setStyleSheet("QPushButton{border: 1px solid #C7CDDF;font: 14px Microsoft YaHei;color:#444444;background: #FFF;"
                                   "width: 98px; height:32px;};");
    ui->cancel_btn->setCursor(QCursor(Qt::PointingHandCursor));

    typeGroup = new QButtonGroup(this);
    typeGroup->addButton(ui->type_radio_carton, 0);
    typeGroup->addButton(ui->type_radio_pic, 1);

    magnificationGroup = new QButtonGroup(this);
    magnificationGroup->addButton(ui->magn_radio_2, 2);
    magnificationGroup->addButton(ui->magn_radio_4, 4);
    magnificationGroup->addButton(ui->magn_radio_8, 8);
    magnificationGroup->addButton(ui->magn_radio_16, 16);
    magnificationGroup->addButton(ui->magn_radio_32, 32);

    qualityGroup = new QButtonGroup(this);
    qualityGroup->addButton(ui->quality_radio_1, 0);
    qualityGroup->addButton(ui->quality_radio_2, 1);
    qualityGroup->addButton(ui->quality_radio_3, 2);
    qualityGroup->addButton(ui->quality_radio_4, 3);
    qualityGroup->addButton(ui->quality_radio_5, 4);

}

void EnlargeParamSelectWidget::typeGroupClickedSlot(int i)
{
    typeIndex = i;
}

void EnlargeParamSelectWidget::magnificationGroupClickedSlot(int i)
{
    magnificationIndex = i;
}

void EnlargeParamSelectWidget::qualityGroupClickedSlot(int i)
{
    qualityIndex = i;
}


