/********************************************************************************
** Form generated from reading UI file 'fishtank.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FISHTANK_H
#define UI_FISHTANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "tank.h"

QT_BEGIN_NAMESPACE

class Ui_FishTank
{
public:
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout;
    QWidget *centralWidget;
    QFrame *line;
    QFrame *line_2;
    Tank *widget;
    QTableWidget *tableWidget;
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QFrame *line_3;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QGroupBox *groupBox_4;
    QLabel *label_5;
    QGroupBox *groupBox_5;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuHelp;

    void setupUi(QMainWindow *FishTank)
    {
        if (FishTank->objectName().isEmpty())
            FishTank->setObjectName(QStringLiteral("FishTank"));
        FishTank->resize(1200, 650);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FishTank->sizePolicy().hasHeightForWidth());
        FishTank->setSizePolicy(sizePolicy);
        FishTank->setMinimumSize(QSize(1200, 650));
        FishTank->setMaximumSize(QSize(1200, 650));
        actionPlay = new QAction(FishTank);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        actionPause = new QAction(FishTank);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionExit = new QAction(FishTank);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(FishTank);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(FishTank);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(FishTank);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(620, -1, 3, 620));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 620, 1200, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget = new Tank(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 603, 603));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 15)
            tableWidget->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(630, 40, 560, 270));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(710, 10, 400, 30));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(660, 330, 120, 90));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 80, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 100, 16));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(620, 430, 580, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(660, 450, 280, 100));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 260, 70));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(810, 330, 380, 90));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 71, 61));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 20, 71, 61));
        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(210, 50, 160, 19));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 20, 161, 20));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(660, 560, 280, 51));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 240, 31));
        label_5->setAlignment(Qt::AlignCenter);
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(950, 450, 240, 160));
        lineEdit_2 = new QLineEdit(groupBox_5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 20, 80, 20));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 20, 60, 20));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 50, 60, 20));
        lineEdit_3 = new QLineEdit(groupBox_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 50, 80, 20));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 80, 60, 20));
        lineEdit_4 = new QLineEdit(groupBox_5);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(100, 80, 80, 20));
        pushButton_3 = new QPushButton(groupBox_5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 120, 100, 30));
        FishTank->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FishTank);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        FishTank->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionPlay);
        menuMenu->addAction(actionPause);
        menuMenu->addSeparator();
        menuMenu->addAction(actionExit);
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(FishTank);

        QMetaObject::connectSlotsByName(FishTank);
    } // setupUi

    void retranslateUi(QMainWindow *FishTank)
    {
        FishTank->setWindowTitle(QApplication::translate("FishTank", "Fish Tank 2.0", 0));
        actionPlay->setText(QApplication::translate("FishTank", "\345\274\200\345\247\213", 0));
        actionPause->setText(QApplication::translate("FishTank", "\346\232\202\345\201\234", 0));
        actionExit->setText(QApplication::translate("FishTank", "\351\200\200\345\207\272", 0));
        actionHelp->setText(QApplication::translate("FishTank", "\345\270\256\345\212\251", 0));
        actionAbout->setText(QApplication::translate("FishTank", "\345\205\263\344\272\216", 0));
#ifndef QT_NO_TOOLTIP
        widget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FishTank", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FishTank", "Author", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FishTank", "Status", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FishTank", "Score", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FishTank", "Lv", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("FishTank", "Exp", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("FishTank", "X", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("FishTank", "Y", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("FishTank", "HP", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("FishTank", "MaxHP", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("FishTank", "Att", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("FishTank", "Sp", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("FishTank", "Ar", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("FishTank", "Kill", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("FishTank", "Death", 0));
        label->setText(QApplication::translate("FishTank", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\346\216\222\350\241\214\346\246\234</span></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("FishTank", "\350\277\275\350\270\252\347\216\251\345\256\266", 0));
        label_2->setText(QApplication::translate("FishTank", "<html><head/><body><p align=\"center\">\350\276\223\345\205\245ID:</p></body></html>", 0));
        groupBox_2->setTitle(QApplication::translate("FishTank", "\345\275\223\345\211\215\347\216\251\345\256\266", 0));
        label_3->setText(QString());
        groupBox_3->setTitle(QApplication::translate("FishTank", "\346\216\247\345\210\266", 0));
        pushButton->setText(QApplication::translate("FishTank", "\345\274\200\345\247\213", 0));
        pushButton_2->setText(QApplication::translate("FishTank", "\346\232\202\345\201\234/\347\273\247\347\273\255", 0));
        label_4->setText(QApplication::translate("FishTank", "<html><head/><body><p align=\"center\">\351\200\237\345\272\246\346\216\247\345\210\266</p></body></html>", 0));
        groupBox_4->setTitle(QApplication::translate("FishTank", "\351\274\240\346\240\207\344\275\215\347\275\256", 0));
        label_5->setText(QString());
        groupBox_5->setTitle(QApplication::translate("FishTank", "\344\277\256\346\224\271\345\231\250", 0));
        label_6->setText(QApplication::translate("FishTank", "ID\357\274\232", 0));
        label_7->setText(QApplication::translate("FishTank", "\345\261\236\346\200\247\357\274\232", 0));
        label_8->setText(QApplication::translate("FishTank", "\345\217\230\345\214\226\344\270\272\357\274\232", 0));
        pushButton_3->setText(QApplication::translate("FishTank", "\347\214\233\345\207\273\344\277\256\346\224\271\357\274\201", 0));
        menuMenu->setTitle(QApplication::translate("FishTank", "\350\217\234\345\215\225", 0));
        menuHelp->setTitle(QApplication::translate("FishTank", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class FishTank: public Ui_FishTank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FISHTANK_H
