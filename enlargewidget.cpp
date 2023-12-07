#include "enlargewidget.h"
#include "ui_enlargewidget.h"

EnlargeWidget::EnlargeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnlargeWidget)
{
    ui->setupUi(this);
}

EnlargeWidget::~EnlargeWidget()
{
    delete ui;
}
