#include "VideoPlay.h"
#include <qfiledialog.h>
#include <time.h>

VideoPlay::VideoPlay(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_iSpeed = 1;
    connect(ui.pushButton_ChooseVideo, SIGNAL(clicked()), this, SLOT(OnButtonChooseVideo()));
    connect(ui.spinBox_Speed, SIGNAL(valueChanged(int)), this, SLOT(OnSpeedChange(int)));
    connect(ui.pushButton_Exit, SIGNAL(clicked()), this, SLOT(OnButtonExit()));
}

void VideoPlay::OnButtonChooseVideo()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choose Video"), 
        "", 
        tr("Video Files (*.avi *.mp4 *.flv)"));
    if (fileName.size())
    {
        VideoCapture video(fileName.toStdString());
        if (video.isOpened())
        {
            int iFPS = video.get(CV_CAP_PROP_FPS);//获取视频帧率
            int iDelay = 1000 / iFPS;//计算每帧之间的延时
            Mat frame;//定义当前播放帧
            while (video.read(frame))//播放视频
            {
                imshow("VideoPlay", frame);
                //LabelDisplayMat(ui.label_VideoView, frame);
                waitKey(m_iSpeed < 0 ? iDelay * (-m_iSpeed + 1) : iDelay / (m_iSpeed + 1));//按设置的播放速度播放
                //delayMsec(iDelay);
            }
            video.release();
        }
        else
        {
            video.release();
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
}

void VideoPlay::delayMsec(int iMsec)
{
    clock_t now = clock();
    while (clock() - now < iMsec);
}

void VideoPlay::OnSpeedChange(int iSpeed)
{
    m_iSpeed = iSpeed;
}

void VideoPlay::OnButtonExit()
{
    destroyAllWindows();
    exit(0);
}
