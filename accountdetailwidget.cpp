#include "accountdetailwidget.h"
#include "ui_accountdetailwidget.h"
#include "enlargedetailitemwidget.h"
#include "resetpasswordwidget.h"

AccountDetailWidget::AccountDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountDetailWidget)
{
    ui->setupUi(this);
    initView();
    initView();

    connect(ui->edit_pwd_btn, &QPushButton::clicked, [=](){
        ResetPasswordWidget *pwdWidget = new ResetPasswordWidget();
        pwdWidget->setWindowModality(Qt::ApplicationModal);
        pwdWidget->show();
    });


}

AccountDetailWidget::~AccountDetailWidget()
{
    delete ui;
}

void AccountDetailWidget::initView()
{

    ui->edit_pwd_btn->setStyleSheet("QPushButton{background: transparent;"
                                    "border: none;width: 62px;height:28px;"
                                    "font:13px Microsoft YaHei;"
                                    "color: #4586E4;}");

    ui->logout_btn->setStyleSheet("QPushButton{background: white;"
                                    "border: none;width: 62px;height:28px;"
                                    "qproperty-icon: url(:/images/logout);"
                                    "font:13px Microsoft YaHei;"
                                    "color: #FF3A3A;}");


    ui->edit_pwd_btn->setCursor(QCursor(Qt::PointingHandCursor));
    ui->logout_btn->setCursor(QCursor(Qt::PointingHandCursor));

    EnlargeDetailItemWidget *itemWidget = new EnlargeDetailItemWidget(this);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(1, 62));
    ui->enlarge_list_widget->insertItem(0, item);
    ui->enlarge_list_widget->setItemWidget(item, itemWidget);


}
