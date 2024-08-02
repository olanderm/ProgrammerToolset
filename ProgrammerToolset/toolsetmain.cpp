#include "toolsetmain.h"
#include "./ui_toolsetmain.h"
#include    <QFileDialog>
#include    <QDateTime>
#include "movie_player.h"

ToolsetMain::ToolsetMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ToolsetMain)
{
    ui->setupUi(this);
}

ToolsetMain::~ToolsetMain()
{
    delete ui;
}

void ToolsetMain::on_actionNew_triggered()
{

}


void ToolsetMain::on_actionOpen_triggered()
{
    //打开文件
    QString curDir=QDir::currentPath();
    QString aFile=QFileDialog::getOpenFileName(this,"打开一个文件",curDir,"所有文件(*.jpg)");

    if(aFile.isEmpty())
    {
        return;
    }

    // 创建一个 QGraphicsScene
    QGraphicsScene *scene = new QGraphicsScene(this);
    // 创建一个 QPixmapItem 并将其添加到场景中
    QPixmap pixmap(aFile);

    // 创建一个QLabel并设置图片

    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
    scene->addItem(pixmapItem);

    // 设置场景大小与图片大小一致
    scene->setSceneRect(pixmap.rect());

    // 创建一个 QGraphicsView，并将其设置为显示该场景
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); // 启用抗锯齿
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform); // 启用平滑变换
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag); // 启用拖动模式
    ui->graphicsView->fitInView(pixmap.rect(), Qt::KeepAspectRatio); //auto fit.

}



void ToolsetMain::on_pushButton_3_clicked()
{
    ui->graphicsView->rotate(-90);
}


void ToolsetMain::on_pushButton_clicked()
{
    ui->graphicsView->rotate(90);
}


void ToolsetMain::on_pushButton_zoomin_clicked()
{
   const double scaleFactor = 1.15;
    ui->graphicsView->scale(scaleFactor, scaleFactor);
}


void ToolsetMain::on_pushButton_zoomout_clicked()
{
    const double scaleFactor = 1.15;
    ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
}


void ToolsetMain::on_pushButton_2_clicked()
{
    // 检查 graphicsView 是否有一个有效的场景
    if (!ui->graphicsView->scene()) {
        return; // 返回一个空的 QPixmap
    }

    // 获取场景中的所有项
    QList<QGraphicsItem*> items = ui->graphicsView->scene()->items();

    // 遍历项并查找 QGraphicsPixmapItem
    for (QGraphicsItem *item : items) {
        QGraphicsPixmapItem *pixmapItem = dynamic_cast<QGraphicsPixmapItem*>(item);
        if (pixmapItem) {
            // 返回找到的 pixmap
            QPixmap mapbuff =  std::move(pixmapItem->pixmap());

            // 将图像转换为灰度
            QImage image = mapbuff.toImage();  // 将 QPixmap 转换为 QImage
            QImage grayImage = image.convertToFormat(QImage::Format_Grayscale8);  // 转换为灰度图像

            // 将灰度图像转换回 QPixmap
            QPixmap grayPixmap = QPixmap::fromImage(grayImage);

            // 创建一个 QGraphicsScene
            QGraphicsScene *scene = new QGraphicsScene(this);

            // 创建一个 QGraphicsPixmapItem 并将其添加到场景中
            QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(grayPixmap);
            scene->addItem(pixmapItem);

            // 设置场景大小与图片大小一致
            scene->setSceneRect(grayPixmap.rect());

            // 设置 QGraphicsView 以显示该场景
            ui->graphicsView->setScene(scene);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);          // 启用抗锯齿
            ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform); // 启用平滑变换
            ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);     // 启用拖动模式
            ui->graphicsView->fitInView(grayPixmap.rect(), Qt::KeepAspectRatio);  // 自动适应
        }
    }

}


void ToolsetMain::on_actionMoive_Player_toggled(bool arg1)
{

}


void ToolsetMain::on_actionMoive_Player_triggered(bool checked)
{
    movie_player *videoView = new movie_player(this);       //指定主窗口为父容器
    videoView->setAttribute(Qt::WA_DeleteOnClose);  //关闭时自动删除



}
