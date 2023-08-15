#include "Gun.h"

Gun::Gun(int buttle)
{
    this->buttle = buttle;
}

int Gun::addButtle(int buttle_num)
{
    buttle = buttle + buttle_num;
    return buttle;
}