#include "fishtank.h"
#include "st01.h"
#include "st04.h"
#include "st09.h"
#include "st13.h"
#include "st18.h"
#include "TAAI.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    host H;
    H.init();
//Add AI here
    for (int i = 1;i <= 7;i++) H.addFish(new TAAI);
    for (int i = 1;i <= 1;i++) H.addFish(new st01);
    for (int i = 1;i <= 1;i++) H.addFish(new st04);
    for (int i = 1;i <= 1;i++) H.addFish(new st09);
    for (int i = 1;i <= 1;i++) H.addFish(new st13);
    for (int i = 1;i <= 1;i++) H.addFish(new st18);
    FishTank w(0,&H);
    w.show();
    return a.exec();
}
