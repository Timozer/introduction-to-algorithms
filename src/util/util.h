/**
 *  File name:	lib/util.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	六  7/28 16:33:24 2018
**/

#ifndef UTIL_H
#define UTIL_H

int random(int _max, int _min = 0);
template<int MAX, int MIN = 0>
int random() { return random(MAX, MIN); }

int max(int _lh, int _rh);
#endif /* end of include guard: UTIL_H */
