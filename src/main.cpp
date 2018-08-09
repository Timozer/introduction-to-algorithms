/**
 *  File name:	main.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	四  7/19 19:51:16 2018
**/

#include <iostream>
#include <iterator>
#include <fstream>
#include <climits>

#include "lib/log.h"
#include "lib/time_analyzer.h"
#include "algorithms/sort/sort.h"
#include "algorithms/sort/heapsort.h"
#include "algorithms/sort/quicksort.h"
#include "util/util.h"
#include "algorithms/find/maxsubarr.h"
#include "data/data.h"

using namespace std;

static int p[100] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 0};

int cutrod(int *_p, int n)
{
    if (n == 0) {
        return 0;
    }
    static int pRes[100] = { 0 };
    if (pRes[n] == 0) {
        int res = -INT_MAX; 
        for (int i = 1; i <= n; ++i) 
        {
            res = std::max(res, _p[i] + cutrod(_p, n - i));
        }
        pRes[n] = res;
    }
    return pRes[n];
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < 101; ++i) 
    {
        cout << cutrod(p, i) << " ";
    }
    cout << endl;
    //Data<int> data;
    //data.genData(300000, random<10000, -10000>);
    ////data.show();

    //CTimeAnalyzer analyzer;

    //InsertSort isort(data);
    //if(analyzer.Analyse(&isort))
    //{
        ////isort.getResult().show();
    //}

    //MergeSort msort(data);
    //if(analyzer.Analyse(&msort))
    //{
        ////msort.getResult().show();
    //}

    //HeapSort hsort(data);
    //if(analyzer.Analyse(&hsort))
    //{
        ////msort.getResult().show();
    //}

    //QuickSort qsort(data);
    //if(analyzer.Analyse(&qsort))
    //{
        ////msort.getResult().show();
    //}
    //CMaxSubArray maxsubarr(data);
    //analyzer.Analyse(&maxsubarr);
    return 0;
}

