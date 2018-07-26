/**
 *  File name:	time_analyzer.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	三  7/25 15:48:18 2018
**/

#ifndef TIME_ANALYZER_H_
#define TIME_ANALYZER_H_ 

#include "analyzer.h"

#include <chrono>

class CTimeAnalyzer  : CAnalyzer
{
public:
    CTimeAnalyzer ();
    virtual ~CTimeAnalyzer ();

private:
    /* data */
    std::chrono::time_point<std::chrono::system_clock> m_start;
    std::chrono::time_point<std::chrono::system_clock> m_end;
};

#endif /* ifndef TIME_ANALYZER_H_ */
