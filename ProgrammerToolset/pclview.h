#ifndef PCLVIEW_H
#define PCLVIEW_H

#include <QWidget>

namespace Ui {
class pclview;
}

class pclview : public QWidget
{
    Q_OBJECT

public:
    explicit pclview(QWidget *parent = nullptr);
    ~pclview();

private:
    Ui::pclview *ui;
};

#endif // PCLVIEW_H
