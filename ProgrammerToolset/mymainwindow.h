#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

private slots:
    void on_actionVideo_toggled(bool arg1);

    void on_actionVideo_triggered(bool checked);

    void on_pushButton_play_clicked();

    void on_actionPCL_triggered();

private:
    Ui::MyMainWindow *ui;
};

#endif // MYMAINWINDOW_H
