#ifndef SOLIDER_H
#define SOLIDER_H

#include <iostream>
#include "Gun.h"

using std::cout;
using std::endl;
using std::string;

class Solider
{
public:
	string name;
	Gun *gun;
public:
	Solider(string name, Gun *gun);

	void fire(void);
};

#endif 
