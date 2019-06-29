/**
 *  File name:	log.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	三  7/25 15:17:40 2018
**/

#ifndef LOG_H_
#define LOG_H_ 

#include <string>
#include <chrono>
#include <ctime>

class CLog
{
public:
    static void Log(std::string _info);
};

#endif /* ifndef LOG_H_  */
