#include <QThread>

#include "fishtank.h"
#include "ui_fishtank.h"
#include "game.h"

FishTank::FishTank(QWidget *parent,host * h) :
    QMainWindow(parent),
    ui(new Ui::FishTank),
    Host(h)
{
    ui->setupUi(this);
    ui->widget->setHost(Host);
    ui->widget->setUi(ui);
    int wid[15] = {25,60,40,45,25,40,25,25,40,50,40,25,25,30,40};
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int i = 0;i < 15;i++) ui->tableWidget->setColumnWidth(i,wid[i]);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    Host->setMain(this);
    ui->horizontalSlider->setValue(40);
    delay = 40;
}

FishTank::~FishTank()
{
    delete ui;
}

void FishTank::setHost(host * p){
    Host = p;
}

void FishTank::on_actionAbout_triggered(){
    Dialog d;
    d.exec();
}

void FishTank::on_actionHelp_triggered(){
    Help h;
    h.exec();
}

void FishTank::on_actionExit_triggered(){
    if (!Host->played) this->close();else Host->end = 1;
}

void FishTank::on_actionPlay_triggered(){
    Host->setUi(ui);
    Host->begin();
}

void FishTank::on_actionPause_triggered(){
    Host->pause ^= 1;
}

void FishTank::on_pushButton_clicked()
{
    Host->setUi(ui);
    Host->begin();
}

void FishTank::on_pushButton_2_clicked()
{
    Host->pause ^= 1;
}

void FishTank::on_horizontalSlider_valueChanged(int value)
{
    delay = value * 5;
}

void FishTank::on_pushButton_3_clicked(){
    QString s = ui->lineEdit_2->text();
    bool f;
    int id = s.toInt(&f);
    if (!f || id < 1 || id > Host->getTotalPlayer()) return;
    s = ui->lineEdit_4->text();
    int x = s.toInt(&f);
    if (!f || f < 0 || f > 1e7) return;
    s = ui->lineEdit_3->text();
    if (s == "Ar") Host->player[id].Ar = x;
    else if (s == "Att" && x > 0) Host->player[id].Att = x;
    else if (s == "HP" && x > 0){
        Host->player[id].HP = x;
        if (Host->player[id].HP > Host->player[id].maxHP) Host->player[id].HP = Host->player[id].maxHP;
    }else if (s == "maxHP" && x > 0){
        Host->player[id].maxHP = x;
        if (Host->player[id].HP > Host->player[id].maxHP) Host->player[id].HP = Host->player[id].maxHP;
    }else if (s == "Sp" && x > 0) Host->player[id].Sp = x;
    else if (s == "Exp" && x > 0){
        Host->player[id].Exp = x;
        Host->renewLevel(id);
    }else if (s == "Point") Host->player[id].Point = x;
    int k = 0;
    while (Host->rank[k + 1] != id) k++;
    Host->renewSta(id,k);
}
