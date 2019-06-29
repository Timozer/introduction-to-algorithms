#ifndef ACTIVITIES_H_
#define ACTIVITIES_H_

#include <iostream>

static int start[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
static int etime[] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};


void actSel()
{
    int *res = new int[12];
    res[1] = 1;
    unsigned int cur = 1;
    for (unsigned int i = 2; i < 12; i++)
    {

        if (start[i] >= etime[res[cur]])
        {
            res[++cur] = i;
        }
    }
    
    for(unsigned int i = 0; i < 12; i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    
}

#endif /*ACTIVITIES_H_ */