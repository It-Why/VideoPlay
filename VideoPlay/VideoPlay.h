#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VideoPlay.h"
#include <opencv2/opencv.hpp>

using namespace std;

class VideoPlay : public QMainWindow
{
    Q_OBJECT

public:
    VideoPlay(QWidget *parent = Q_NULLPTR);
    void closeEvent(QCloseEvent *event);//重写窗口关闭响应函数

private:
    void LabelDisplayMat(QLabel *label, cv::Mat &mat);//label显示Mat图像
    void PlayVideo();

private slots:
    void OnButtonChooseVideo();//选择视频
    void OnSpeedChange(int iSpeed);//播放速度改变响应
    void OnButtonExit();//退出按钮响应
    void OnButtonPlayPause();//播放暂停按钮

private:
    Ui::VideoPlayClass ui;
    int m_iSpeed;//播放速度，负为降速，正为提速，0为保持原速
    int m_iDelay;
    cv::VideoCapture m_video;
    cv::Mat m_frame;//定义当前播放帧
    bool m_bPlay;

};
