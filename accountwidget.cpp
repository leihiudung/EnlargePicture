#include "accountwidget.h"
#include "ui_accountwidget.h"

AccountWidget::AccountWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountWidget)
{
    ui->setupUi(this);
    initView();
}

AccountWidget::~AccountWidget()
{
    delete ui;
}

void AccountWidget::initView()
{
    ui->eamil_edit->setPlaceholderText(QString("  请输入邮箱"));
    ui->password_edit->setPlaceholderText(QString("  请输入密码"));
    ui->register_checkbox->setText(QString("注册一个新用户"));
    ui->forget_password_btn->setText(QString("忘记密码?"));
    ui->register_login_btn->setText(QString("登陆/注册"));

    ui->eamil_edit->setStyleSheet("QLineEdit{background: #FCFDFF;border: 1px solid #C0C6D9;"
                                  "width:260px;height:36px;font: 12px Microsoft YaHei; };");

    ui->password_edit->setStyleSheet("QLineEdit{background: #FCFDFF;border: 1px solid #C0C6D9;"
                                     "width:260px;height:36px;font: 12px Microsoft YaHei; };");

    ui->forget_password_btn->setStyleSheet("QPushButton{border: none;font: 12px Microsoft YaHei; color:#4586E4;text-align: right;};");

    ui->register_login_btn->setStyleSheet("QPushButton{border: none;font: 12px Microsoft YaHei;color:white;background: #CBD0DF;"
                                          "width: 260px; height:36px;};");
}
