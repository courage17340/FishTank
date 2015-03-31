#ifndef st04_H
#define st04_H

#include "fish.h"
#include "cstdlib"

class st04:public fish{
    int DIE,die[100],a[N+5][M+5],f[N+5][M+5],g[N+5][M+5],success,fail;

    public:
    void init();

    void play();

    void revive(int&,int&);

    void work(int&,int&);
    bool check();
    void fight();
    void food(int&,int&);
    void FAIL();
    st04();

    ~st04();

};

//可自行增加所需函数所需函数及变量，但需保证上面每个函数的完整与可调用

//不要使用全局变量！！

#endif
