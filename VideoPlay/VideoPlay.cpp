#include "VideoPlay.h"
#include <qfiledialog.h>
#include <time.h>
#include <Windows.h>

VideoPlay::VideoPlay(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_iSpeed = 1;
    m_bPlay = false;
    connect(ui.pushButton_ChooseVideo, SIGNAL(clicked()), this, SLOT(OnButtonChooseVideo()));
    connect(ui.spinBox_Speed, SIGNAL(valueChanged(int)), this, SLOT(OnSpeedChange(int)));
    connect(ui.pushButton_Exit, SIGNAL(clicked()), this, SLOT(OnButtonExit()));
    connect(ui.pushButton_PlayPause, SIGNAL(clicked()), this, SLOT(OnButtonPlayPause()));
}

void VideoPlay::OnButtonChooseVideo()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choose Video"), 
        "", 
        tr("Video Files (*.avi *.mp4 *.flv)"));
    if (fileName.size())
    {
        m_video.open(fileName.toStdString());
        if (m_video.isOpened())
        {
            int iFPS = m_video.get(CV_CAP_PROP_FPS);//获取视频帧率
            m_iDelay = 1000 / iFPS;//计算每帧之间的延时
            m_video.read(m_frame);
            LabelDisplayMat(ui.label_VideoView, m_frame);
            PlayVideo();
        }
        else
        {
            m_video.release();
        }
    }
}

void VideoPlay::closeEvent(QCloseEvent * event)
{
    OnButtonExit();
}

//参数1-显示图像的Label，参数2-要显示的Mat
void VideoPlay::LabelDisplayMat(QLabel *label, cv::Mat &mat)
{
    cv::Mat Rgb;
    QImage Img;
    if (mat.channels() == 3)//RGB Img
    {
        cv::cvtColor(mat, Rgb, CV_BGR2RGB);//颜色空间转换
        Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
    }
    else//Gray Img
    {
        Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
    }
    label->setPixmap(QPixmap::fromImage(Img));
    label->resize(Img.size());
    label->show();
    this->update();//刷新界面
}

void VideoPlay::PlayVideo()
{
    while (!m_frame.empty())//播放视频
    {
        imshow("VideoPlay", m_frame);
        cv::waitKey(m_iSpeed < 0 ? m_iDelay * (-m_iSpeed + 1) : m_iDelay / (m_iSpeed + 1));//按设置的播放速度播放
        if (m_bPlay)
        {
            m_video.read(m_frame);
        }
    }
    m_video.release();
}

void VideoPlay::OnSpeedChange(int iSpeed)
{
    m_iSpeed = iSpeed;
}

void VideoPlay::OnButtonExit()
{
    cv::destroyAllWindows();
    exit(0);
}

void VideoPlay::OnButtonPlayPause()
{
    if (ui.pushButton_PlayPause->text() == tr("Play"))
    {
        ui.pushButton_PlayPause->setText(tr("Pause"));
        m_bPlay = true;
    }
    else
    {
        ui.pushButton_PlayPause->setText(tr("Play"));
        m_bPlay = false;
    }
}
