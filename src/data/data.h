/**
 *  File name:	data/data.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  8/ 2 14:59:24 2018
**/

#ifndef DATA_H_8AXBNFDK
#define DATA_H_8AXBNFDK

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

template<typename T>
class Data : public std::vector<T>
{
public:
    void show() const
    {
        std::copy(this->begin(), this->end(),
                std::ostream_iterator<int>(std::cout, " "));
        //for (auto item : *this) {
            //std::cout << item << " ";
        //}
        std::cout << std::endl;
    }
    bool genData(int _size, T (*_genfunc)())
    {
        for (int i = 0; i < _size; ++i) 
        {
            this->push_back(_genfunc());
        }
        return true;
    }
};

#endif /* end of include guard: DATA_H_8AXBNFDK */
