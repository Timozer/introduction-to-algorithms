/**
 *  File name:	main.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  7/19 19:51:16 2018
**/

#include <iostream>

#include "../lib/log.h"
#include "../lib/time_analyzer.h"
#include "../lib/sort.h"
#include "../lib/util.h"

using namespace std;

int main(int argc, char *argv[])
{
    
    CSort::SORT_ARGS sort_args;
    sort_args.input = new int[100]; 
    sort_args.output = new int[100];
    sort_args.size = 100;
    for (int i = 0; i < 100; ++i) 
    {
        sort_args.input[i] = random(100);
    }
    show_array(sort_args.input, sort_args.size);
    CTimeAnalyzer analyzer;

    CInsertSort isort(&sort_args);
    if(analyzer.Analyse(isort))
    {
        show_array(sort_args.output, sort_args.size);
    }
    return 0;
}

