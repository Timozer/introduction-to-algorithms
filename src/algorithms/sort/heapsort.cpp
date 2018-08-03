/**
 *  File name:	algorithms/sort/heapsort.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  8/ 2 22:41:14 2018
**/

#include "heapsort.h"

void HeapSort::BuildMaxHeap()
{
    for(int i = m_heapsize / 2; i >= 0; --i)
    {
        MaxHeapfy(i);
    }
}

void HeapSort::MaxHeapfy(int _idx)
{
    Data<int> &data = getSortData();
    int lv = left(_idx);
    int rv = right(_idx);
    int maxvidx = lv < m_heapsize && data[lv] > data[_idx] ? lv : _idx;
    maxvidx = rv < m_heapsize && data[rv] > data[maxvidx] ? rv : maxvidx;
    if (maxvidx != _idx) {
        int tmp = data[_idx];
        data[_idx] = data[maxvidx];
        data[maxvidx] = tmp;
        MaxHeapfy(maxvidx);
    }
}

bool HeapSort::operator()(void *_pargs)
{
    BuildMaxHeap();
    Data<int> &data = getSortData();
    for (int i = data.size() - 1; i > 0; --i) 
    {
        int tmp = data[i];
        data[i] = data[0];
        data[0] = tmp;
        m_heapsize--;
        MaxHeapfy(0);
    }
    return true;
}

