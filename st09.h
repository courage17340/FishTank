#ifndef st09_H
#define st09_H

#include "fish.h"
#include "cstdlib"


class st09:public fish{

    public:
    void init();

    void play();

    void revive(int&,int&);
    
    int assess(int, int);

    st09();

    ~st09();

};


#endif
