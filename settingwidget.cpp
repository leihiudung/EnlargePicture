#include "settingwidget.h"
#include "ui_settingwidget.h"

SettingWidget::SettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWidget)
{
    ui->setupUi(this);
    initView();
}

SettingWidget::~SettingWidget()
{
    delete ui;
}

void SettingWidget::initView()
{

    ui->qr_code_img->setStyleSheet("QLabel{border-image:url(:/images/qr_code);"
                                   "width:130px;height:130px;min-width:130px;min-height:130px;max-width:130px;max-height:130px;}");
    ui->qr_code_img->setAlignment(Qt::AlignCenter);
}
