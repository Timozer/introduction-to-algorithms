/**
 *  File name:	log.cpp
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	三  7/25 15:20:05 2018
**/

#include "log.h"

#include <iostream>

void CLog::Log(std::string _info)
{
    auto now_t_p = std::chrono::system_clock::now();
    auto now_t = std::chrono::system_clock::to_time_t(now_t_p);
    std::string now_str = std::ctime(&now_t);
    now_str[now_str.size() - 1] = ':';

    std::cout << "INFO " << now_str 
        << "\t" << _info << std::endl;
}
