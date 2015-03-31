#ifndef FISHTANK_H
#define FISHTANK_H

#include <QMainWindow>

#include "dialog.h"
#include "help.h"
#include "constants.h"

namespace Ui {
class FishTank;
}
class host;

class FishTank : public QMainWindow
{
    Q_OBJECT

public:
    
    explicit FishTank(QWidget *parent = 0,host * h = 0);
    ~FishTank();
    void setHost(host *);
    int delay;

private slots:

    void on_actionAbout_triggered();
    void on_actionHelp_triggered();
    void on_actionExit_triggered();
    void on_actionPlay_triggered();
    void on_actionPause_triggered();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_horizontalSlider_valueChanged(int);
    
public slots:
    
    void on_pushButton_3_clicked();
    
private:
    Ui::FishTank *ui;
    host * Host;
};

#endif // FISHTANK_H
