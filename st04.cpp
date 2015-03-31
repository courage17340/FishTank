#include "st04.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

st04::st04()
{
     setIdentifier("Mars");
     srand(time(0));
}

st04::~st04() {}
void st04::init()
{
    DIE=0;
    memset(die,0,sizeof(die));
    increaseStrength();
    increaseHealth();
    increaseHealth();
    while (getPoint())increaseSpeed();
    success=fail=0;
}

void st04::work(int &X,int &Y)
{
    int z[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    
    for (int i=1;i<=100;i++)die[i]++;
    
    memset(f,0,sizeof(f));
    
    for (int i=1;i<=N;++i)
      for (int j=1;j<=M;++j)
        a[i][j]=askWhat(i,j)!=getID()?askWhat(i,j):0;
    
    for(int i=1; i<=N; ++i)
      for(int j=1; j<=M; ++j)
        if (a[i][j]>1)
        {
            die[a[i][j]]--;
            int Ar=max(getAr()+(getLevel()-(die[a[i][j]]-DIE>>1)/10)/10+1+(fail*4-success)/5,0);
            if (askHP(a[i][j])==1||askHP(a[i][j])<getAtt()*(1-Ar/(10.0+Ar)))
                f[i][j]=getLevel()-(die[a[i][j]]-DIE>>1)*10/getLevel();
            else f[i][j]=min(-(die[a[i][j]]-DIE>>1)*10/getLevel(),-1);
        }
        else if (a[i][j]==-1)f[i][j]=2;
    
    memset(g,130,sizeof(g));
    
    for (int i=1; i<=N; ++i)
      for (int j=1; j<=M; ++j)
        for (int k=0;k<4;k++)
          g[i][j]=max(g[i][j],f[i+z[k][0]][j+z[k][1]]);
    
    int max=-100000,x[1600],y[1600],s=0,xx,yy;
    memset(x,0,sizeof(x));memset(y,0,sizeof(y));
    
    for (int i=1;i<=N;++i)
      for (int j=1;j<=M;++j)
        if (abs(i-getX())+abs(j-getY())<=getSp()&&a[i][j]==0)
          if (g[i][j]>max)max=g[i][j],s=0,x[++s]=i,y[s]=j;
          else if (g[i][j]==max)x[++s]=i,y[s]=j;
    
    max=-100000;
    for (int ss=1;ss<=s;++ss)
    {
        int c=0;
        for (int i=1;i<=N;++i)
        for (int j=1;j<=M;++j)
          if (abs(x[ss]-i)+abs(y[ss]-j)<=getSp())
            if (f[i][j]>0)c++;
        if (c>=max)max=c,X=x[ss],Y=y[ss];
    }
 }

void st04::food(int&X,int&Y)
{
    for (int i=1;i<=N;++i)
      for (int j=1;j<=M;++j)
        a[i][j]=askWhat(i,j)!=getID()?askWhat(i,j):0;
    int z[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int s=0,x[1600],y[1600],max=-10000000;
    memset(x,0,sizeof(x));memset(y,0,sizeof(y));
    for (int i=1;i<=N;++i)
      for (int j=1;j<=M;++j)
        if (abs(i-getX())+abs(j-getY())<=getSp()&&a[i][j]==0)
        {
            for (int k=0;k<4;k++)
              if (a[i+z[k][0]][j+z[k][1]]==-1)
                x[++s]=i,y[s]=j;
        }
    if (s)
      for (int ss=1;ss<=s;ss++)
      {
          int S=0;
          for (int i=1;i<=N;++i)
            for (int j=1;j<=M;++j)
              if (abs(i-x[ss])+abs(j-y[ss])<=getSp())
                if (a[i][j]>0)S--;
                else if (a[i][j]<0)S++;
          if (S>max)max=S,X=x[ss],Y=y[ss];
      }
    else
      for (int ii=1;ii<=N;++ii)
        for (int jj=1;jj<=M;++jj)
          if (abs(ii-getX())+abs(jj-getY())<=getSp()&&a[ii][jj]==0)
        {
            int S=0;
            for (int i=1;i<=N;++i)
              for (int j=1;j<=M;++j)
                if (abs(i-ii)+abs(j-jj)<=getSp())
                  if (a[i][j]>0)S--;
                  else if (a[i][j]<0)S++;
            if (S>max)max=S,X=ii,Y=jj;
        }
}
bool st04::check()
{
    for (int i=1;i<=N;++i)
      for (int j=1;j<=M;++j)
        a[i][j]=askWhat(i,j)!=getID()?askWhat(i,j):0;
    int z[4][2]={{0,1},{0,-1},{1,0},{-1,0}},x=getX(),y=getY(),s=0;
    for (int i=0;i<4;i++)
      if (a[x+z[i][0]][y+z[i][1]]>0)s++;
    return s!=1;
 }
void st04::fight()
{
    int z[4][2]={{0,1},{0,-1},{1,0},{-1,0}},x=getX(),y=getY(),s=0;
    for (int i=0;i<4;i++)
      if (a[x+z[i][0]][y+z[i][1]]>0)attack(x+z[i][0],y+z[i][1]);
 }

void st04::play()
{
    int z[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int x,y,s=0,max;
    if (getHP()<=(getMaxHP()>>2)*3)
      if (check()||getAr()<=10)
        food(x,y);
      else fight();
    else work(x,y);
    move(x,y);
    if (getHP()<=(getMaxHP()>>2)*3)
    {
        int i;
        for (i=0;i<4;i++)
          if (a[getX()+z[i][0]][getY()+z[i][1]]==-1)break;
        if (i!=4)attack(getX()+z[i][0],getY()+z[i][1]);
        else
        {
            for (i=0;i<4;i++)
              if (a[getX()+z[i][0]][getY()+z[i][1]])s=i;
            attack(getX()+z[s][0],getY()+z[s][1]);
        }
    }
    else
    {
        max=0;
        for (int i=0;i<4;i++)
          if (f[x+z[i][0]][y+z[i][1]]>max)
            max=f[x+z[i][0]][y+z[i][1]],s=i;
        if (s==0)
          for (int i=0;i<4;i++)
            if (a[x+z[i][0]][y+z[i][1]])s=i;
        if (askWhat(x+z[s][0],y+z[s][1])>0)
        {
            attack(x+z[s][0],y+z[s][1]);
            if (f[x+z[s][0]][y+z[s][1]]>0)
              if (askWhat(x+z[s][0],y+z[s][1]))fail++;
              else success++;
        }
        else attack(x+z[s][0],y+z[s][1]);
    }
    
    if (getPoint())
    {
        if (getSp()<20)
        {
            increaseSpeed();
            if (getMaxHP()<60)increaseHealth();
            while (getPoint()&&getSp()<20)increaseSpeed();
        }
        while (rand()%3&&getMaxHP()<=60)
        if (getPoint())
          if (rand()%40>=9)increaseHealth();
          else increaseArmor();
        if (rand()%3)increaseStrength();
        if (getPoint()&&getSp()<40)
          if (rand()%4==0)increaseSpeed();
        if (rand()%12>=5)increaseStrength();
        while (getPoint())
          if (rand()%40>=9)increaseHealth();
          else increaseArmor();
    }
}

void st04::revive(int& X,int& Y)
{
     DIE+=2;
    for (int i=1;i<=N;++i)
      for (int j=1;j<=M;++j)
        a[i][j]=askWhat(i,j)!=getID()?askWhat(i,j):0;
    
     int z[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
     int s=0,x[1600],y[1600],max=-10000000;
     memset(x,0,sizeof(x));memset(y,0,sizeof(y));
     for (int i=1;i<=N;++i)
       for (int j=1;j<=M;++j)
         if (a[i][j]==0)
           for (int k=0;k<4;k++)
             if (a[i+z[k][0]][j+z[k][1]]==-1)
               x[++s]=i,y[s]=j;
     if (s)
       for (int ss=1;ss<=s;ss++)
       {
           int S=0;
           for (int i=1;i<=N;++i)
             for (int j=1;j<=M;++j)
               if (abs(i-x[ss])+abs(j-y[ss])<=getSp())
                 if (a[i][j]>0)S--;
                 else if (a[i][j]<0)S++;
           if (S>max)max=S,X=x[ss],Y=y[ss];
       }
     else
       for (int ii=1;ii<=N;++ii)
         for (int jj=1;jj<=M;++jj)
           if (a[ii][jj]==0)
           {
               int S=0;
               for (int i=1;i<=N;++i)
                 for (int j=1;j<=M;++j)
                   if (abs(i-ii)+abs(j-jj)<=getSp())
                     if (a[i][j]>0)S--;
                     else if (a[i][j]<0)S++;
               if (S>max)max=S,X=ii,Y=jj;
           }
}
