#include "toolsetmain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolsetMain w;
    w.show();
    return a.exec();
}
