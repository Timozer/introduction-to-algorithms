/**
 *  File name:	algorithms/find/bstree.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	二  8/ 7 21:53:08 2018
**/

#ifndef BSTREE_H_KVSGT4R9
#define BSTREE_H_KVSGT4R9

#include "../../data/data.h"

class BinarySearchTree
{
public:
    BinarySearchTree (Data<int> const &_data) : mData(_data) {}
    virtual ~BinarySearchTree (){}

    void Walk(int _idx) const;
    int Search(int _idx, int _key) const;
private:
    /* data */
    Data<int> mData;

    /* functions */
    int _Parent(int _idx) const;
    int _Left(int _idx) const;
    int _Right(int _idx) const;
};

#endif /* end of include guard: BSTREE_H_KVSGT4R9 */
