/**
 *  File name:	analyzer.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	三  7/25 15:45:46 2018
**/

#ifndef ANALYZER_H_
#define ANALYZER_H_ 

class CAnalyzer
{
public:
    CAnalyzer ();
    virtual ~CAnalyzer ();

    virtual bool Analyse();
private:
    /* data */
};

#endif /* ifndef ANALYZER_H_ */
