#include "menberwidget.h"
#include "ui_menberwidget.h"

MenberWidget::MenberWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenberWidget)
{
    ui->setupUi(this);
}

MenberWidget::~MenberWidget()
{
    delete ui;
}
