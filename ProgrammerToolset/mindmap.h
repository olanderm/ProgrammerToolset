#ifndef MINDMAP_H
#define MINDMAP_H

#include <QWidget>

namespace Ui {
class mindmap;
}

class mindmap : public QWidget
{
    Q_OBJECT

public:
    explicit mindmap(QWidget *parent = nullptr);
    ~mindmap();

private:
    Ui::mindmap *ui;
};

#endif // MINDMAP_H
