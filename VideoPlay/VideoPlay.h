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
    void closeEvent(QCloseEvent *event);//重写窗口关闭响应函数

private:
    void LabelDisplayMat(QLabel *label, cv::Mat &mat);//label显示Mat图像
    void delayMsec(int iMsec);//延时毫秒

private slots:
    void OnButtonChooseVideo();//选择视频
    void OnSpeedChange(int iSpeed);//播放速度改变响应
    void OnButtonExit();//退出按钮响应

private:
    Ui::VideoPlayClass ui;
    int m_iSpeed;//播放速度，负为降速，正为提速，0为保持原速
};
