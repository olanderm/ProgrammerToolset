#include "toolsetmain.h"
#include "./ui_toolsetmain.h"

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
