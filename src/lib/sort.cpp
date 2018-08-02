/**
 *  File name:	lib/sort.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	六  7/28 15:45:32 2018
**/

#include "sort.h"
#include <climits>

bool CInsertSort::operator()(void *_pargs)
{
    m_p_args = _pargs == nullptr ? m_p_args : (CSort::SORT_ARGS *)_pargs;
    if (m_p_args->size < 2) {
        return true;
    }
    m_p_args->output[0] = m_p_args->input[0];
    for (int i = 1; i < m_p_args->size; ++i) {
        int tmp = m_p_args->input[i];
        int j = i - 1;
        while(j >= 0 && m_p_args->output[j] > tmp){
            m_p_args->output[j + 1] = m_p_args->output[j];
            --j;
        }
        m_p_args->output[j + 1] = tmp;
    }
    return true;
}

bool CMergeSort::operator()(void *_pargs)
{
    m_p_args = _pargs == nullptr ? m_p_args : (CSort::SORT_ARGS *)_pargs;
    for (int i = 0; i < m_p_args->size; ++i) 
    {
        m_p_args->output[i] = m_p_args->input[i];
    }
    merge(0, m_p_args->size - 1);
    return true;
}
void CMergeSort::merge(int _lidx, int _ridx) // [_lidx, _ridx]
{
    if (_lidx < _ridx) {
        int midx = (_lidx + _ridx) / 2;
        merge(_lidx, midx);
        merge(midx + 1, _ridx);
        merge(_lidx, midx, _ridx);
    }
}
void CMergeSort::merge(int _lidx, int _midx, int _ridx)
{
    int ln = _midx + 1 - _lidx;
    int rn = _ridx  - _midx;
    int *larray = new int[ln + 1];
    int *rarray = new int[rn + 1];
    for (int i = 0; i < ln; ++i) 
    {
        larray[i] = m_p_args->output[_lidx + i];
    }
    larray[ln] = INT_MAX;
    for (int i = 0; i < rn; ++i) 
    {
        rarray[i] = m_p_args->output[_midx + 1 + i];
    }
    rarray[rn] = INT_MAX;

    int j = 0, k = 0;
    for (int i = _lidx; i < _ridx + 1; ++i) 
    {
        m_p_args->output[i] = larray[j] < rarray[k] ? larray[j++] : rarray[k++];
    }

    delete [] larray;
    delete [] rarray;
}
