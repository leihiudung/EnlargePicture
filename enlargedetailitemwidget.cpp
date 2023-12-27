#include "enlargedetailitemwidget.h"
#include "ui_enlargedetailitemwidget.h"
#include <QFileInfo>
#include <QImageReader>

EnlargeDetailItemWidget::EnlargeDetailItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnlargeDetailItemWidget)
{
    ui->setupUi(this);
    initView();

}

EnlargeDetailItemWidget::~EnlargeDetailItemWidget()
{
    delete ui;
}

void EnlargeDetailItemWidget::initView()
{
//    ui->img_label->setStyleSheet("QLabel{background-color:blue;width: 52px;height:52px;min-width:52px; min-height:52px;max-width:62px;max-height:62px;}");

    QImageReader imageReader;
    imageReader.setFileName(":/images/default_pic");

    auto oriImageSize = imageReader.size();
    oriImageSize.scale(QSize(52, 52), Qt::KeepAspectRatioByExpanding);

    imageReader.setScaledSize(oriImageSize);

    QImage selectedImg = imageReader.read();
    QPixmap scalePixmap = QPixmap::fromImage(selectedImg);
    ui->img_label->setFixedSize(52, 52);
    ui->img_label->setPixmap(scalePixmap);

    ui->watch_btn->setStyleSheet("QPushButton{background: #4586E4;border-radius: 2px;"
                                 "border-radius: 2px;width: 62px;height:28px;"
                                 "qproperty-icon: url(:/images/enlarge_big_btn);"
                                 "font:12px Microsoft YaHei;"
                                 "color: #fff;}");
    ui->watch_btn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->del_btn->setStyleSheet("QPushButton{background: #E92930;border-radius: 2px;"
                               "border-radius: 2px;width: 62px;height:28px;"
                               "qproperty-icon: url(:/images/enlarge_del_btn);"
                               "font:12px Microsoft YaHei;"
                               "color: #fff;}");
    ui->del_btn->setCursor(QCursor(Qt::PointingHandCursor));

}

void EnlargeDetailItemWidget::addEnlargeMaskView()
{
    QLabel *maskLabel = new QLabel(this);
    maskLabel->setText("HI");
    maskLabel->setParent(this);
    maskLabel->setStyleSheet("QLabel{background-color: rgba(255, 255, 224, 50%);width: 60px;height:60px;min-width:60px;max-width:120px;min-height:60px;max-height:120px;}");
    maskLabel->move(600, 400);



    //4.设置按钮大小
    maskLabel->resize(120, 120);

    //5.按钮位置大小
    maskLabel->setGeometry(400, 400, 120, 120); //x和y是按钮的位置，a和b是按钮的长和宽
}
