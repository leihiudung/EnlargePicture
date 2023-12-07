#include "widget.h"
#include "ui_widget.h"
#include "enlargewidget.h"
#include "accountwidget.h"
#include "menberwidget.h"
#include "settingwidget.h"

#include <QGraphicsDropShadowEffect>
#include <QFileInfo>
#include <QPainter>
#include <QDebug>

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);

    //设置窗体透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //设置无边框
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //实例阴影shadow
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(0, 8);
    //    shadow->setYOffset(6);
    //设置阴影颜色
    shadow->setColor(QColor(0, 0, 0, 70));
    //设置阴影圆角
    shadow->setBlurRadius(43);
    //给嵌套QWidget设置阴影
    ui->useable_widget->setGraphicsEffect(shadow);
    //给垂直布局器设置边距(此步很重要, 设置宽度为阴影的宽度)
    ui->gridLayout->setMargin(40);

    m_areaMovable = geometry();
    m_bPressed = false;

    QList<QString> optionPixmapList;
    optionPixmapList << QString(":/images/option_enlarge") << QString(":/images/option_account") << QString(":/images/option_menber") << QString(":/images/option_setting");

    QList<QString> optionStrList;
    optionStrList << QString("放大图片") << QString("登录账户") << QString("开通会员") << QString("基础设置");
    for (int i = 0; i < optionStrList.count(); ++i) {
        initItem(optionStrList[i], optionPixmapList[i]);
    }
    ui->option_list_widget->setCurrentRow(0);
    initView();

    ui->function_stack_widget->addWidget(new EnlargeWidget());

    ui->function_stack_widget->insertWidget(1, new AccountWidget());

    ui->function_stack_widget->insertWidget(2, new MenberWidget());

    ui->function_stack_widget->insertWidget(3, new SettingWidget());

//    connect(ui->option_list_widget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));
    connect(ui->option_list_widget,&QListWidget::pressed,[=](QModelIndex pos){
//        qDebug()<<"m_ListWidget pos.row:"<<pos.row();
        int optionIndex = pos.row();
        ui->function_stack_widget->setCurrentIndex(optionIndex);
        if (optionIndex == 0) {

        } else if (optionIndex == 1) {

        } else if (optionIndex == 2) {

        } else  {

        }
    });
}

widget::~widget()
{
    delete ui;
}

void widget::initView()
{
    QPixmap iconaaa(":/images/nav_icon");
    iconaaa = iconaaa.scaled(30, 30);
    ui->icon_label->setAlignment(Qt::AlignCenter);
    ui->icon_label->setPixmap(iconaaa);
    qDebug("%f", ui->icon_label->width());

    ui->min_btn->setStyleSheet("QToolButton{border-image:url(:/images/navi_min_icon) 0 0 42 0;}"
                                "QToolButton:hover{border-image:url(:/images/navi_min_icon) 14 0 28 0;}"
                                "QToolButton:pressed{border-image:url(:/images/navi_min_icon) 28 0 14 0;}"
                                "QToolButton:disabled{border-image:url(:/images/navi_min_icon) 42 0 0 0;}");

    ui->close_btn->setStyleSheet("QToolButton{border-image:url(:/images/navi_close_icon) 0 0 42 0;}"
                                    "QToolButton:hover{border-image:url(:/images/navi_close_icon) 14 0 28 0;}"
                                    "QToolButton:pressed{border-image:url(:/images/navi_close_icon) 28 0 14 0;}"
                                    "QToolButton:disabled{border-image:url(:/images/navi_close_icon) 42 0 0 0;}");

    ui->option_list_widget->setStyleSheet("QListWidget{outline:0px;border: none;background-color: transparent;}"
                                            "QListWidget::Item{background-color: #4586E4;}"
                                            "QListWidget::Item:hover{background-color: #3d7dd8; }"
                                            "QListWidget::item:selected{background-color: #2965BB;}");
}

void widget::initItem(const QString &str, const QString &picmap)
{
    QWidget *widget = new QWidget(ui->option_list_widget);

    //创建自定义的item
    widget->setStyleSheet("background:transparent;");

    QWidget *frontAreaA = new QWidget(widget);
    frontAreaA->setFixedWidth(14);

    QLabel *TypeLabel = new QLabel(widget);
    QPixmap myPix(picmap);
    TypeLabel->setFixedSize(18, 18);
    TypeLabel->setPixmap(myPix);
    TypeLabel->setScaledContents(true);

    QWidget *frontArea = new QWidget(widget);
    frontArea->setFixedHeight(20);

    QLabel *TotalCopyLabel = new QLabel(frontArea);
    TotalCopyLabel->setStyleSheet("font: normal normal 15px Microsoft YaHei;color: white;padding-left: 6px;");
    TotalCopyLabel->setText(str);

    QWidget *backArea = new QWidget(widget);
    backArea->setFixedSize(128, 50);

    QHBoxLayout *horLayout = new QHBoxLayout;
    horLayout->setContentsMargins(0, 0, 0, 0);
    horLayout->setMargin(0);
    horLayout->setSpacing(0);
    horLayout->addWidget(frontAreaA);
    horLayout->addWidget(TypeLabel);
    horLayout->addWidget(frontArea);
    widget->setLayout(horLayout);

    //将widget作为列表的item
    QListWidgetItem *ITEM = new QListWidgetItem();
    QSize size = ITEM->sizeHint();
    ITEM->setSizeHint(QSize(120, 50));
    ui->option_list_widget->addItem(ITEM);
    ui->option_list_widget->setItemWidget(ITEM, widget);
}

void widget::initItemWidget()
{
    //文字框高度
    const int textHight = 30;

    //生成图标对象
    QPixmap iconPixmap(24, 24);

    // 在图标上生成QPainter对象
    QPainter painter(&iconPixmap);

    // 设置画笔颜色
    painter.setPen(QColor(0, 0, 0));

    // 设置字体：SimSun、大小15
    QFont font;
    font.setFamily("SimSun");
    font.setPointSize(15);
    painter.setFont(font);

    // 定义文本框矩形
    const QRect rectangle = QRect(0, 0, 24, textHight);
    // 绘制文本
    painter.drawText(rectangle, Qt::AlignHCenter, QString("放大图片"));

    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 为单元项添加图标对象
    QListWidgetItem *pItem = new QListWidgetItem(QIcon(iconPixmap.scaled(QSize(24,24),Qt::KeepAspectRatio,Qt::SmoothTransformation)),QString("放大图片"));

    QListWidgetItem *pItem2 = new QListWidgetItem(QIcon(iconPixmap.scaled(QSize(24,24),Qt::KeepAspectRatio,Qt::SmoothTransformation)),QString("登录账号"));

    // 设置单元项的宽度和高度
    pItem->setSizeHint(QSize(24 ,24));
    pItem2->setSizeHint(QSize(24 ,24));
    ui->option_list_widget->insertItem(0, pItem);
    ui->option_list_widget->insertItem(1, pItem2);

}

void widget::itemClicked(QListWidgetItem *item)
{
    qDebug("d");
}



void widget::mousePressEvent(QMouseEvent *e)
{
    //鼠标左键
    if(e->button() == Qt::LeftButton)
    {
        m_ptPress = e->pos();
        qDebug() << pos() << e->pos() << m_ptPress;
        m_bPressed = m_areaMovable.contains(m_ptPress);
    }
}

void widget::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bPressed)
    {
        qDebug() << pos() << e->pos() << m_ptPress;
        move(pos() + e->pos() - m_ptPress);
    }
}

void widget::mouseReleaseEvent(QMouseEvent *e)
{
    m_bPressed = false;
}
