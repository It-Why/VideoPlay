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
    void closeEvent(QCloseEvent *event);//��д���ڹر���Ӧ����

private:
    void LabelDisplayMat(QLabel *label, cv::Mat &mat);//label��ʾMatͼ��
    void PlayVideo();

private slots:
    void OnButtonChooseVideo();//ѡ����Ƶ
    void OnSpeedChange(int iSpeed);//�����ٶȸı���Ӧ
    void OnButtonExit();//�˳���ť��Ӧ
    void OnButtonPlayPause();//������ͣ��ť

private:
    Ui::VideoPlayClass ui;
    int m_iSpeed;//�����ٶȣ���Ϊ���٣���Ϊ���٣�0Ϊ����ԭ��
    int m_iDelay;
    cv::VideoCapture m_video;
    cv::Mat m_frame;//���嵱ǰ����֡
    bool m_bPlay;

};
