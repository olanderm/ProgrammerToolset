#ifndef TOOLSETMAIN_H
#define TOOLSETMAIN_H

#include <QMainWindow>

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

private:
    Ui::ToolsetMain *ui;
};
#endif // TOOLSETMAIN_H
