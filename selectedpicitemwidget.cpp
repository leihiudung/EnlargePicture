#include "selectedpicitemwidget.h"
#include "ui_selectedpicitemwidget.h"

SelectedPicItemWidget::SelectedPicItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectedPicItemWidget)
{
    ui->setupUi(this);
    initView();
}

SelectedPicItemWidget::~SelectedPicItemWidget()
{
    delete ui;
}

void SelectedPicItemWidget::initView()
{

    ui->pic_label->setStyleSheet("QLabel{width: 90px;height:95px;}");
    QPixmap myPix(":/images/default_pic");
    ui->pic_label->setFixedSize(90, 95);
    ui->pic_label->setPixmap(myPix);
    ui->pic_label->setScaledContents(true);

    ui->pic_info_label->setStyleSheet("QLabel{background-color: #F5F5F5;}");

    ui->pic_big_btn->setStyleSheet("QPushButton{background: #4586E4;border-radius: 2px;"
                                   "border-radius: 2px;width: 62px;height:28px;"
                                   "qproperty-icon: url(:/images/enlarge_big_btn);"
                                   "font:12px Microsoft YaHei;"
                                   "color: #fff;}");
    ui->pic_del_btn->setStyleSheet("QPushButton{background: #E92930;border-radius: 2px;"
                                   "border-radius: 2px;width: 62px;height:28px;"
                                   "qproperty-icon: url(:/images/enlarge_del_btn);"
                                   "font:12px Microsoft YaHei;"
                                   "color: #fff;}");

}
