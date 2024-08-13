#include "mindmap.h"
#include "ui_mindmap.h"

mindmap::mindmap(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mindmap)
{
    ui->setupUi(this);
}

mindmap::~mindmap()
{
    delete ui;
}
