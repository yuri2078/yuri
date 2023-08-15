#include "Solider.h"

Solider::Solider(string name, Gun *gun)
{
    this->name = name;
    this->gun = gun;
}

void Solider::fire(void)
{
    gun->buttle = gun->buttle - 1;
    if(gun->buttle == 0){
        cout << "没有子弹捏" << endl;
    }
    else{
        cout << "开火成功" << endl;
    }
}