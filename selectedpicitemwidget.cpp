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

void SelectedPicItemWidget::initView()
{

    ui->pic_label->setStyleSheet("QLabel{width: 90px;height:95px;}");

    QImageReader imageReader;
    imageReader.setFileName(imgPath);

    auto oriImageSize = imageReader.size();

    /** */
    oriImageSize.scale(QSize(145, 145), Qt::KeepAspectRatioByExpanding);

    imageReader.setScaledSize(oriImageSize);

    QImage selectedImg = imageReader.read();
    QPixmap scalePixmap = QPixmap::fromImage(selectedImg);

    ui->pic_label->setFixedSize(90, 95);
    ui->pic_label->setPixmap(scalePixmap);
    ui->pic_label->setAlignment(Qt::AlignCenter);

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

    connect(ui->pic_big_btn, &QPushButton::clicked, [=](){
        EnlargeParamSelectWidget *paramWidget = new EnlargeParamSelectWidget();
        paramWidget->setWindowModality(Qt::ApplicationModal);
        connect(paramWidget, &EnlargeParamSelectWidget::comfirnEnlargeParamSignal, [=](int i, int j, int z){
            emit comfirnEnlargeParamSignal(i, j, z);
        });
        paramWidget->show();
    });

    connect(ui->pic_del_btn, &QPushButton::clicked, [=](){
        emit closeSelectedPicItem();
    });

}
