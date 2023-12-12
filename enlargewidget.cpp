#include "enlargewidget.h"
#include "ui_enlargewidget.h"
#include "selectedpicitemwidget.h"
#include <QPushButton>

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
//    initItem("", ":/images/default_pic");
    initItem();

}

EnlargeWidget::~EnlargeWidget()
{
    delete ui;
}

void EnlargeWidget::initView()
{

    ui->select_pic_widget->setStyleSheet("QWidget#select_pic_widget{border-image:url(:/images/enlarge_add_border)}");

    QPixmap iconaaa(":/images/enlarge_add_img");
    iconaaa = iconaaa.scaled(20, 20);
    ui->add_icon->setAlignment(Qt::AlignCenter);
    ui->add_icon->setPixmap(iconaaa);


}

void EnlargeWidget::initItem()
{
    SelectedPicItemWidget *widget = new SelectedPicItemWidget(ui->selected_list_widget);
    //将widget作为列表的item
    QListWidgetItem *ITEM = new QListWidgetItem();
    QSize size = ITEM->sizeHint();
    ITEM->setSizeHint(QSize(120, 107));
    ui->selected_list_widget->addItem(ITEM);
    ui->selected_list_widget->setItemWidget(ITEM, widget);

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
