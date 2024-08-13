#include "pclview.h"
#include "ui_pclview.h"
#include    <QFileDialog>
#include    <QDateTime>
#include    <QTemporaryDir>
#include    <QTemporaryFile>

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

void pclview::on_pushButton_clicked()
{
    QString curDir=QDir::currentPath();
    QString aFile=QFileDialog::getOpenFileName(this,"打开一个文件",curDir,"所有文件(*.*)");
    if(aFile.isEmpty())
    {
        return;
    }
}

