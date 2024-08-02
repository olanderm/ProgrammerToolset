#include "movie_player.h"
#include "ui_movie_player.h"
#include    <QFileDialog>
#include "mymainwindow.h"
movie_player::movie_player(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::movie_player)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);        //创建视频播放器
    QAudioOutput *audioOutput= new QAudioOutput(this);
    player->setAudioOutput(audioOutput);        //设置音频输出通道
    player->setVideoOutput(ui->videowidget);    //设置视频显示组件

    ui->videowidget->setMediaPlayer(player);//设置显示组件的关联播放器

    // connect(player,&QMediaPlayer::playbackStateChanged,this, &MainWindow::do_stateChanged);

    connect(player,&QMediaPlayer::positionChanged,this, &movie_player::do_positionChanged);

    // connect(player,&QMediaPlayer::durationChanged,this, &MainWindow::do_durationChanged);
}

movie_player::~movie_player()
{
    delete ui;
}

void movie_player::on_pushButton_play_clicked()
{
    QString curPath=QDir::homePath();
    QString dlgTitle="选择视频文件";
    QString filter="视频文件(*.wmv, *.mp4);;所有文件(*.*)";
    QString aFile=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);

    if (aFile.isEmpty())
        return;

    QFileInfo   fileInfo(aFile);
    player->setSource(QUrl::fromLocalFile(aFile));  //设置播放文件
    // 假设 player 是 QMediaPlayer 指针
    duration = player->duration();
    ui->horizontalSlider->setRange(0, duration);

    int   secs=duration/1000;   //秒
    int   mins=secs/60;         //分钟
    secs=secs % 60;             //余数秒

    durationTime=QString::asprintf("%d:%d",mins,secs);

   // qreal playbackRate = speed / 100.0;
    player->setPlaybackRate(1.5);


    player->play();
}


void movie_player::on_horizontalSlider_valueChanged(int value)
{
    player->setPosition(value);
}


void movie_player::on_pushButton_play_2_clicked(bool checked)
{
    if(checked)
    {
        player->pause();

    }
    else
    {
        player->play();
    }

}


void movie_player::on_pushButton_stop_clicked()
{
    player->stop();
}


void movie_player::on_pushButton_clicked(bool checked)
{

    if (checked) {
        this->showMaximized(); // 最大化子窗口
        ui->videowidget->setFullScreen(true);
    } else {
        this->showNormal(); // 恢复子窗口大小
    }

}

void movie_player::do_positionChanged(qint64 position)
{
    //文件播放位置变化
    if (ui->horizontalSlider->isSliderDown())
        return;     //如果正在拖动滑条，退出

    ui->horizontalSlider->setSliderPosition(position);
    int   secs=position/1000;   //秒
    int   mins=secs/60;         //分钟
    secs=secs % 60;             //余数秒
    QString positionTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(positionTime+"/"+durationTime);
}

