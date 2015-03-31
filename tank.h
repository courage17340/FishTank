#ifndef TANK_H
#define TANK_H

#include <QPainter>
#include <cmath>
#include <QMouseEvent>

#include "fishtank.h"

class host;

class Tank :public QWidget{
    
    Q_OBJECT

public:

    Tank(QWidget * parent = 0);
    ~Tank();
    void setHost(host *);
    void setUi(Ui::FishTank *);
    void mouseMoveEvent(QMouseEvent *ev);
    void enterEvent(QEvent *);
    
private:
    
    int type,map[N + 1][M + 1];
    void draw(int,int,int,QPainter &);
    host * cmp;
    Ui::FishTank * ui;
    
protected:
    
    void paintEvent(QPaintEvent *);
    
signals:  
    
    void customMouseMoveEvent(int x,int y);
    
private slots:
    
    void showxy(int,int);
    
};

#endif
