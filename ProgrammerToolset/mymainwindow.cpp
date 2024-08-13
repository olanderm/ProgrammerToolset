#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include "movie_player.h"
#include "pclview.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
    setWindowState(Qt::WindowMaximized);  //窗口最大化显示
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::on_actionVideo_toggled(bool arg1)
{

}

void MyMainWindow::on_actionVideo_triggered(bool checked)
{
    movie_player *formDoc = new movie_player(this);
    ui->mdiArea->addSubWindow(formDoc);     //文档窗口添加到MDI
    formDoc->show();    //在单独的窗口中显示
}

void MyMainWindow::on_pushButton_play_clicked()
{

}

void MyMainWindow::on_actionPCL_triggered()
{
    pclview *pcl = new pclview(this);
    ui->mdiArea->addSubWindow(pcl);
    pcl->show();
}

