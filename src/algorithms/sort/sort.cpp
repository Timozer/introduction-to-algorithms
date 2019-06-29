/**
 *  File name:	lib/sort.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	六  7/28 15:45:32 2018
**/

#include "sort.h"
#include <cstddef>
#include <climits>

bool InsertSort::operator()(void *_pargs)
{
    Data<int>& data = getSortData();
    if (data.size() < 2) {
        return true;
    }
    for (int i = 1; i < data.size(); ++i) {
        int tmp = data[i];
        int j = i - 1;
        while(j >= 0 && data[j] > tmp){
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = tmp;
    }
    return true;
}

bool MergeSort::operator()(void *_pargs)
{
    Data<int>& data = getSortData();
    merge(0, data.size() - 1);
    return true;
}
void MergeSort::merge(int _lidx, int _ridx) // [_lidx, _ridx]
{
    if (_lidx < _ridx) {
        int midx = (_lidx + _ridx) / 2;
        merge(_lidx, midx);
        merge(midx + 1, _ridx);
        merge(_lidx, midx, _ridx);
    }
}
void MergeSort::merge(int _lidx, int _midx, int _ridx)
{
    Data<int>& data = getSortData();
    int ln = _midx + 1 - _lidx;
    int rn = _ridx  - _midx;
    int *larray = new int[ln + 1];
    int *rarray = new int[rn + 1];
    for (int i = 0; i < ln; ++i) 
    {
        larray[i] = data[_lidx + i];
    }
    larray[ln] = INT_MAX;
    for (int i = 0; i < rn; ++i) 
    {
        rarray[i] = data[_midx + 1 + i];
    }
    rarray[rn] = INT_MAX;

    int j = 0, k = 0;
    for (int i = _lidx; i < _ridx + 1; ++i) 
    {
        data[i] = larray[j] < rarray[k] ? larray[j++] : rarray[k++];
    }

    delete [] larray;
    delete [] rarray;
}
