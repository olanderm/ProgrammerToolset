#ifndef MOVIE_PLAYER_H
#define MOVIE_PLAYER_H

#include <QWidget>
#include    "tmyvideowidget.h"

namespace Ui {
class movie_player;
}

class movie_player : public QWidget
{
    Q_OBJECT

public:
    explicit movie_player(QWidget *parent = nullptr);
    ~movie_player();

private slots:
    void on_pushButton_play_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_play_2_clicked(bool checked);

    void on_pushButton_stop_clicked();

    void on_pushButton_clicked(bool checked);
    void do_positionChanged(qint64 position);

private:
    Ui::movie_player *ui;
     QMediaPlayer  *player;  //视频播放器
    qint64 duration;
     QString durationTime;
};

#endif // MOVIE_PLAYER_H
