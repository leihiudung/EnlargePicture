#include "selectedpicitemwidget.h"
#include "ui_selectedpicitemwidget.h"
#include <QFileInfo>
#include <QImageReader>

SelectedPicItemWidget::SelectedPicItemWidget(const QString &imgPath, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectedPicItemWidget)
{
    ui->setupUi(this);
    this->imgPath = imgPath;
    initView();
}

SelectedPicItemWidget::~SelectedPicItemWidget()
{
    delete ui;
}

void SelectedPicItemWidget::initView()
{

    ui->pic_label->setStyleSheet("QLabel{width: 90px;height:95px;}");

    QImageReader imageReader;
    imageReader.setFileName(imgPath);
//    imageReader.setAutoTransform(true);

    auto oriImageSize = imageReader.size();

    /** */
    oriImageSize.scale(QSize(145, 145), Qt::KeepAspectRatioByExpanding);

    imageReader.setScaledSize(oriImageSize);
//    oriImageSize.setHeight(100);
//    oriImageSize.setWidth(100);
//    imageReader.setScaledSize(oriImageSize);
    QImage selectedImg = imageReader.read();
    QPixmap scalePixmap = QPixmap::fromImage(selectedImg);
    /** */

    //    auto targetImageSize = oriImageSize.scaled(imageSize, Qt::AspectRatioMode::KeepAspectRatio);


//    auto targetImageSize = oriImageSize.scaled(QSize(120, 120), Qt::AspectRatioMode::KeepAspectRatio);
//    imageReader.setScaledSize(targetImageSize);
//    QPixmap scalePixmap = QPixmap::fromImageReader(&imageReader);
//    QPixmap scalePixmap = QPixmap::fromImage(QImage(imgPath));
//    scalePixmap.scaled(90, 95, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

//    QPixmap myPix(imgPath);
//    myPix = myPix.scaled(90,95/myPix.width()*myPix.height());//按照宽度等比例放大

    ui->pic_label->setFixedSize(90, 95);
    ui->pic_label->setPixmap(scalePixmap);
    ui->pic_label->setAlignment(Qt::AlignCenter);
//    ui->pic_label->setScaledContents(true);

    ui->pic_info_label->setStyleSheet("QLabel{background-color: #F5F5F5;font: 12px Microsoft YaHei;color: #333;}");

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

    QFileInfo info(imgPath);
    QString imgName = imgPath.split("/").last();
    QString picInfoStr;
    picInfoStr = QString(" %1x%2  |  %3 KB  |  %4").arg(scalePixmap.width()).arg(scalePixmap.height()).arg(QString::number(info.size() / 1024.0, 'f', 2)).arg(imgName);
    ui->pic_info_label->setText(picInfoStr);

}
