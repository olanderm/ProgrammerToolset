#include "pclview.h"
#include "ui_pclview.h"

pclview::pclview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::pclview)
{
    ui->setupUi(this);
}

pclview::~pclview()
{
    delete ui;
}
