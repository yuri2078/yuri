#include <iostream>
#include "Solider.h"
#include "Gun.h"

int main(int argc, char **argv)
{
    Gun *gun = new Gun(100);
    Solider *solider = new Solider("yuri", gun);
    cout << "当前有" << solider->gun->buttle << "个子弹" << endl;
    solider->fire();
    cout << "当前有" << solider->gun->buttle << "个子弹" << endl;
    solider->gun->addButtle(2);
    cout << "当前有" << solider->gun->buttle << "个子弹" << endl;
    return 0;
}