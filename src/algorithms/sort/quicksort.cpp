/**
 *  File name:	algorithms/sort/quicksort.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	五  8/ 3 08:35:43 2018
**/

#include "quicksort.h"
#include <utility>

bool QuickSort::operator()(void *_pargs)
{
    sort(0, getSortData().size() - 1);
	return true;
}

int QuickSort::partation(int _lidx, int _ridx)
{
    Data<int> &data = getSortData();
    int q = _lidx;
    for (int i = _lidx; i < _ridx;  ++i) 
    {
        if (data[i] < data[_ridx]) {
            std::swap(data[i], data[q++]);
        }
    }
    std::swap(data[q], data[_ridx]);
	return q;
}
void QuickSort::sort(int _lidx, int _ridx)
{
    if (_lidx < _ridx) {
        int q = partation(_lidx, _ridx);
        sort(_lidx, q - 1);
        sort(q + 1, _ridx);
    }
}

