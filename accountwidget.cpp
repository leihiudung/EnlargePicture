#include "accountwidget.h"
#include "ui_accountwidget.h"
#include "retrievepasswordwidget.h"

AccountWidget::AccountWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountWidget)
{
    ui->setupUi(this);
    initView();
    connect(ui->eamil_edit, &QLineEdit::textChanged, [=](const QString &content){
        emailEditValuable = content.length() > 0 ? true : false;
        if (emailEditValuable && passwordEditValuable) {
            ui->register_login_btn->setEnabled(true);
            ui->register_login_btn->setStyleSheet("QPushButton{border: none;font: 12px Microsoft YaHei;color:white;background-color: #4586E4;width: 260px; height:36px;};");

        } else {
            ui->register_login_btn->setEnabled(false);
            ui->register_login_btn->setStyleSheet("QPushButton{border: none;font: 12px Microsoft YaHei;color:white;background-color: #CBD0DF;width: 260px; height:36px;};");
        }
    });
    connect(ui->password_edit, &QLineEdit::textChanged, [=](const QString &content){
        passwordEditValuable = content.length() > 0 ? true : false;
        if (emailEditValuable && passwordEditValuable) {
            qDebug("3");
            ui->register_login_btn->setEnabled(true);
            ui->register_login_btn->setStyleSheet("QPushButton{border: none;font: 12px Microsoft YaHei;color:white;background-color: #4586E4;width: 260px; height:36px;};");
        } else {
            qDebug("4");
            ui->register_login_btn->setEnabled(false);
            ui->register_login_btn->setStyleSheet("QPushButton{border: none;font: 12px Microsoft YaHei;color:white;background-color: #CBD0DF;width: 260px; height:36px;};");
        }
    });

    connect(ui->register_login_btn, &QPushButton::clicked, [=](){
        if (ui->register_checkbox->checkState() == Qt::Checked) {

        } else {
            emit loggedSignal();
        }
    });

    connect(ui->forget_password_btn, &QPushButton::clicked, [=](){
        RetrievePasswordWidget *widget = new RetrievePasswordWidget();
        widget->setWindowModality(Qt::ApplicationModal);
        widget->show();

    });

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

    ui->register_login_btn->setStyleSheet("QPushButton{border: none;font: 12px Microsoft YaHei;color:white;background-color: #CBD0DF;width: 260px; height:36px;};"
                                          "QPushButton:!enable{border: none;font: 16px Microsoft YaHei;color:white;background-color: #CBD0DF;width: 260px; height:36px;};");
    ui->register_login_btn->setCursor(QCursor(Qt::PointingHandCursor));
    ui->register_login_btn->setEnabled(false);
}
