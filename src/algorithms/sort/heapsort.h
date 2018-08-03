/**
 *  File name:	algorithms/sort/heapsort.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  8/ 2 22:33:48 2018
**/

#ifndef HEAPSORT_H_PAEO0YHM
#define HEAPSORT_H_PAEO0YHM

#include "sort.h"
#include "../../data/data.h"

class HeapSort : public Sort
{
public:
    HeapSort (Data<int> &_data) : Sort(_data) { m_heapsize = _data.size(); }
    virtual ~HeapSort (){}

    virtual bool operator()(void *_pargs);
private:
    /* data */
    int m_heapsize;

    /* functions */
    int parent(int _idx) { return _idx >> 1; }
    int left(int _idx) { return _idx << 1; }
    int right(int _idx) { return (_idx << 1) + 1; }
    void MaxHeapfy(int _idx);
    void BuildMaxHeap();
};

#endif /* end of include guard: HEAPSORT_H_PAEO0YHM */
