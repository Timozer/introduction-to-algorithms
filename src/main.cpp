/**
 *  File name:	main.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  7/19 19:51:16 2018
**/

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "../lib/log.h"
#include "../lib/time_analyzer.h"
#include "../lib/sort.h"

using namespace std;

int main(int argc, char *argv[])
{
    
    std::srand(std::time(0));
    CSort::SORT_ARGS sort_args;
    sort_args.input = new int[100]; 
    sort_args.output = new int[100];
    sort_args.size = 100;
    for (int i = 0; i < 100; ++i) 
    {
        sort_args.input[i] = 1 + std::rand() / ((RAND_MAX + 1u) / 100);
        std::cout << sort_args.input[i] << " ";
    }
    std::cout << std::endl;
    CTimeAnalyzer analyzer;

    CInsertSort isort(&sort_args);
    if(analyzer.Analyse(isort))
    {
        for (int i = 0; i < 100; ++i) {
            std::cout << sort_args.output[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

