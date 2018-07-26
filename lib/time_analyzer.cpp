/**
 *  File name:	time_analyzer.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	三  7/25 15:55:47 2018
**/

#include "time_analyzer.h"

bool CTimeAnalyzer::Analyse()
{
    m_start = std::chrono::system_clock::now();
    m_end = std::chrono::system_clock::now();
}
