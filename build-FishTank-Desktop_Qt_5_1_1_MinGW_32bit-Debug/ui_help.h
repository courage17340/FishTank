/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QPushButton *okButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QTextBrowser *textBrowser_2;
    QWidget *tab_3;
    QTextBrowser *textBrowser_3;
    QWidget *tab_4;
    QTextBrowser *textBrowser_4;
    QWidget *tab_5;
    QTextBrowser *textBrowser_5;
    QWidget *tab_6;
    QTextBrowser *textBrowser_6;

    void setupUi(QDialog *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QStringLiteral("Help"));
        Help->resize(450, 350);
        Help->setMinimumSize(QSize(450, 350));
        Help->setMaximumSize(QSize(450, 350));
        okButton = new QPushButton(Help);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(180, 300, 90, 30));
        tabWidget = new QTabWidget(Help);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 20, 391, 261));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 386, 241));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        textBrowser_2 = new QTextBrowser(tab_2);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 0, 386, 241));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        textBrowser_3 = new QTextBrowser(tab_3);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(0, 0, 386, 241));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        textBrowser_4 = new QTextBrowser(tab_4);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(0, 0, 386, 241));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        textBrowser_5 = new QTextBrowser(tab_5);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(0, 0, 386, 241));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        textBrowser_6 = new QTextBrowser(tab_6);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(0, 0, 386, 241));
        tabWidget->addTab(tab_6, QString());

        retranslateUi(Help);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QDialog *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "\345\270\256\345\212\251", 0));
        okButton->setText(QApplication::translate("Help", "\347\241\256\345\256\232", 0));
        textBrowser->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\205\263\344\272\216FishTank</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    FishTank\346\230\257\344\270\200\346\254\276\345\271\277\345\217\227ACM\347\217\255\345\260\217\344\274\231\344\274\264\346\254\242\350\277\216\357\274\214\350\200\201\345\260\221\345\222\270\345\256\234\347\232\204\346\210\230\346\227\227\347\261"
                        "\273\345\260\217\346\270\270\346\210\217\357\274\214\347\216\251\345\256\266\351\234\200\350\246\201\347\274\226\345\206\231AI\344\270\216\345\205\266\344\273\226\347\216\251\345\256\266\345\234\250\344\270\200\344\270\25240*40\347\232\204\346\243\213\347\233\230\344\270\212\344\275\234\346\210\230\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\205\263\344\272\216GUI</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; tex"
                        "t-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\257\217\344\270\252\347\216\251\345\256\266\347\224\250\344\270\200\344\270\252\345\234\206\350\241\250\347\244\272\357\274\214\346\240\271\346\215\256\347\224\237\345\221\275\345\200\274\345\241\253\345\205\205\346\255\244\345\234\206\357\274\214\345\217\246\345\244\226\347\224\237\345\221\275\345\200\274\351\253\230\344\272\21675%\346\227\266\344\270\272\350\223\235\350\211\262\357\274\214\351\253\230\344\272\21650%\346\227\266\344\270\272\347\264\253\350\211\262\357\274\214\351\253\230\344\272\21625%\346\227\266\344\270\272\346\251\231\350\211\262\357\274\214\345\220\246\345\210\231\344\270\272\347\272\242\350\211\262\357\274\210\351\242\234\350\211\262\344\270\216rating\346\227\240\345\205\263\357\274\211</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inden"
                        "t:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\260\264\350\227\273\347\224\250\347\273\277\350\211\262\346\226\271\345\235\227\350\241\250\347\244\272</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Help", "\347\256\200\344\273\213", 0));
        textBrowser_2->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\237\272\346\234\254\350\247\204\345\210\231</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\270\270\346\210\217\346\243\213\347\233\230\344\270\27240 * 40</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\270\270\346\210\217\350"
                        "\207\263\345\260\221\346\234\2111\344\270\252\347\216\251\345\256\266\357\274\214\350\207\263\345\244\232\346\234\21150\344\270\252\347\216\251\345\256\266\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \344\273\273\346\204\217\346\240\274\345\255\220\350\207\263\345\244\232\346\234\211\344\270\200\344\270\252\347\211\251\344\275\223(\347\216\251\345\256\266/\346\260\264\350\227\273)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:"
                        "0px;\">\346\270\270\346\210\217\347\233\256\347\232\204</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\270\270\346\210\217\350\277\233\350\241\214500\350\275\256\344\271\213\345\220\216\350\216\267\345\276\227\345\260\275\345\217\257\350\203\275\351\253\230\347\232\204\345\210\206\346\225\260</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin"
                        "-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\261\236\346\200\247\344\273\213\347\273\215</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    1.\347\224\237\345\221\275\345\200\274(HP)\357\274\232\347\216\251\345\256\266\345\275\223\345\211\215\347\224\237\345\221\275\345\200\274\357\274\214\344\270\2720\346\227\266\346\255\273\344\272\241\357\274\214\344\275\216\344\272\2160\346\227\266\345\274\272\345\210\266\347\275\256\344\270\2720</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    2.\347\224\237\345\221"
                        "\275\345\200\274\344\270\212\351\231\220(maxHP)\357\274\232\347\216\251\345\256\266\346\234\200\345\244\247\347\224\237\345\221\275\345\200\274\357\274\214\347\216\251\345\256\266\347\224\237\345\221\275\345\200\274\344\270\215\350\203\275\350\266\205\350\277\207\346\255\244\344\270\212\351\231\220</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    3.\346\224\273\345\207\273\345\212\233(Att)\357\274\232\347\216\251\345\256\266\346\224\273\345\207\273\345\210\253\344\272\272\347\232\204\350\203\275\345\212\233</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent"
                        ":0; text-indent:0px;\">    4.\346\212\244\347\224\262(Ar)\357\274\232\347\216\251\345\256\266\351\230\262\345\276\241\347\232\204\350\203\275\345\212\233</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    5.\351\200\237\345\272\246(Sp)\357\274\232\345\206\263\345\256\232\347\216\251\345\256\266\350\241\214\345\212\250\351\241\272\345\272\217\347\232\204\347\254\254\344\270\200\345\205\263\351\224\256\345\255\227\357\274\214\345\220\214\346\227\266\344\273\243\350\241\250\344\272\206\347\216\251\345\256\266\346\257\217\350\275\256\350\241\214\350\265\260\347\232\204\346\233\274\345\223\210\351\241\277\350\267\235\347\246\273\344\270\212\351\231\220</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-i"
                        "ndent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    6.\347\273\217\351\252\214\345\200\274(Exp)\357\274\232\345\206\263\345\256\232\347\216\251\345\256\266\347\255\211\347\272\247</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    7.\347\255\211\347\272\247(Level)\357\274\232\344\270\200\345\256\232\347\250\213\345\272\246\344\270\212\350\261\241\345\276\201\347\216\251\345\256\266\345\256\236\345\212\233\357\274\214\346\257\217\345\215\2071\347\272\247\346\227\266\350\216\267\345\276\2273\347\202\271\345\261\236\346\200\247\347\202\271</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    8.\345\261\236\346\200\247\347\202\271(Point)\357\274\232\347\216\251\345\256\266\350\207\252\347\224\261\346\224\257\351\205\215\357\274\2141\347\202\271\345\261\236\346\200\247\347\202\271\345\217\257\344\273\245\350\275\254\345\214\226\344\270\272\344\273\245\344\270\2134\350\200\205\344\271\213\344\270\200\357\274\2323 HP &amp; 3 maxHP\357\274\2332 Att\357\274\2331 Ar\357\274\2331 Sp</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    9.\346\235\200\344\272\272\346\225\260(Kill)\357\274\232\347\216\251\345\256\266\346\235\200\344\272\272\346\254\241\346\225\260</p>\n"
"<p style=\"-qt-paragraph-type:em"
                        "pty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    10.\350\242\253\346\235\200\346\254\241\346\225\260(Death)\357\274\232\347\216\251\345\256\266\346\255\273\344\272\241\346\254\241\346\225\260</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\260\264\350\227\273</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:"
                        "0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\224\273\345\207\273\345\220\216\346\266\210\345\244\261\357\274\214\347\216\251\345\256\266Exp++\357\274\214HP += max{1,maxHP / 4}</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\274\200\345\261\200</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px;"
                        " margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \350\275\275\345\205\245AI\345\220\216\347\273\231\346\257\217\344\270\252AI\345\210\206\351\205\215\344\270\200\344\270\252ID\357\274\21410\347\202\271\345\261\236\346\200\247\347\202\271\357\274\214\351\232\217\346\234\272\345\256\211\346\216\222AI\344\275\215\347\275\256\357\274\214\346\211\247\350\241\214\345\220\204AI\347\232\204\345\210\235\345\247\213\345\214\226\345\207\275\346\225\260\357\274\214\344\271\213\345\220\216\345\274\200\345\247\213\347\254\254\344\270\200\350\275\256\346\270\270\346\210\217</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200"
                        "\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">AI\345\210\235\345\247\213\345\214\226</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \345\277\205\351\241\273\344\277\235\350\257\201\345\242\236\345\212\240\350\277\207\351\231\244Ar\345\244\226\346\211\200\346\234\211\345\261\236\346\200\247</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200"
                        "\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\257\217\344\270\200\350\275\256</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \351\246\226\345\205\210\357\274\214\350\213\245\350\275\256\346\225\260\346\250\2415\344\275\2311\357\274\214\345\210\231\346\270\205\351\231\244\345\234\260\345\233\276\344\270\212\346\211\200\346\234\211\346\260\264\350\227\273\345\220\216\351\232\217\346\234\272\345\234\250\347\251\272\346\240\274\344\270\212\347\224\237\346\210\22050\344\270\252\346\260\264\350\227\273</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0"
                        "px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \347\204\266\345\220\216\357\274\214\345\205\250\345\234\272\345\255\230\346\264\273\347\216\251\345\256\266Exp++</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\234\200\345\220\216\357\274\214\345\206\263\345\256\232\350\241\214\345\212\250\351\241\272\345\272\217\345\271\266\344\276\235\346\254\241\350\277\233\350\241\214\346\270\270\346\210\217</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\">\344\274\244\345\256\263\346\234\272\345\210\266</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    damage = max{Att * 10 / (10 + Ar),1}</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\215\207\347\272\247\346\234\272\345\210\266</p>\n"
""
                        "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \345\215\207\345\210\260\347\254\254n\347\272\247\351\234\200\350\246\201\347\232\204\347\273\217\351\252\214\344\270\2722+3+\342\200\246\342\200\246+n</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\276\227\345\210\206\346\234\272\345"
                        "\210\266</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    Score = Exp + Kill * 5 - (Death ^ 2) / 5</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\241\214\345\212\250\351\241\272\345\272\217\345\206\263\347\255\226</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; "
                        "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">(+\350\241\250\347\244\272\346\225\260\345\200\274\350\266\212\345\244\247\350\266\212\345\205\210\350\241\214\345\212\250,-\345\217\215\344\271\213)</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \347\254\254\344\270\200\345\205\263\351\224\256\345\255\227\357\274\232Sp(+)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \347\254\254\344\272\214\345\205\263\351\224\256\345\255\227\357\274\232HP(-)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \347\254\254\344\270\211\345\205\263\351\224\256\345\255\227\357\274\232Level(-)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \347\254\254\345\233\233\345\205\263\351\224\256\345\255\227\357\274\232Score(-)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \347\254\254\344\272\224\345\205\263\351\224\256\345\255\227\357\274\232ID(+)</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342"
                        "\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\247\273\345\212\250</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \347\216\251\345\256\266\347\242\260\346\222\236\344\275\223\347\247\257\344\270\2720\357\274\214\345\217\252\350\246\201\347\233\256\346\240\207\347\202\271\344\270\216\350\207\252\345\267\261\351\227\264\347\232\204\346\233\274\345\223\210\351\241\277\350\267\235\347\246\273&lt;=Sp\345\210\231\345\217\257\344\273\245\345\211\215\345\276\200\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -"
                        "qt-block-indent:0; text-indent:0px;\">    \346\257\217\350\275\256\350\207\263\345\244\232\347\247\273\345\212\250\344\270\200\346\254\241\357\274\214\345\217\257\344\273\245\351\200\211\346\213\251\344\270\215\347\247\273\345\212\250</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\224\273\345\207\273</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; ma"
                        "rgin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \345\217\252\350\203\275\346\224\273\345\207\273\344\270\216\350\207\252\345\267\261\346\233\274\345\223\210\351\241\277\350\267\235\347\246\273\344\270\2721\347\232\204\346\240\274\345\255\220(\344\273\216\346\240\271\346\234\254\344\270\212\346\235\234\347\273\235\344\272\206\350\207\252\346\235\200\347\232\204\345\217\257\350\203\275\346\200\247)\357\274\214\350\213\245\346\224\273\345\207\273\347\232\204\346\230\257\347\216\251\345\256\266\357\274\214\344\270\224\345\257\271\346\226\271\350\242\253\346\235\200\346\255\273\345\210\231\350\207\252\345\267\261Kill++\357\274\214\345\257\271\346\226\271Death++\357\274\214\350\207\252\345\267\261\347\273\217\351\252\214 += \345\257\271\346\226\271Level / 2\357\274\214\350\213\245\350\207\252\345\267\261\347\255\211\347\272\247\344\275\216\344\272\216\345\257\271\346\226\271\345\210\231\351\242\235\345\244\226\345\242\236\345\212\240\347\255\211\347\272\247\345\267\256 * 3\347\232\204\347"
                        "\273\217\351\252\214</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \346\257\217\350\275\256\350\207\263\345\244\232\346\224\273\345\207\273\344\270\200\346\254\241\357\274\214\345\217\257\344\273\245\351\200\211\346\213\251\344\270\215\346\224\273\345\207\273\357\274\214\346\224\273\345\207\273\345\220\216\344\270\215\345\217\257\345\206\215\347\247\273\345\212\250</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\255\273\344\272\241"
                        "\344\270\216\345\244\215\346\264\273</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \350\242\253\347\216\251\345\256\266\346\235\200\346\255\273\345\220\216\357\274\214\347\253\213\345\215\263\350\242\253\347\247\273\345\207\272\345\234\260\345\233\276\357\274\214\350\267\263\350\277\207\344\270\213\344\270\244\346\254\241\350\241\214\345\212\250\357\274\214\347\254\2543\346\254\241\350\241\214\345\212\250\346\227\266\344\273\245max{maxHP / 2,2}\347\232\204HP\345\244\215\346\264\273\357\274\214\345\217\257\344\273\245\350\207\252\345\267\261\351\200\211\346\213\251\345\244\215\346\264\273\344\275\215\347\275\256\357\274\214\345\244\215\346\264\273\345\220\216\347\253\213\345\215\263\350\241\214\345\212\250</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Help", "\346\270\270\346\210\217\350\247\204\345\210\231", 0));
        textBrowser_3->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \344\270\272\344\272\206\346\226\271\344\276\277\350\277\275\350\270\252\350\207\252\345\267\261\347\232\204\357\274\210\346\210\226\350\200\205\345\210\253\344\272\272\347\232\204\357\274\211AI\357\274\214\347\211\271\346\267\273\345\212\240\346\234\254\345\212\237\350\203\275\343\200\202\345\217\252\350\246\201\350\276\223\345\205\245ID\345\215\263\345\217\257\350\277\275\350\270\252\357\274\214\347\256\200\345\215\225\343\200\201\346\226\271\344\276\277\343\200\201\345\256\236\347\224\250</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Help", "\350\277\275\350\270\252\347\224\250\346\210\267", 0));
        textBrowser_4->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\274\200\345\247\213 \345\222\214 \346\232\202\345\201\234/\347\273\247\347\273\255 \345\246\202\345\255\227\351\235\242\346\204\217\346\200\235</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\200\237\345\272\246\346\216\247\345\210\266\345\220\221\345\267\246\346\213\211\346\230\257\345\217\230\345\277\253\357\274\214"
                        "\345\220\221\345\217\263\346\213\211\346\230\257\345\217\230\346\205\242</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\246\345\244\226\344\271\237\345\217\257\344\273\245\344\275\277\347\224\250 \350\217\234\345\215\225 \351\207\214\351\235\242\347\232\204\346\216\247\345\210\266\345\221\275\344\273\244</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Help", "\346\216\247\345\210\266", 0));
        textBrowser_5->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\230\276\347\244\272\345\275\223\345\211\215\347\216\251\345\256\266\347\232\204\347\247\273\345\212\250\346\203\205\345\206\265\344\270\216\346\224\273\345\207\273\346\203\205\345\206\265\357\274\210\345\205\210\346\230\276\347\244\272\347\224\273\351\235\242\345\220\216\346\233\264\346\226\260\346\226\207\345\255\227\357\274\211</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; m"
                        "argin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\274\240\346\240\207\346\211\200\346\214\207\344\275\215\347\275\256\347\232\204\346\203\205\345\206\265\344\271\237\344\274\232\345\276\227\345\210\260\345\217\215\351\246\210</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Help", "\347\212\266\346\200\201", 0));
        textBrowser_6->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\276\223\345\205\245ID\357\274\214\345\261\236\346\200\247\345\220\215\347\247\260\357\274\210\345\277\205\351\241\273\344\270\245\346\240\274\347\255\211\344\272\216\345\257\271\347\205\247\350\241\250\344\270\255\347\232\204\345\255\227\347\254\246\344\270\262\357\274\211\357\274\214\350\277\230\346\234\211\346\224\271\345\217\230\345\220\216\347\232\204\345\200\274\357\274\210\345\277\205\351\241\273&lt;10,000,000)\357\274\214\347\202\271\345\207\273\346\214\211\351\222\256\345\215\263\345\217\257\344\277\256\346\224\271</p>\n"
"<p style=\"-qt-paragraph-type"
                        ":empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\246\345\244\226\344\277\256\346\224\271Exp\345\220\216\357\274\214\350\213\245Exp\345\215\207\351\253\230\345\210\231\344\274\232\345\215\207\347\272\247\357\274\214\350\213\245\351\231\215\344\275\216\345\210\231\347\255\211\347\272\247\347\273\264\346\214\201\344\270\215\345\217\230</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\257\271\347\205\247\350\241\250\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\261\236"
                        "\346\200\247\345\220\215\347\247\260	\346\234\200\345\260\217\345\200\274</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">HP	1</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">maxHP	1</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ar	0</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Att	1</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Sp	1</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Point	0</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Exp	1</p>\n"
""
                        "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\277\256\346\224\271\345\231\250\350\231\275\345\245\275\357\274\214\345\217\257\344\270\215\350\246\201\346\273\245\347\224\250\345\223\246</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("Help", "\344\277\256\346\224\271\345\231\250", 0));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
