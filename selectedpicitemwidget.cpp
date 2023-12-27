#include "selectedpicitemwidget.h"
#include "ui_selectedpicitemwidget.h"
#include "enlargeparamselectwidget.h"
#include <QFileInfo>
#include <QImageReader>
#include <QPainter>
#include <QGraphicsOpacityEffect>
#include <QDesktopServices>

/**
 * @brief SelectedPicItemWidget::SelectedPicItemWidget
 * @param imgPath
 * @param parent
 */
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

//    QPainter painter(this);

//    QColor color(255, 150, 30);
//    painter.setBrush(color);
//    painter.drawRect(ui->pic_label->rect());

    QPainter p(ui->pic_label);

    p.setPen(Qt::NoPen);

    p.setBrush(Qt::black);

    p.drawRect(rect());

}

void SelectedPicItemWidget::enlargeFinishSlot()
{
    ui->pic_label->paintMask = false;
    ui->pic_big_progress->setValue(100);
    ui->pic_big_btn->setEnabled(true);
    ui->pic_del_btn->setEnabled(true);
     ui->pic_watch_btn->setVisible(true);

    this->update();
}

void SelectedPicItemWidget::confirmActionSlot()
{
    emit confirmCloseSelectedPicItem();
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
                                   "color: #fff;}"
                                   "QPushButton:!enabled {background: #CBD0DF;};");
    ui->pic_del_btn->setStyleSheet("QPushButton{background: #E92930;border-radius: 2px;"
                                   "border-radius: 2px;height:28px;"
                                   "qproperty-icon: url(:/images/enlarge_del_btn);"
                                   "font:12px Microsoft YaHei;"
                                   "color: #fff;}"
                                   "QPushButton:!enabled {background: #CBD0DF;};");
    ui->pic_watch_btn->setStyleSheet("QPushButton{background: #4586E4;border-radius: 2px;"
                                     "border-radius: 2px;height:28px;"
                                     "qproperty-icon: url(:/images/enlarge_big_btn);"
                                     "font:12px Microsoft YaHei;"
                                     "color: #fff;}"
                                     "QPushButton:!enabled {background: #CBD0DF;};");
    ui->pic_watch_btn->setVisible(false);
    ui->pic_watch_btn->setCursor(QCursor(Qt::PointingHandCursor));

    QFileInfo info(imgPath);
    QString imgName = imgPath.split("/").last();
    QString picInfoStr;
    picInfoStr = QString(" %1x%2  |  %3 KB  |  %4").arg(scalePixmap.width()).arg(scalePixmap.height()).arg(QString::number(info.size() / 1024.0, 'f', 2)).arg(imgName);
    ui->pic_info_label->setText(picInfoStr);

    connect(ui->pic_big_btn, &QPushButton::clicked, [=](){
        ui->pic_watch_btn->setVisible(false);
        EnlargeParamSelectWidget *paramWidget = new EnlargeParamSelectWidget();
        paramWidget->setWindowModality(Qt::ApplicationModal);
        connect(paramWidget, &EnlargeParamSelectWidget::comfirnEnlargeParamSignal, [=](int typeIndex, int scaleIndex, int noiseIndex){

            ui->pic_label->paintMask = true;
            ui->pic_big_btn->setEnabled(false);
            ui->pic_del_btn->setEnabled(false);
            ui->pic_big_progress->setValue(40);
//            this->update();
            emit comfirnEnlargeParamSignal(typeIndex, scaleIndex, noiseIndex);

            ui->pic_watch_btn->setVisible(false);
        });
        paramWidget->show();
    });

    connect(ui->pic_watch_btn, &QPushButton::clicked, [=](){
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QFileInfo fileInfo = QFileInfo(imgPath);

        QDesktopServices::openUrl(QUrl(desktop_path.append("/").append(fileInfo.baseName()).append(".png")));
        qDebug() << "IMG" << fileInfo.baseName();
    });

    connect(ui->pic_del_btn, &QPushButton::clicked, [=](){
        emit closeSelectedPicItem();
    });


}

void SelectedPicItemWidget::addLayerMask(bool flag)
{
    if (flag) {
        int lawi = ui->pic_label->width();
        int lawh = ui->pic_label->height();
        qDebug() << ui->pic_label->minimumSizeHint();
        QString picLabelSheetStr = ui->pic_label->styleSheet();
        ui->pic_label->setHidden(true);

        QString maskLabelSheetStr = "QLabel{width: %1 px;height: %2 px;background-color:rgba(0,0,0,125);;min-width: %1 px;max-width: %1 px;min-height: %2 px;max_height: %2 px}";
        maskLabelSheetStr = maskLabelSheetStr.arg(QString::number(lawi)).arg(QString::number(lawh));
//        maskLabelSheetStr.arg(QString::number(lawh));

        maskLabel = new QLabel(this);
//        maskLabel->setStyleSheet("QLabel{width:90px;height: 90px;background-color:black;min-width:90px;max-width:90px;max-width:90px;max_height: 90px}");
        maskLabel->setStyleSheet(maskLabelSheetStr);
        maskLabel->setText("放大中");


        ui->gridLayout_4->addWidget(maskLabel);
    } else {
        ui->pic_label->setHidden(false);
        maskLabel->setHidden(true);
    }


/**  */
    // 创建 QGraphicsOpacityEffect
//    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect();
//    effect->setOpacity(0.8); // 设置蒙层透明度为50%
//    ui->pic_label->setGraphicsEffect(effect);

/**  */
//    QGraphicsColorizeEffect *effect2 = new QGraphicsColorizeEffect();
//    effect2->setColor(QColor(qRgba(0, 0, 0, 255)));
//    ui->pic_label->setGraphicsEffect(effect2);

/**  */
//    QPalette palette;
//    //设置主窗口背景颜色
//    palette.setColor(QPalette::Window,QColor(255, 150, 30));
//    ui->pic_label->setPalette(palette);

//    QLabel *maskLabel = new QLabel(ui->widget);
//    maskLabel->setStyleSheet("QLabel{background-color: rgba(0,0,0, 50%)};");
//    maskLabel->setText("HIHHHH");
//    //3.移动按钮位置
//    maskLabel->move(0,0);

//    //4.设置按钮大小
//    //maskLabel->resize(60,60);

//    //5.按钮位置大小
//    maskLabel->setGeometry(0,0,60,60); //x和y是按钮的位置，a和b是按钮的长和宽
//    ui->gridLayout_4->addWidget(maskLabel);
//    maskLabel->layout()->setAlignment(Qt::AlignRight);
//    ui->horizontalLayout_2->addWidget(maskLabel);



}
