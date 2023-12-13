#include "enlargewidget.h"
#include "ui_enlargewidget.h"
#include "selectedpicitemwidget.h"

#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QFileDialog>

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
                                   "border-radius: 15px;height:128px;"
                                   "qproperty-icon: url(:/images/enlarge_add_img);icon-size: 20px 20px;"
                                   "font:20px Microsoft YaHei;"
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

    connect(widget, &SelectedPicItemWidget::comfirnEnlargeParamSignal, [=](){
        qDebug("Clicked");
    });

    connect(widget, &SelectedPicItemWidget::closeSelectedPicItem, [=](){
        delete ITEM;
    });
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
    TypeLabel->setStyleSheet("QLabel{width: 92px;height: 92px;min-width:92px;min-height:92px;max-width:92px;max-height:92px;}");

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

void EnlargeWidget::selectPicBtnSlot(bool checked)
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("选择文件保存路径"), "./", tr("图片(*.png* *.jpg* *.jpeg*)"));
    if (imagePath.length() > 0) {
        initItem(imagePath);
    } else {

    }

}

