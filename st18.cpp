#include "st18.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
//需要估算经验，等级的函数
//暂时不还击
//无拦截水草功能，无抢人头
//凑热闹需改进 渣血区域的划定
st18::st18()
{
    output=false;
    setIdentifier("Chendy");//Your name herte
    add_risk=true;
    oo=999999999;
    aim=-1;
    round=0;
    hp_ar_point=0;
    idn=0;
    fx[0]=0;
    fx[1]=1;
    fx[2]=0;
    fx[3]=-1;
    fy[0]=1;
    fy[1]=0;
    fy[2]=-1;
    fy[3]=0;
    for (int i=1;i<=4;i++)
    for (int j=1;j<=4;j++)
    {
        int t=i*4-4+j;
        head[t].x=10*i-5;
        head[t].y=10*j-5;
    }
    memset(idq,0,sizeof(idq));
}
st18::~st18() {}
///////////////////////////////////////////////////////////
void st18::init()
{
    if (output)
    freopen("data.out","w",stdout);
    srand(time(NULL));
    increaseStrength();
    for (int i=1; i<=2; i++)
        increaseHealth();
    while (getPoint()) increaseSpeed();
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (askWhat(i,j)>0&&askWhat(i,j)!=getID())
            {
                int id=askWhat(i,j);
                idq[idn++]=id;
                en[id].maxhp_l=en[id].maxhp_r=max(3,askHP(id));
                en[id].hp=askHP(id);
                en[id].x=i;
                en[id].y=j;
            }
}
bool st18::is_dangerous()
{
    if (getHP()<=getMaxHP()*0.65) return true;
    bool is_beating=false;
    for (int k=0; k<4; k++)
        if (askWhat(getX()+fx[k],getY()+fy[k])>0)
        {
            if (getHP()<hprest) is_beating=true;
            en[askWhat(getX()+fx[k],getY()+fy[k])].dangerous_level+=1;
        }
    if (is_beating&&getHP()<=getMaxHP()*0.7) return true;
    return false;
}
bool st18::can_kill(int id,double gank_limit)
{
    return (kill_pb(id)+0.0)/(getAtt())<=gank_limit;
}
st18::point st18::in_battle()
{
    point ans;
    if (hprest>getHP())
    {
        for (int k=0; k<4; k++)
        {
            int id=askWhat(getX()+fx[k],getY()+fy[k]);
            if (id>0&&(ans.id==-1||en[id].att_l>en[ans.id].att_l))
            {
                ans.x=getX()+fx[k];
                ans.y=getY()+fy[k];
                ans.id=id;
            }
        }
    }
    return ans;
}
double st18::kill_pb(int id)
{
    if (askHP(id)<=3) return 3;
    else return askHP(id)*1.0*(10+min(en[id].ar_l,getAr()+2.0))/10.0;
}
inline int st18::dis(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
void st18::collect()
{
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (askWhat(i,j)>0&&askWhat(i,j)!=getID())
            {
                int id=askWhat(i,j);
                if (add_risk)
                {
                    en[id].sp_l=en[id].sp_r=max(en[id].sp_l,dis(i,j,en[id].x,en[id].y));
                }
                en[id].maxhp_l=en[id].maxhp_r=max(en[id].maxhp_l,((askHP(id)+2)/3)*3);
                en[id].x=i;
                en[id].y=j;
            }
    if (add_risk) //预测攻击
        for (int k=1; k<=idn; k++)
        {
            if (askHP(idq[k])<en[idq[k]].hp)
            {
                int cnt=0;
                for (int i=0; i<4; i++)
                    if (askWhat(en[idq[k]].x+fx[i],en[idq[k]].y+fy[i])>0) cnt++;
                if (cnt==1)
                {
                    for (int i=0; i<4; i++)
                        if (askWhat(en[idq[k]].x+fx[i],en[idq[k]].y+fy[i])>0)
                        {
                            int tid=askWhat(en[idq[k]].x+fx[i],en[idq[k]].y+fy[i]);
                            en[tid].dangerous_level++;
                            en[tid].att_l=max(en[tid].att_l,(en[idq[k]].hp-askHP(idq[k]))*(10+en[idq[k]].ar_l)/10.0);
                            break;
                        }
                }
            }
            en[idq[k]].hp=askHP(idq[k]);
        }
    if (round==0) //初始预测
    {
        for (int k=1; k<=idn; k++)
            if (askHP(idq[k])>3)
                en[idq[k]].att_l=max(2,2*(10-(askHP(idq[k])+2)/3-5));
            else en[idq[k]].att_l=16;
    }
}
void st18::risking()//考察地图上的危险情况 simple edit
{
    memset(risk,0,sizeof(risk));
    memset(fat,0,sizeof(fat));
    memset(chance,0,sizeof(chance));
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (askWhat(i,j)==EMPTY)
            {
                fat[i][j]=1;
                risk[i][j]=1;
                chance[i][j]=1e-10;
                for (int k=1; k<=N; k++)
                    for (int l=1; l<=M; l++)
                        if (dis(i,j,k,l)<=getSp()&&askWhat(k,l)>0&&askWhat(k,l)!=getID())
                        {
                            int id=askWhat(k,l);
                            risk[i][j]+=en[id].dangerous_level*en[id].att_l/(1.0*max(1,((dis(i,j,k,l)+getSp()-1)/getSp())));
                        }
                for (int k=1; k<=N; k++)
                    for (int l=1; l<=M; l++)
                        if (askWhat(k,l)>0&&askWhat(k,l)!=getID())
                        {
                            int id=askWhat(k,l);
                            if (can_kill(id,gank_limit))
                                chance[i][j]+=1.0/kill_pb(id)/(0.1+dis(i,j,k,l));
                        }
                //////////////////肥沃度
                for (int k=1; k<=N; k++)
                    for (int l=1; l<=M; l++)
                        if (askWhat(k,l)==FOOD)
                        {
                            fat[i][j]+=1.0/(1.0*max(1,((dis(i,j,k,l)+getSp()-1)/getSp())));
                        }
            }
}
void st18::head_map()
{
        ///////////人头分布图
    for (int i=1;i<=4;i++)
    for (int j=1;j<=4;j++)
    {
        int t=i*4-4+j;
        head[t].id=0;
        for (int k=i*10-9;k<=i*10;k++)
        for (int l=j*10-9;l<=j*10;l++)
        if (askWhat(k,l)>0&&askWhat(k,l)!=getID()&&kill_pb(askWhat(k,l))<=1.7)
        {
            head[t].id++;
        }
    }
}
void st18::att(int x,int y)
{
    if (askWhat(x,y)<=0) attack(x,y);
    else
    {
        int id=askWhat(x,y);
        double thp=askHP(id);
        attack(x,y);
        thp-=askHP(id);
        en[id].ar_l=en[id].ar_r=max(en[id].ar_l,(getAtt()-thp)*10.0/thp);
    }
}
void st18::increaseHP_AR()
{
    hp_ar_point++;
    if (getLevel()<=20)
    {
        if (hp_ar_point%5||getAr()>=getLevel()/4)increaseHealth();
        else increaseArmor();
    }
    else if (getLevel()<=40)
    {
        if (getLevel()%4==0) increaseArmor();
        else increaseHealth();
    }
    else
    {
        if (getLevel()%4==0) increaseArmor();
        else increaseHealth();
    }
}
void st18::increase()
{
    double max_att=0,min_hp=oo,sp_limit=0;
    for (int k=1; k<=idn; k++)
        if (idq[k]!=getID())
        {
            min_hp=min(min_hp,0.0+askHP(idq[k])*(10+en[idq[k]].ar_l)/10.0);
            sp_limit=max(sp_limit,0.0+en[idq[k]].sp_l+3);
            max_att=max(max_att,en[idq[k]].att_l);
        }
    sp_limit=min(sp_limit,60.0);
    sp_limit=max(sp_limit,getLevel()/2.0);
    if (getLevel()==2)
    {
        increaseSpeed();
        increaseHP_AR();
        increaseHP_AR();
    }
    else if (getLevel()==3)
    {
        increaseSpeed();
        increaseSpeed();
        increaseHP_AR();
    }
    else if (getLevel()==4)
    {
        increaseHP_AR();
        increaseSpeed();
        increaseSpeed();
    }
    else if (getLevel()==5)
    {

        increaseSpeed();
        increaseSpeed();
        increaseHP_AR();

    }
    else if (getLevel()==6)
    {
        increaseHP_AR();
        increaseHP_AR();
        increaseHP_AR();
    }
    else if (getLevel()<=15)
    {
        increaseStrength();
        if (getLevel()%2)
            increaseStrength();
        else increaseHP_AR();
        if (max(max_att*4,max(3*getLevel()+0.0,min_hp))+1>getMaxHP()*(10.0+getAr())/10.0) increaseHP_AR();
        else increaseStrength();
    }
    else
    {
        increaseStrength();
        increaseHP_AR();
        if (getLevel()%2==0&&getSp()<sp_limit) increaseSpeed();
        else
        {
            if (getLevel()%5)
                increaseStrength();
            else increaseHP_AR();
        }
    }
}
void st18::search_map()
{
    memset(around_enemy,0,sizeof(around_enemy));
    memset(around_grass,0,sizeof(around_grass));
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (askWhat(i,j)==EMPTY)
            {
                for (int k=0; k<4; k++)
                {
                    if (askWhat(i+fx[k],j+fy[k])>0) around_enemy[i][j][askWhat(i+fx[k],j+fy[k])]=true;
                    if (askWhat(i+fx[k],j+fy[k])==FOOD) around_grass[i][j]=true;
                }
            }
}
st18::point st18::find_head()
{
    point ans;
    int maxn=-1,pos=-1;
    for (int i=1;i<=16;i++)
    if (head[i].id>maxn)
    {
        maxn=head[i].id;
        pos=i;
    }
    ans=head[pos];
    if (ans.id==0)
    {
        ans.x=1;
        ans.y=1;
        ans.id=41;
    }
    return ans;
}
st18::point st18::search_easy_to_kill(int x,int y,int l)
{
    point ans;
    double minn=1e50;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if ((askWhat(i,j)==EMPTY||askWhat(i,j)==getID())&&dis(x,y,i,j)<=l)
            {
                for (int k=0; k<4; k++)
                {
                    int id=askWhat(i+fx[k],j+fy[k]);
                    if (id>0&&id!=getID())
                    {
                        if (kill_pb(id)<minn)
                        {
                            minn=kill_pb(id);
                            ans.x=i;
                            ans.y=j;
                            ans.id=id;
                        }
                    }
                }
            }
    return ans;
}
st18::point st18::search_grass(int x,int y,int l)
{
    point ans;
    double maxn=-1e50;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if ((askWhat(i,j)==EMPTY||askWhat(i,j)==getID())&&dis(x,y,i,j)<=l)
            {
                for (int k=0; k<4; k++)
                    if (askWhat(i+fx[k],j+fy[k])==FOOD)
                    {
                        if ((fat[i][j]/risk[i][j])>maxn)
                        {
                            maxn=(fat[i][j]/risk[i][j]);
                            ans.x=i;
                            ans.y=j;
                            ans.id=0;
                        }
                        break;
                    }
            }
    return ans;
}
void st18::defence() //补给&逃逸
{
    aim=-1;
    point tmp=search_grass(getX(),getY(),getSp());
    if (in_battle().x!=-1&&tmp.x!=-1)
    {
        point tmp2=in_battle();
        point ans;
        double maxn=-1e50;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=M; j++)
                if ((askWhat(i,j)==EMPTY||askWhat(i,j)==getID())&&dis(getX(),getY(),i,j)<=getSp())
                {
                    for (int k=0; k<4; k++)
                        if (askWhat(i+fx[k],j+fy[k])==FOOD)
                        {
                            if (dis(i,j,tmp2.x,tmp2.y)>maxn)
                            {
                                maxn=dis(i,j,tmp2.x,tmp2.y);
                                ans.x=i;
                                ans.y=j;
                                ans.id=0;
                            }
                            break;
                        }
                }
        move(ans.x,ans.y);
        for (int k=0; k<4; k++)
            if (askWhat(ans.x+fx[k],ans.y+fy[k])==FOOD)
            {
                att(ans.x+fx[k],ans.y+fy[k]);
                return;
            }
    }
    else if (tmp.x!=-1)
    {
        move(tmp.x,tmp.y);
        for (int k=0; k<4; k++)
            if (askWhat(tmp.x+fx[k],tmp.y+fy[k])==FOOD)
            {
                att(tmp.x+fx[k],tmp.y+fy[k]);
                return;
            }
    }
    else if (in_battle().x==-1)
    {
        double maxn=-1e50;
        point ans;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=M; j++)
                if (askWhat(i,j)==EMPTY&&dis(getX(),getY(),i,j)<=getSp())
                {
                    if ((fat[i][j]/risk[i][j])>maxn)
                    {
                        maxn=(fat[i][j]/risk[i][j]);
                        ans.x=i;
                        ans.y=j;
                    }
                }
        move(ans.x,ans.y);
    }
    else
    {
        double maxn=-1e50;
        point tmp=in_battle();
        point ans;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=M; j++)
                if (askWhat(i,j)==EMPTY&&dis(getX(),getY(),i,j)<=getSp())
                {
                    if ((fat[i][j]/risk[i][j])*dis(getX(),getY(),tmp.x,tmp.y)>maxn)
                    {
                        maxn=(fat[i][j]/risk[i][j])*dis(getX(),getY(),tmp.x,tmp.y);
                        ans.x=i;
                        ans.y=j;
                    }
                }
        move(ans.x,ans.y);
    }
}
void st18::gank(int id)
{
    point tmp=search_easy_to_kill(getX(),getY(),getSp());
    aim=tmp.id;
    if (tmp.x!=getX()||tmp.y!=getY())
        move(tmp.x,tmp.y);
    att(en[tmp.id].x,en[tmp.id].y);
}
void st18::fun_gank()
{
    point tmp=search_grass(getX(),getY(),getSp());
    point tmp1=find_head();
    point tmp2=search_easy_to_kill(getX(),getY(),getSp());
    point ans;
    double minn=1e50;
    int t=oo;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if ((askWhat(i,j)==EMPTY||askWhat(i,j)==getID())&&dis(getX(),getY(),i,j)<=getSp())
            {
                int dist=dis(i,j,tmp1.x,tmp1.y);
                for (int k=0; k<4; k++)
                {
                    int id=askWhat(i+fx[k],j+fy[k]);
                    if (id>0&&getID()!=id)
                    {
                        if (((dist+getSp()-1)/getSp()<t)||((dist+getSp()-1)/getSp()==t&&kill_pb(id)*pow(dist,3)<minn))
                        {
                            t=(dist+getSp()-1)/getSp();
                            minn=kill_pb(id)*pow(dist,3);
                            ans.x=i;
                            ans.y=j;
                            ans.id=id;
                        }
                    }
                }
            }
    if (ans.x!=getX()||ans.y!=getY())
        move(ans.x,ans.y);
    att(en[ans.id].x,en[ans.id].y);
}
void st18::fun_feed()
{
    point tmp=search_grass(getX(),getY(),getSp());
    point tmp1=find_head();
    point tmp2=search_easy_to_kill(getX(),getY(),getSp());
    point ans;
    double maxn=-1e50;
    int t=oo;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if ((askWhat(i,j)==EMPTY||askWhat(i,j)==getID())&&dis(getX(),getY(),i,j)<=getSp())
            {
                for (int k=0; k<4; k++)
                    if (askWhat(i+fx[k],j+fy[k])==FOOD)
                    {
                        int dist=dis(i,j,tmp1.x,tmp1.y);
                        if (((dist+getSp()-1)/getSp()<t)||((dist+getSp()-1)/getSp()==t&&(fat[i][j]/risk[i][j])/(0.1+pow(dist,3))>maxn))
                        {
                            t=(dist+getSp()-1)/getSp();
                            maxn=(fat[i][j]/risk[i][j])/(0.1+pow(dist,3));
                            ans.x=i;
                            ans.y=j;
                            ans.id=0;
                        }
                        break;
                    }
            }
    if (ans.x!=getX()||ans.y!=getY())
        move(ans.x,ans.y);
    for (int k=0; k<4; k++)
        if (askWhat(ans.x+fx[k],ans.y+fy[k])==FOOD)
        {
            att(ans.x+fx[k],ans.y+fy[k]);
            break;
        }
}
void st18::join_the_fun()
{
    point tmp=search_grass(getX(),getY(),getSp());
    point tmp1=find_head();
    point tmp2=search_easy_to_kill(getX(),getY(),getSp());
    bool cd=true;
    if (getLevel()>10&&(tmp1.id!=41)&&dis(getX(),getY(),tmp1.x,tmp1.y)>getSp()+5&&((getLevel()/3)>(dis(getX(),getY(),tmp1.x,tmp1.y)+getSp()-1)/getSp()))
    {
        cd=false;
        point ans;
        double maxn=-1e50;
        int t=oo;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=M; j++)
                if ((askWhat(i,j)==EMPTY||askWhat(i,j)==getID())&&dis(getX(),getY(),i,j)<=getSp())
                {
                    int dist=dis(i,j,tmp1.x,tmp1.y);
                    if (((dist+getSp()-1)/getSp()<t)||((dist+getSp()-1)/getSp()==t&&fat[i][j]/risk[i][j]/(pow(dist,3)+0.1)>maxn))
                    {
                        t=(dist+getSp()-1)/getSp();
                        maxn=fat[i][j]/risk[i][j]/(pow(dist,3)+0.1);
                        ans.x=i;
                        ans.y=j;
                        ans.id=0;
                    }
                }
        if ((tmp.x!=-1&&dis(ans.x,ans.y,tmp.x,tmp.y)<=5)||(tmp2.x!=-1&&dis(ans.x,ans.y,tmp2.x,tmp2.y)<=5))
        {
            cd=true;
        }
        else
        {
            if (ans.x!=getX()||ans.y!=getY())
            move(ans.x,ans.y);
            for (int k=0; k<4; k++)
            if (askWhat(ans.x+fx[k],ans.y+fy[k])==FOOD)
            {
                att(ans.x+fx[k],ans.y+fy[k]);
                break;
            }
        }
    }
    if (!cd) return;
    if (getLevel()<=10)
    {
        if (tmp.x!=-1)
        {
            cd=false;
            fun_feed();
        }
        else if (tmp2.x!=-1)
        {
            cd=false;
            fun_gank();
        }
    }
    else
    {
        if (tmp2.x!=-1)
        {
            cd=false;
            fun_gank();
        }
        else if (tmp.x!=-1)
        {
            cd=false;
            fun_feed();
        }
    }
    if (cd)
    {
        point ans;
        double maxn=-1e50;
        int t=oo;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=M; j++)
                if ((askWhat(i,j)==EMPTY||askWhat(i,j)==getID())&&dis(getX(),getY(),i,j)<=getSp())
                {
                    int dist=dis(i,j,tmp1.x,tmp1.y);
                    if (((dist+getSp()-1)/getSp()<t)||((dist+getSp()-1)/getSp()==t&&fat[i][j]/risk[i][j]/(pow(dist,3)+0.1)>maxn))
                    {
                        t=(dist+getSp()-1)/getSp();
                        maxn=fat[i][j]/risk[i][j]/(pow(dist,3)+0.1);
                        ans.x=i;
                        ans.y=j;
                        ans.id=0;
                    }
                }
        if (ans.x!=getX()||ans.y!=getY())
            move(ans.x,ans.y);
    }
}
void st18::play()
{
    collect();
    risking();
    increase();
    search_map();
    point tmp=search_grass(getX(),getY(),getSp());
    point tmp1=in_battle();
    point tmp2=search_easy_to_kill(getX(),getY(),getSp());
    point tmp3=find_head();
    if (output)
    {
        printf("round=%d action: find_head: %d %d %d\n",round,tmp3.x,tmp3.y,tmp3.id);
        printf("round=%d action: grass: %d %d %d\n",round,tmp.x,tmp.y,tmp.id);
        printf("round=%d action: kill: %d %d %d %.2lf\n",round,tmp2.x,tmp2.y,tmp2.id,kill_pb(tmp2.id));
    }
    double g_limit=1+log(log(getLevel()));
    gank_limit=g_limit;
    if (getLevel()<=8) gank_limit*=0.7;
    if (add_risk)
    {
        if (!is_dangerous()&&((tmp2.x!=-1)&&can_kill(tmp2.id,0.95)))
        {
            gank(tmp2.id);
            if (output)
            printf("round=%d action: gank1\n",round);
        }
        else if (is_dangerous()||getLevel()<=8)
        {
            defence();
            if (output)
            printf("round=%d action: defence\n",round);
        }
        else if (((tmp2.x!=-1)&&can_kill(tmp2.id,(getLevel()<=15)?max(1.0,gank_limit):2)))
        {
            gank(tmp2.id);
            if (output)
            printf("round=%d action: gank1\n",round);
        }
        else
        {
            if (tmp2.x==-1)
            {
                join_the_fun();
                if (output)
                printf("round=%d action: jf1\n",round);
            }
            else if (dis(getX(),getY(),tmp3.x,tmp3.y)>getSp()&&tmp3.id>0)
            {
                join_the_fun();
                if (output)
                printf("round=%d action: jf2\n",round);
            }
            else //if ((tmp2.x!=-1)&&can_kill(tmp2.id,gank_limit))
            {
                if (can_kill(tmp2.id,gank_limit))
                {
                    gank(tmp2.id);
                    if (output)
                    printf("round=%d action: gank2\n",round);
                }
                else
                {
                    join_the_fun();
                    if (output)
                    printf("round=%d action: jf3\n",round);
                }
            }
        }
    }
    else
    {
        if (aim==-1) defence();
        else gank(aim);
    }
    /////////////////////////
    add_risk=true;
    increase();
    hprest=getHP();
    round++;
}
void st18::revive(int& x,int& y)
{
    round+=2;
    add_risk=false;
    hprest=min(2,(int)(0.25*getMaxHP()));
    aim=-1;
    point ans=search_easy_to_kill(0,0,100);
    if (ans.x!=-1&&can_kill(ans.id,0.9))
    {
        aim=ans.id;
        x=ans.x;
        y=ans.y;
    }
    else
    {
        ans=search_grass(0,0,100); //复活补血方式待改进
        if (ans.x!=-1)
        {
            x=ans.x;
            y=ans.y;
        }
        else
        {
            int minn=oo;
            point ans;
            ans.x=getX();
            ans.y=getY();
            ans.id=-1;
            for (int i=1; i<=N; i++)
                for (int j=1; j<=M; j++)
                    if (askWhat(i,j)==EMPTY)
                    {
                        if (risk[i][j]<minn)
                        {
                            minn=risk[i][j];
                            ans.x=i;
                            ans.y=j;
                        }
                    }
            x=ans.x;
            y=ans.y;
        }
    }
}
