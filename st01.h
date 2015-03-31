#ifndef st01_H
#define st01_H

#include "fish.h"
#include "cstdlib"


class st01:public fish{

    private:
        int predict[MAX_PLAYER+1];

        int armorPredict(int,int);//护甲推断
        void contributionPoint();//属性点分配
        void findBestGrad(int,int,int,int&,int&);
        int getGradValue(int,int);
        int randInt(int,int);
        int subGetGradValue(int,int);
        int distanceOther(int,int);

    public:
        void init();

        void play();

        void revive(int&,int&);

        st01();

        ~st01();

};

//可自行增加所需函数所需函数及变量，但需保证上面每个函数的完整与可调用

//不要使用全局变量！！

#endif
