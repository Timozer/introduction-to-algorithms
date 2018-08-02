/**
 *  File name:	time_analyzer.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	三  7/25 15:48:18 2018
**/

#ifndef TIME_ANALYZER_H_
#define TIME_ANALYZER_H_ 

//#include "analyzer.h"

#include "log.h"
#include <sstream>
#include <chrono>

class CTimeAnalyzer
{
public:
    CTimeAnalyzer (){};
    virtual ~CTimeAnalyzer (){};

    virtual bool Analyse(bool (*_pf)(void *_pg), void *_pg);
    template<typename FUNCTOR, typename ARGUMENTS = void>
    bool Analyse(FUNCTOR *_fc, ARGUMENTS *_pt = nullptr)
    {
        CLog::Log("Begin to run program");
        m_start = std::chrono::system_clock::now();

        bool ret = (*_fc)(_pt);

        m_end = std::chrono::system_clock::now();
        CLog::Log("End to run program");

        std::chrono::duration<double> elapsed_seconds = m_end - m_start;
        std::stringstream info;
        info << "Cost " << elapsed_seconds.count() << "s";
        CLog::Log(info.str());

        return ret;
    }

protected:

private:
    /* data */
    std::chrono::time_point<std::chrono::system_clock> m_start;
    std::chrono::time_point<std::chrono::system_clock> m_end;
};

template<>
bool CTimeAnalyzer::Analyse(bool (*)(void *), void *);
#endif /* ifndef TIME_ANALYZER_H_ */
