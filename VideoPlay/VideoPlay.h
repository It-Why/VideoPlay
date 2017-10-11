#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VideoPlay.h"

class VideoPlay : public QMainWindow
{
    Q_OBJECT

public:
    VideoPlay(QWidget *parent = Q_NULLPTR);

private:
    Ui::VideoPlayClass ui;
};
