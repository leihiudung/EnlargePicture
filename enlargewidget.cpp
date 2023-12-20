#include "enlargewidget.h"
#include "ui_enlargewidget.h"
#include "selectedpicitemwidget.h"
#include "enlargethread.h"

#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDateTime>

EnlargeWidget::EnlargeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnlargeWidget)
{
    ui->setupUi(this);
    initView();

    ui->selected_list_widget->setStyleSheet("QListWidget{border:none;}"
                                            "QListWidget::Item:hover{background:transparent;}"//悬浮
                                            "QListWidget::Item:pressed{background:#E8E9ED;}"//按下
                                            "QListWidget::item:selected:!active{background:#E8E9ED;}"//按下后，当前活动控件不在列表中
                                            "QListWidget::item:selected{background:transparent;}"//按下后鼠标移动到其它位置
                                            );

    connect(ui->pushButton, &QPushButton::clicked, this, &EnlargeWidget::selectPicBtnSlot);


}

EnlargeWidget::~EnlargeWidget()
{
    delete ui;
}


void EnlargeWidget::initView()
{
    ui->selected_list_widget->setGridSize(QSize(30, 120));
    ui->pushButton->setStyleSheet("QPushButton{background: transparent;border-radius: 2px;"
                                    "border-image:url(:/images/enlarge_add_border);"
                                    "border-radius: 15px;font-size:20px;"
                                    "qproperty-icon: url(:/images/enlarge_add_img);"
                                    "icon-size: 20px 20px;"
                                "color: #444;}");

}

void EnlargeWidget::initItem(const QString &imgPath)
{

    SelectedPicItemWidget *widget = new SelectedPicItemWidget(imgPath, ui->selected_list_widget);
    //将widget作为列表的item
    QListWidgetItem *ITEM = new QListWidgetItem();
    QSize size = ITEM->sizeHint();
    ITEM->setSizeHint(QSize(120, 107));
    ui->selected_list_widget->addItem(ITEM);
    ui->selected_list_widget->setItemWidget(ITEM, widget);

    connect(widget, &SelectedPicItemWidget::comfirnEnlargeParamSignal, [=](int typeIndex, int scaleIndex, int noiseIndex){
        enlargePic(imgPath, scaleIndex, noiseIndex);
    });

    connect(widget, &SelectedPicItemWidget::closeSelectedPicItem, [=](){
        delete ITEM;
    });

    connect(this, &EnlargeWidget::enlargeFinishSignal, widget, &SelectedPicItemWidget::enlargeFinishSlot);
}

void EnlargeWidget::initItem(const QString &str, const QString &picmap)
{
    QWidget *widget = new QWidget(ui->selected_list_widget);

    //创建自定义的item
    widget->setStyleSheet("background:transparent;");

    QWidget *frontAreaA = new QWidget(widget);
    frontAreaA->setFixedWidth(14);

    QLabel *TypeLabel = new QLabel(widget);
    QPixmap myPix(picmap);
    TypeLabel->setFixedSize(18, 18);
    TypeLabel->setPixmap(myPix);
    TypeLabel->setScaledContents(true);
//    TypeLabel->setStyleSheet("QLabel{width: 92px;height: 92px;min-width:92px;min-height:92px;max-width:192px;max-height:192px;}");

    QPushButton *enlargeBtn = new QPushButton(widget);
    enlargeBtn->setText(QString("HI"));
    enlargeBtn->setCursor(QCursor(Qt::PointingHandCursor));
    connect(enlargeBtn, &QPushButton::clicked, [=](){
        qDebug("I'm clicked");
    });

    QWidget *frontArea = new QWidget(widget);
    frontArea->setFixedHeight(20);

    QLabel *TotalCopyLabel = new QLabel(frontArea);
    TotalCopyLabel->setStyleSheet("QLabel{font: normal normal 15px Microsoft YaHei;color: white;padding-left: 6px;}");
    TotalCopyLabel->setText(str);

    QWidget *backArea = new QWidget(widget);
    backArea->setFixedSize(128, 50);

    QHBoxLayout *horLayout = new QHBoxLayout;
    horLayout->setContentsMargins(0, 0, 0, 0);
    horLayout->setMargin(0);
    horLayout->setSpacing(0);
    horLayout->addWidget(frontAreaA);
    horLayout->addWidget(TypeLabel);
    horLayout->addWidget(enlargeBtn);
    horLayout->addWidget(frontArea);
    widget->setLayout(horLayout);

    QVBoxLayout *rightPartLayout = new QVBoxLayout;


    //将widget作为列表的item
    QListWidgetItem *ITEM = new QListWidgetItem();
    QSize size = ITEM->sizeHint();
    ITEM->setSizeHint(QSize(120, 107));
    ui->selected_list_widget->addItem(ITEM);
    ui->selected_list_widget->setItemWidget(ITEM, widget);
}

void EnlargeWidget::deleteItem(int row)
{
//    ui->selected_list_widget->removeItemWidget(item);

//    qDebug("selected index %d", item);

//    int row = ui->selected_list_widget->currentRow();
    ui->selected_list_widget->takeItem(row);
}

void EnlargeWidget::enlargePic(QString originPath, int increase, int denoise)
{
    QFileInfo fileInfo = QFileInfo(originPath);

    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    QString filePath = QDir::currentPath();
    QString EXEName_src = ":/exe/waifu";
    QString EXEName_Dst = "waifu2x-ncnn-vulkan_boxed.exe";

    QString EXEName_Cmd = "waifu2x-ncnn-vulkan_boxed.exe -i ";
    QString EXE_CMD = EXEName_Cmd.append(originPath).append(" -o ").append(desktop_path).append("/").append(fileInfo.baseName()).append(".png -n ").append(QString::number(denoise)).append(" -s ").append(QString::number(increase));
    qDebug() << EXE_CMD;
    QFile EXEFile_src(EXEName_src);
    QFile EXEFile_Dst(EXEName_Dst);

    if (EXEFile_Dst.open(QIODevice::WriteOnly)) {
        if (EXEFile_src.open(QIODevice::ReadOnly)) {
            QByteArray tmp = EXEFile_src.readAll();
            EXEFile_Dst.write(tmp);
        }
    }
    EXEFile_Dst.close();
    EXEFile_src.close();
    QString CMD = EXE_CMD;

    QImage improveImg;
    QMap<QString, QString> imgInfo;
    if (improveImg.load(fileInfo.filePath())) {
        QDateTime dateTime= QDateTime::currentDateTime();
        imgInfo["file_timestamp"] = QString::number(dateTime.toTime_t());
        imgInfo["file_name"] = fileInfo.fileName();
        imgInfo["file_path"] = fileInfo.filePath();
        imgInfo["argument"] = QString("放大级别:%1 降噪级别:%2 分辨率:%3*%4").arg(increase).arg(denoise).arg(improveImg.width()).arg(improveImg.height());

                                      imgInfo["time"] = dateTime.toString("yyyy-MM-dd HH:mm");
        qDebug() << "保存路径" << fileInfo.filePath();
    }



    EnlargeThread *enlargeThread = new EnlargeThread();
    connect(enlargeThread, &EnlargeThread::finishEnlargeSignal, this, &EnlargeWidget::enlargeThreadFinishSlot);
    enlargeThread->EXE_CMD = EXE_CMD;
    enlargeThread->imageInfo = imgInfo;
    enlargeThread->start();

}

void EnlargeWidget::enlargeThreadFinishSlot(bool flag)
{
    QString EXEName_Dst = "waifu2x-ncnn-vulkan_boxed.exe";
    QFile::remove(EXEName_Dst); //删掉exe文件
    emit enlargeFinishSignal();
}

void EnlargeWidget::upgrageProgressWidget(int percent)
{

}

void EnlargeWidget::selectPicBtnSlot(bool checked)
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("选择文件保存路径"), "./", tr("图片(*.png* *.jpg* *.jpeg*)"));
    if (imagePath.length() > 0) {
        initItem(imagePath);
    } else {

    }

}

