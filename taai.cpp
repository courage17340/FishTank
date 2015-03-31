#include "TAAI.h"
#include <cstdio>

using namespace std;

TAAI::TAAI()
{
    setIdentifier("TA_E");
}

TAAI::~TAAI() {}

void TAAI::init()
{
    increaseStrength();
    while(getPoint())
    {
        if(getPoint())increaseHealth();
        if(getPoint())increaseSpeed();
    }
}

void TAAI::play()
{
    while(getPoint())
    {
        if(getPoint())increaseHealth();
        if(getPoint())increaseSpeed();
    }
    int d=(~0U>>1),x,y;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            if(askWhat(i,j)==EMPTY)
            {
                int t1=abs(i-getX())+abs(j-getY());
                if(t1>getSp())continue;
                for(int k=1; k<=N; ++k)
                    for(int l=1; l<=M; ++l)
                        if(askWhat(k,l)!=EMPTY)
                        {
                            int tmp=abs(i-k)+abs(j-l);
                            if(tmp<d)d=tmp,x=i,y=j;
                        }
            }
    move(x,y);
    for(int i=-1; i<2; ++i)
        for(int j=-1; j<2; ++j)
        {
            if(i&&j)continue;
            if((!i)&&(!j))continue;
            if(askWhat(x+i,y+j)!=EMPTY)
            {
                attack(x+i,y+j);
                return;
            }
        }
}

void TAAI::revive(int& x,int& y) {}
