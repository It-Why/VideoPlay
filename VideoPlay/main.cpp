/**********************************************************
视频播放程序（调速）

Visual Studio 2015
OpenCV 3.0
Qt 5.8

By：Why
2017.10.14
**********************************************************/
#include "VideoPlay.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::codecForLocale();
    QApplication a(argc, argv);
    VideoPlay w;
    w.show();
    return a.exec();
}
