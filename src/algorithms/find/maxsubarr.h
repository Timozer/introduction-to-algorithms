/**
 *  File name:	algorithms/find/maxsubarr.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  8/ 2 14:48:29 2018
**/

#ifndef MAXSUBARR_H_FPSDAYPV
#define MAXSUBARR_H_FPSDAYPV

#include "../../data/data.h"

class CMaxSubArray
{
public:
    CMaxSubArray (Data<int> &_data): m_data(_data){}

    bool operator()(void *_pargs = nullptr);
protected:
    int FindMaxSubArray(int _lidx, int _ridx);
    int FindMaxCrossSubArray(int _lidx, int _midx, int _ridx);
private:
    /* data */
    Data<int> &m_data;
};

#endif /* end of include guard: MAXSUBARR_H_FPSDAYPV */
