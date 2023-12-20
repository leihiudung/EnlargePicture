#include "selectedpicitemwidget.h"
#include "ui_selectedpicitemwidget.h"
#include "enlargeparamselectwidget.h"
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

void SelectedPicItemWidget::paintEvent(QPaintEvent *event)
{
//    qDebug() << ui->pic_label->width() << ":" << ui->pic_label->height();
//    //如果m_pBgWidget的宽大于高了,就按照它的高计算比例大小
//    if (ui->pic_label->width() > ui->pic_label->height())
//    {
//        float fScaleH = ui->pic_label->height();
//        float fScaleW = fScaleH * m_fScale;
//        ui->pic_label->resize(fScaleW, fScaleH); //重新设置QLabel的宽和高
//    }
//    else
//    {
//        //如果m_pBgWidget的宽小于高了,就按照它的宽计算比例大小
//        float fScaleW = ui->pic_label->width();
//        float fScaleH = fScaleW / m_fScale;
//        ui->pic_label->resize(fScaleW, fScaleH);//重新设置QLabel的宽和高
    //    }
}

void SelectedPicItemWidget::enlargeFinishSlot()
{
    ui->pic_big_progress->setValue(100);
}

void SelectedPicItemWidget::initView()
{

//    ui->pic_label->setStyleSheet("QLabel{width: 90px;height:95px;}");

    QImageReader imageReader;
    imageReader.setFileName(imgPath);

    auto oriImageSize = imageReader.size();

    /** */
    oriImageSize.scale(QSize(145, 145), Qt::KeepAspectRatioByExpanding);

    imageReader.setScaledSize(oriImageSize);

    QImage selectedImg = imageReader.read();
    QPixmap scalePixmap = QPixmap::fromImage(selectedImg);

    ui->pic_label->setFixedSize(90, 95);
//    ui->pic_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->pic_label->setPixmap(scalePixmap);
    ui->pic_label->setAlignment(Qt::AlignCenter);
    int picW = selectedImg.width();
    int picH = selectedImg.height();
//    m_fScale = picW/picH;
//    ui->pic_label->resize(picW, picH);

    ui->pic_info_label->setStyleSheet("QLabel{background-color: #F5F5F5;font: 12px Microsoft YaHei;color: #333;}");

    ui->pic_big_btn->setStyleSheet("QPushButton{background: #4586E4;border-radius: 2px;"
                                   "border-radius: 2px;height:28px;"
                                   "qproperty-icon: url(:/images/enlarge_big_btn);"
                                   "font:12px Microsoft YaHei;"
                                   "color: #fff;}");
    ui->pic_del_btn->setStyleSheet("QPushButton{background: #E92930;border-radius: 2px;"
                                   "border-radius: 2px;height:28px;"
                                   "qproperty-icon: url(:/images/enlarge_del_btn);"
                                   "font:12px Microsoft YaHei;"
                                   "color: #fff;}");

    QFileInfo info(imgPath);
    QString imgName = imgPath.split("/").last();
    QString picInfoStr;
    picInfoStr = QString(" %1x%2  |  %3 KB  |  %4").arg(scalePixmap.width()).arg(scalePixmap.height()).arg(QString::number(info.size() / 1024.0, 'f', 2)).arg(imgName);
    ui->pic_info_label->setText(picInfoStr);

    connect(ui->pic_big_btn, &QPushButton::clicked, [=](){
        EnlargeParamSelectWidget *paramWidget = new EnlargeParamSelectWidget();
        paramWidget->setWindowModality(Qt::ApplicationModal);
        connect(paramWidget, &EnlargeParamSelectWidget::comfirnEnlargeParamSignal, [=](int typeIndex, int scaleIndex, int noiseIndex){
            ui->pic_big_progress->setValue(40);
            emit comfirnEnlargeParamSignal(typeIndex, scaleIndex, noiseIndex);
        });
        paramWidget->show();
    });

    connect(ui->pic_del_btn, &QPushButton::clicked, [=](){
        emit closeSelectedPicItem();
    });

}
