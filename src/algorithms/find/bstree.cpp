/**
 *  File name:	algorithms/find/bstree.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	二  8/ 7 21:56:37 2018
**/

#include "bstree.h"

#include <iostream>
void BinarySearchTree::Walk(int _idx) const
{
    if (!(_idx >= 0 && _idx < mData.size())) {
        return;
    }

    Walk(_Left(_idx));
    std::cout << mData[_idx] << std::endl;
    Walk(_Right(_idx));
}
int BinarySearchTree::_Left(int _idx) const
{
	return 0;
}

int BinarySearchTree::_Right(int _idx) const
{
	return 0;
}
int BinarySearchTree::_Parent(int _idx) const
{
	return 0;
}
int BinarySearchTree::Search(int _idx, int _key) const
{
    if (_idx >= 0 && _idx < mData.size() && mData[_idx] == _key) {
        return _idx;
    }
	return _key < mData[_idx] ? Search(_Left(_idx), _key) : Search(_Right(_idx), _key);
}

