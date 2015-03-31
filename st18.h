#ifndef st18_H
#define st18_H

#include "fish.h"
#include "cstdlib"


class st18:public fish{

    public:
    void init();

    void play();

    void revive(int&,int&);

    st18();

    ~st18();
    private:
    struct point
    {
        int x,y,id;
        point()
        {
            x=y=id=-1;
        }
    }q[3010],head[100];
    struct enemy
    {
        int level_l,level_r;
        int maxhp_l,maxhp_r,hp;
        int sp_l,sp_r;
        double ar_l,ar_r;
        double att_l,att_r;
        double dangerous_level;
        int x,y;
        enemy()
        {
            level_l=level_r=1;
            maxhp_l=maxhp_r=3;
            sp_l=sp_r=1;
            ar_l=ar_r=0;
            att_l=att_r=2;
            dangerous_level=1;
            hp=1;
            x=y=0;
        }
    }en[MAX_PLAYER+110];
    bool is_dangerous();
    bool can_kill(int,double);
    void increaseHP_AR();
    double kill_pb(int);
    int dis(int,int,int,int);
    void gank(int);
    void defence();
    void join_the_fun();
    void fun_gank();
    void fun_feed();
    void collect();
    void risking();
    void increase();
    void search_map();
    void head_map();
    void att(int,int);
    point find_head();
    point search_easy_to_kill(int,int,int);
    point search_grass(int,int,int);
    point in_battle();
    bool output;
    bool add_risk;
    bool around_grass[N+10][M+10];
    bool around_enemy[N+10][M+10][MAX_PLAYER+10];
    int round,ganklevel,hprest;
    int idq[MAX_PLAYER+100],idn;
    bool exist[MAX_PLAYER+100];
    double risk[N+10][M+10];
    double fat[N+10][M+10];
    double chance[N+10][M+10];
    int fx[4],fy[4];
    int nq,oo,times,aim,hp_ar_point;
    double gank_limit;
};

//可自行增加所需函数所需函数及变量，但需保证上面每个函数的完整与可调用

//不要使用全局变量！！

#endif
