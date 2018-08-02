/**
 *  File name:	lib/sort.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	六  7/28 15:29:16 2018
**/

#ifndef SORT_H_
#define SORT_H_

#include "../../data/data.h"

class Sort
{
public:
    Sort (Data<int> &_data) : m_data(_data), m_result(_data){}
    virtual ~Sort (){}

    const Data<int> &getData() const { return m_data; }
    //Data<int> &getResult() { return m_result; }
    const Data<int> &getResult() const { return m_result; }

    virtual bool operator()(void *_pargs) = 0;
protected:
    Data<int> &getSortData() { return m_result; }
private:
    /* data */
    Data<int> &m_data;
    Data<int> m_result;
};
class InsertSort : public Sort
{
public:
    InsertSort(Data<int> &_data) : Sort(_data){}
    virtual ~InsertSort(){}

    bool operator()(void *_pargs);
};

class MergeSort : public Sort
{
public:
    MergeSort(Data<int> &_data) : Sort(_data){}
    virtual ~MergeSort(){}

    bool operator()(void *_pargs);
private:
    /* functions */
    void merge(int _lidx, int _ridx);
    void merge(int _lidx, int _midx, int _ridx);
};
#endif /* ifndef SORT_H_ */
