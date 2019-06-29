/**
 *  File name:	algorithms/find/maxsubarr.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  8/ 2 14:54:41 2018
**/

#include "maxsubarr.h"

#include "../../util/util.h"
#include <iostream>

int CMaxSubArray::FindMaxCrossSubArray(int _lidx, int _midx, int _ridx)
{
    int lmax = m_data[_midx];
    int lsum = lmax;
    for (int i = _midx - 1; i >= _lidx; --i) 
    {
        lsum += m_data[i];
        lmax = lsum > lmax ? lsum : lmax;
    }
    int rmax = m_data[_midx + 1];
    int rsum = rmax;
    for (int i = _midx + 2; i <= _ridx; ++i) 
    {
        rsum += m_data[i];
        rmax = rsum > rmax ? rsum : rmax;
    }
	return lmax + rmax;
}

int CMaxSubArray::FindMaxSubArray(int _lidx, int _ridx)
{
    if (_lidx == _ridx) {
        return m_data[_lidx];
    }
    int midx = (_lidx + _ridx) / 2;
    int lmax = FindMaxSubArray(_lidx, midx);
    int rmax = FindMaxSubArray(midx + 1, _ridx);
    int cmax = FindMaxCrossSubArray(_lidx, midx, _ridx);
    return max(lmax, max(cmax, rmax));
}

bool CMaxSubArray::operator()(void *_pargs)
{
	int max = FindMaxSubArray(0, m_data.size() - 1);
    std::cout << "Max sub array is " << max << std::endl;
    return true;
}

