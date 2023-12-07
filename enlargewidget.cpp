#include "enlargewidget.h"
#include "ui_enlargewidget.h"

EnlargeWidget::EnlargeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnlargeWidget)
{
    ui->setupUi(this);
    initView();
}

EnlargeWidget::~EnlargeWidget()
{
    delete ui;
}

void EnlargeWidget::initView()
{
    QPixmap iconaaa(":/images/enlarge_add_img");
    iconaaa = iconaaa.scaled(20, 20);
    ui->add_icon->setAlignment(Qt::AlignCenter);
    ui->add_icon->setPixmap(iconaaa);

}

//background-image: url(:/images/enlarge_add_img) no-repeat;
//background-position: left top;
//qproperty-iconSize: 36px 36px;
