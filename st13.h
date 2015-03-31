#ifndef _st13_H
#define _st13_H

#include "fish.h"
#include "cstdlib"


class st13:public fish{
	private:
		
		double dam[MAX_PLAYER + 1];
		int pt;

    public:
    
    void add();
    
    void init();

    void play();

    void revive(int&,int&);

    st13();

    ~st13();

};

//鍙嚜琛屽鍔犳墍闇€鍑芥暟鎵€闇€鍑芥暟鍙婂彉閲忥紝浣嗛渶淇濊瘉涓婇潰姣忎釜鍑芥暟鐨勫畬鏁翠笌鍙皟鐢?

//涓嶈浣跨敤鍏ㄥ眬鍙橀噺锛侊紒

#endif
