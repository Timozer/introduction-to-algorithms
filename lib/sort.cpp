/**
 *  File name:	lib/sort.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	六  7/28 15:45:32 2018
**/

#include "sort.h"

bool CInsertSort::operator()()
{
    if (m_p_args->size < 2) {
        return true;
    }
    m_p_args->output[0] = m_p_args->input[0];
    for (int i = 1; i < m_p_args->size; ++i) {
        int tmp = m_p_args->input[i];
        int j = i - 1;
        while(j >= 0 && m_p_args->output[j] < tmp){
            m_p_args->output[j + 1] = m_p_args->output[j];
            --j;
        }
        m_p_args->output[j + 1] = tmp;
    }
    return true;
}
