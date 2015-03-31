#ifndef TAAI_H
#define TAAI_H

#include "fish.h"
#include "cstdlib"


class TAAI:public fish{

    public:
    void init();

    void play();

    void revive(int&,int&);

    TAAI();

    ~TAAI();

};

//鍙嚜琛屽鍔犳墍闇€鍑芥暟鎵€闇€鍑芥暟鍙婂彉閲忥紝浣嗛渶淇濊瘉涓婇潰姣忎釜鍑芥暟鐨勫畬鏁翠笌鍙皟鐢?

//涓嶈浣跨敤鍏ㄥ眬鍙橀噺锛侊紒

#endif
