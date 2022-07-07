#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <ctime>

// cout 打印日志文件
template <class T>
void outFile(std::fstream &fst,const T &t)
{
    fst << t << std::endl;
}

template <class T, class ...Args>
void outFile(std::fstream &fst,const T &t, Args ...args)
{
    fst << t << " ";
    outFile(fst, args...);
}

template <class T, class ...Args>
void cout(const T &temp, Args ...args)
{
    std::fstream fst;
    fst.open("E:/vscode/log.txt", std::ios::app);
    if(!fst.is_open())
    {
        fst.open("E:/vscode/log.txt", std::ios::out);
    }
    time_t time_1 = time(NULL);
    struct tm *t = localtime(&time_1);
    fst << "记录日志 : " << t->tm_year + 1900 << " 年 " << t->tm_mon + 1 << " 月 ";
    fst << t->tm_mday << " 日 " << t->tm_hour << " 时 " << t->tm_min << " 分 " << t->tm_sec << " 秒 " << std::endl;
    outFile(fst, temp, args...);
    fst.close();
}

void cleanLog()
{
    std::fstream fst;
    fst.open("E:/vscode/log.txt", std::ios::out);
    fst.close();
}

#endif
