/**
 *  File name:	main.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  7/19 19:51:16 2018
**/

#include <iostream>

#include "lib/log.h"
#include "lib/time_analyzer.h"
#include "algorithms/sort/sort.h"
#include "algorithms/sort/heapsort.h"
#include "algorithms/sort/quicksort.h"
#include "util/util.h"
#include "algorithms/find/maxsubarr.h"
#include "data/data.h"

using namespace std;

int main(int argc, char *argv[])
{
    Data<int> data;
    data.genData(10, random<20, -20>);
    data.show();

    CTimeAnalyzer analyzer;

    InsertSort isort(data);
    if(analyzer.Analyse(&isort))
    {
        isort.getResult().show();
    }

    MergeSort msort(data);
    if(analyzer.Analyse(&msort))
    {
        msort.getResult().show();
    }

    HeapSort hsort(data);
    if(analyzer.Analyse(&hsort))
    {
        msort.getResult().show();
    }

    QuickSort qsort(data);
    if(analyzer.Analyse(&qsort))
    {
        msort.getResult().show();
    }
    CMaxSubArray maxsubarr(data);
    analyzer.Analyse(&maxsubarr);
    return 0;
}

