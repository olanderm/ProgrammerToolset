#ifndef TOOLSETMAIN_H
#define TOOLSETMAIN_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
class ToolsetMain;
}
QT_END_NAMESPACE

class ToolsetMain : public QMainWindow
{
    Q_OBJECT

public:
    ToolsetMain(QWidget *parent = nullptr);
    ~ToolsetMain();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_zoomin_clicked();

    void on_pushButton_zoomout_clicked();

    void on_pushButton_2_clicked();

    void on_actionMoive_Player_toggled(bool arg1);

    void on_actionMoive_Player_triggered(bool checked);

private:
    Ui::ToolsetMain *ui;
    QWidget *videoView;


};
#endif // TOOLSETMAIN_H
