#include "st01.h"
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

st01::st01()
{
    setIdentifier("Juda");//Your name here
    memset(predict,-1,sizeof predict);
}

st01::~st01() {}

void st01::init()
{
    for(int i=1;i<=3;++i)increaseHealth();
    for(int i=1;i<=6;++i)increaseSpeed();
    increaseStrength();
    srand(time(0));
}

void st01::play()
{
    int ID,x,y,Now,Res1,Res2,HPTemp,Temp;
    if(getPoint())contributionPoint();
    x=getX();y=getY();
    findBestGrad(x,y,getSp(),x,y);
    move(x,y);
    Now=-1;Res1=x;Res2=y;
    if((Temp=subGetGradValue(x-1,y))>Now)
    {
        Now=Temp;
        Res1=x-1;
        Res2=y;
    }
    if((Temp=subGetGradValue(x+1,y))>Now)
    {
        Now=Temp;
        Res1=x+1;
        Res2=y;
    }
    if((Temp=subGetGradValue(x,y-1))>Now)
    {
        Now=Temp;
        Res1=x;
        Res2=y-1;
    }
    if((Temp=subGetGradValue(x,y+1))>Now)
    {
        Now=Temp;
        Res1=x;
        Res2=y+1;
    }
    ID=askWhat(Res1,Res2);
    if(ID>0)HPTemp=askHP(ID);
    attack(Res1,Res2);
    if(ID>0 && ID==askWhat(Res1,Res2))
    {
        predict[ID]=armorPredict(HPTemp,askHP(ID));
    }
}

void st01::revive(int& x,int& y)
{
    int t1,t2,i,j,res,now=0;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(askWhat(i-1,j)==FOOD || askWhat(i+1,j)==FOOD || askWhat(i,j-1)==FOOD || askWhat(i,j+1)==FOOD)
            {
                res=123456;
                for(t1=1;t1<=N;t1++)
                {
                    for(t2=1;t2<=M;t2++)
                    {
                        if(askWhat(t1,t2)>0)
                        {
                            res=min(res,abs(t1-i)+abs(t2-j));
                        }
                    }
                }
                if(res>now)
                {
                    now=res;
                    x=i;
                    y=j;
                }
            }
        }
    }
}


void st01::contributionPoint()
{
    int Level;
    Level=getLevel();
    if(Level<=10)
    {
        increaseHealth();
        if(randInt(1,2)==1)increaseArmor();else increaseHealth();
        if(randInt(1,2)==1)increaseSpeed();else increaseStrength();
        return;
    }else
    {
        if(getAr()>30 && getHP()>200)increaseStrength();
        if(getSp()<40 && randInt(1,2)==2)increaseSpeed();
        if(randInt(1,4)==1)increaseHealth();else increaseStrength();
        switch (randInt(1,5))
        {
            case 1:increaseSpeed();break;
            case 2:increaseArmor();break;
            default : increaseStrength();
        }
        if(randInt(1,3)==1)increaseArmor();else increaseHealth();
    }
}

int st01::armorPredict(int InitialHP,int NowHP)
{
    int MyAtt,Harm,Temp;
    MyAtt=getAtt();
    Harm=NowHP-InitialHP;
    Temp=1-Harm/(double)MyAtt;
    return (int)(-10*Temp/(double)(Temp-1));
}

void st01::findBestGrad(int Xaid,int Yaid,int Radius,int &Res1,int &Res2)
{
    int NowValue=-1,TEMP;
    Res1=Xaid;
    Res2=Yaid;
    for(int i=max(1,Xaid-Radius);i<=min(N,Xaid+Radius);++i)
    {
        for(int j=max(1,Yaid-Radius);j<=min(M,Yaid+Radius);++j)
        {
            if(abs(i-Xaid)+abs(j-Yaid)<=Radius && askWhat(i,j)==EMPTY)
            {
                TEMP=getGradValue(i,j);
                if(TEMP>NowValue)
                {
                    NowValue=TEMP;
                    Res1=i;Res2=j;
                }
            }
        }
    }
}

int st01::getGradValue(int x,int y)
{
    return max(max(max(subGetGradValue(x-1,y),subGetGradValue(x+1,y)),subGetGradValue(x,y-1)),subGetGradValue(x,y+1));
}

int st01::distanceOther(int x,int y)
{
    int res=1000,temp;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            temp=askWhat(i,j);
            if(temp>0 && temp!=getID())
            {
                temp=askHP(temp);
                res=min(res,temp+(abs(i-x)+abs(j-y))*2);
            }
        }
    }
    return (int)(500*(max(1,1000-res)/1000.));
}

int st01::subGetGradValue(int x,int y)
{
    if(askWhat(x,y)==INVALID_VALUE || askWhat(x,y)==getID())return -1;
    int Value=-1;
    if(getAtt()>80)
    {
        if(askWhat(x,y)==FOOD)
        {
            if(getHP()<=getMaxHP()*0.65+1e-6)Value=max(Value,4100+distanceOther(x,y));else Value=max(Value,1500+distanceOther(x,y));
        }else
        {
            int ID,playHP,MyAtt;
            ID=askWhat(x,y);
            if(ID>0)
            {
                playHP=askHP(ID);
                MyAtt=getAtt();
                if(predict[ID]==-1)
                {
                    if(MyAtt*9/10>=playHP)Value=max(Value,randInt(2400,3000));else Value=max(Value,randInt(800,1300));
                }else
                {
                    double ArmorModify=1-predict[ID]/(10+predict[ID]);
                    if(MyAtt*ArmorModify>=playHP)Value=max(Value,randInt(3500,5000));else Value=max(Value,randInt(1400,1600));
                }
            }
        }
    }else
    {
        if(askWhat(x,y)==FOOD)
        {
            if(getHP()<=getMaxHP()*0.75+1e-6)Value=max(Value,4500+distanceOther(x,y));else Value=max(Value,2000+distanceOther(x,y));
        }else
        {
            int ID,playHP,MyAtt;
            ID=askWhat(x,y);
            if(ID>0)
            {
                playHP=askHP(ID);
                MyAtt=getAtt();
                if(predict[ID]==-1)
                {
                    if(MyAtt*8/10>=playHP)Value=max(Value,randInt(2500,2800));else Value=max(Value,randInt(800,1500));
                }else
                {
                    double ArmorModify=1-predict[ID]/(10+predict[ID]);
                    if(MyAtt*ArmorModify>=playHP)Value=max(Value,randInt(2900,3500));else Value=max(Value,randInt(1500,2200));
                }
            }
        }
    }
    return max(distanceOther(x,y),Value);
}

int st01::randInt(int x,int y)
{
    return rand()%(y-x+1)+x;
}
