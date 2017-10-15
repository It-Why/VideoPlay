#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VideoPlay.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class VideoPlay : public QMainWindow
{
    Q_OBJECT

public:
    VideoPlay(QWidget *parent = Q_NULLPTR);
    void closeEvent(QCloseEvent *event);

private:
    void LabelDisplayMat(QLabel *label, cv::Mat &mat);
    void delayMsec(int iMsec);//延时毫秒

private slots:
    void OnButtonChooseVideo();
    void OnSpeedChange(int iSpeed);
    void OnButtonExit();

private:
    Ui::VideoPlayClass ui;
    int m_iSpeed;//播放速度
};
