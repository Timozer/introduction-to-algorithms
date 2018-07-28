/**
 *  File name:	time_analyzer.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	三  7/25 15:55:47 2018
**/

#include "time_analyzer.h"
#include "log.h"
#include <cstdarg>
#include <sstream>

//template<typename FIRST>
//std::string toString(FIRST first, ...)
//{
    //std::stringstream res;

    //va_list vargs;
    //va_start(vargs, first);

    //va_end(vargs);

    //return res.str();
//}

bool CTimeAnalyzer::Analyse(bool (*_pf)(void *), void *_pargs)
{
    CLog::Log("Begin to run program");
    m_start = std::chrono::system_clock::now();

    bool ret = _pf(_pargs);

    m_end = std::chrono::system_clock::now();
    CLog::Log("End to run program");

    std::chrono::duration<double> elapsed_seconds = m_end - m_start;
    std::stringstream info;
    info << "Cost " << elapsed_seconds.count() << "s";
    CLog::Log(info.str());

    return ret;
}
