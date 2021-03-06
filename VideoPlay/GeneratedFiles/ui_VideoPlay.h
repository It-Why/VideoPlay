/********************************************************************************
** Form generated from reading UI file 'VideoPlay.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAY_H
#define UI_VIDEOPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPlayClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_VideoView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_ChooseVideo;
    QPushButton *pushButton_PlayPause;
    QHBoxLayout *horizontalLayout;
    QLabel *label_SpeedMod;
    QSpinBox *spinBox_Speed;
    QPushButton *pushButton_Exit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VideoPlayClass)
    {
        if (VideoPlayClass->objectName().isEmpty())
            VideoPlayClass->setObjectName(QStringLiteral("VideoPlayClass"));
        VideoPlayClass->resize(536, 419);
        centralWidget = new QWidget(VideoPlayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_VideoView = new QLabel(centralWidget);
        label_VideoView->setObjectName(QStringLiteral("label_VideoView"));
        label_VideoView->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_VideoView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_ChooseVideo = new QPushButton(centralWidget);
        pushButton_ChooseVideo->setObjectName(QStringLiteral("pushButton_ChooseVideo"));

        horizontalLayout_2->addWidget(pushButton_ChooseVideo);

        pushButton_PlayPause = new QPushButton(centralWidget);
        pushButton_PlayPause->setObjectName(QStringLiteral("pushButton_PlayPause"));

        horizontalLayout_2->addWidget(pushButton_PlayPause);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_SpeedMod = new QLabel(centralWidget);
        label_SpeedMod->setObjectName(QStringLiteral("label_SpeedMod"));
        label_SpeedMod->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_SpeedMod);

        spinBox_Speed = new QSpinBox(centralWidget);
        spinBox_Speed->setObjectName(QStringLiteral("spinBox_Speed"));
        spinBox_Speed->setMinimum(-10);
        spinBox_Speed->setMaximum(10);

        horizontalLayout->addWidget(spinBox_Speed);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        pushButton_Exit = new QPushButton(centralWidget);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));

        verticalLayout_2->addWidget(pushButton_Exit);

        verticalLayout_2->setStretch(0, 6);
        verticalLayout_2->setStretch(1, 2);
        verticalLayout_2->setStretch(2, 2);
        verticalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(verticalLayout_2);

        VideoPlayClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VideoPlayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 536, 23));
        VideoPlayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VideoPlayClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VideoPlayClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VideoPlayClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VideoPlayClass->setStatusBar(statusBar);

        retranslateUi(VideoPlayClass);

        QMetaObject::connectSlotsByName(VideoPlayClass);
    } // setupUi

    void retranslateUi(QMainWindow *VideoPlayClass)
    {
        VideoPlayClass->setWindowTitle(QApplication::translate("VideoPlayClass", "VideoPlay", Q_NULLPTR));
        label_VideoView->setText(QApplication::translate("VideoPlayClass", "VideoView", Q_NULLPTR));
        pushButton_ChooseVideo->setText(QApplication::translate("VideoPlayClass", "ChooseVideo", Q_NULLPTR));
        pushButton_PlayPause->setText(QApplication::translate("VideoPlayClass", "Play", Q_NULLPTR));
        label_SpeedMod->setText(QApplication::translate("VideoPlayClass", "SpeedMod:", Q_NULLPTR));
        pushButton_Exit->setText(QApplication::translate("VideoPlayClass", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayClass: public Ui_VideoPlayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAY_H
