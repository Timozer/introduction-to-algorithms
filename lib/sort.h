/**
 *  File name:	lib/sort.h
 *  Author:		Timozer
 *  Mail:		zhenyuwang94@gmail.com
 *  Homepage:	http://none.xxx
 *  Create time:	六  7/28 15:29:16 2018
**/

#ifndef SORT_H_
#define SORT_H_

class CSort
{
public:
    struct SORT_ARGS
    {
        int *input;
        int size;
        int *output;
    };

    CSort (SORT_ARGS *_pargs): m_p_args(_pargs){};
    virtual ~CSort (){};

    virtual bool operator()() = 0;
protected:

    SORT_ARGS *m_p_args;
private:
    /* data */
};

class CInsertSort : CSort
{
public:
    CInsertSort (SORT_ARGS *_pargs) : CSort(_pargs){};
    virtual ~CInsertSort (){};

    virtual bool operator()();
private:
    /* data */
};

class CMergeSort : CSort
{
public:
    CMergeSort ();
    virtual ~CMergeSort ();

private:
    /* data */
};
#endif /* ifndef SORT_H_ */
