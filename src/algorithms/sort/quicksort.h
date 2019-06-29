/**
 *  File name:	algorithms/sort/quicksort.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	五  8/ 3 08:32:36 2018
**/

#ifndef QUICKSORT_H_AK8XEJ65
#define QUICKSORT_H_AK8XEJ65

#include "sort.h"

#include "../../data/data.h"

class QuickSort : public Sort
{
public:
    QuickSort (Data<int> &_data) : Sort(_data) {}
    virtual ~QuickSort (){}

    virtual bool operator()(void *_pargs);
private:
    /* data */
    
    /* function */
    int partation(int _lidx, int _ridx);
    void sort(int _lidx, int _ridx);

};

#endif /* end of include guard: QUICKSORT_H_AK8XEJ65 */
