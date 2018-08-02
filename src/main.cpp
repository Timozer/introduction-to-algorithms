/**
 *  File name:	main.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  7/19 19:51:16 2018
**/

#include <iostream>

#include <vector>
#include "lib/log.h"
#include "lib/time_analyzer.h"
#include "lib/sort.h"
#include "lib/util.h"

using namespace std;

#define ARRAY_MAX 200

bool test(void * _pargs)
{
    char *pStr = static_cast<char *>(_pargs);
    std::cout << *pStr << std::endl;
    return true;
}
int main(int argc, char *argv[])
{
    CSort::SORT_ARGS sort_args;
    sort_args.input = new int[ARRAY_MAX]; 
    sort_args.output = new int[ARRAY_MAX];
    sort_args.size = ARRAY_MAX;
    for (int i = 0; i < ARRAY_MAX; ++i) 
    {
        sort_args.input[i] = random(100, -100);
    }
    CTimeAnalyzer analyzer;

    char testStr[] = "test analyse function";
    analyzer.Analyse(test, testStr);

    CInsertSort isort(&sort_args);
    if(analyzer.Analyse(&isort))
    {
        //show_array(sort_args.input, sort_args.size);
        //show_array(sort_args.output, sort_args.size);
    }

    CMergeSort msort(&sort_args);
    if(analyzer.Analyse(&msort))
    {
        //show_array(sort_args.input, sort_args.size);
        //show_array(sort_args.output, sort_args.size);
    }
    return 0;
}

