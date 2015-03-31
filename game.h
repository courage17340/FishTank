#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <cstdlib>

#include "constants.h"
#include "fish.h"
#include "ui_fishtank.h"

struct data{
    int Point,HP,maxHP,Att,Sp,Ar,Exp,Level,X,Y,Kill,Death,Score,Revive;
    bool Moved,Attacked,Dead;
    char identifier[20];
};

class fish;
class FishTank;

class host{
    
    friend void FishTank::on_pushButton_3_clicked();
    
private:
    
    int map[N + 1][M + 1],tot,list[MAX_PLAYER + 1],rank[MAX_PLAYER + 1];
    data player[MAX_PLAYER + 1];
    int abs(int) const;
    int max(int,int) const;
    void renewScore(int);
    void renewLevel(int);
    int damage(int,int) const;
    fish * a[MAX_PLAYER + 1], * b[MAX_PLAYER + 1];
    FishTank * ma;
    QString text;
    
public:

    int getPoint(int) const;
    int getLevel(int) const;
    int getExp(int) const;
    int getX(int) const;
    int getY(int) const;
    int getHP(int) const;
    int getMaxHP(int) const;
    int getAtt(int) const;
    int getSp(int) const;
    int getAr(int) const;
    int getID(int) const;
    int getTotalPlayer() const;
    int askWhat(int,int) const;
    int askHP(int) const;
    int askMaxHP(int) const;
    bool move(int,int,int);
    bool attack(int,int,int);
    bool increaseHealth(int);
    bool increaseStrength(int);
    bool increaseSpeed(int);
    bool increaseArmor(int);
    
//下面是系统的实现
    
    
    Ui::FishTank * ui;
    void init();
    void addFish(fish *);
    void begin();
    void refreshFood();
    bool cmp(int,int);
    void swap(int &,int &);
    void setUi(Ui::FishTank *);
    void renewSta(int,int);
    void renewRank1();
    bool cmp_s(int,int);
    void trans(int,char *);
    bool pause,played,end;
    void setMain(FishTank *);
    char * askName(int,int);
    
};


#endif // GAME_H
