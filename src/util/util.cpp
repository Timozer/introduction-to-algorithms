/**
 *  File name:	lib/util.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	六  7/28 16:35:21 2018
**/

#include "util.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

int random(int _max, int _min /* = 0 */)
{
    static bool isInit = false;
    if (!isInit)
    {
        std::srand(std::time(0));
        isInit = true;
    }
    return _min + std::rand() / ((RAND_MAX + 1u) / (_max - _min));
}

int max(int _lh, int _rh)
{
    return _lh > _rh ? _lh : _rh;
}
