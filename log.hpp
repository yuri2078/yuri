#include <fstream>
#include <string>
#include <ctime>
#include <qobject.h>

class M_log : public QObject
{

    QOBJECT_H
private:
    static time_t my_time;

public:
    M_log &operator<<(const std::string &temp);
    M_log(QObject *parent);
    int clean();
};
M_log::M_log(QObject *parent) : QObject(parent)
{

}
M_log & M_log::operator << (const std::string &temp)
{
    std::fstream fst;
    fst.open("E:/vscode/log.txt", std::ios::app);
    time_t time_1 = time(NULL);
    struct tm *t = localtime(&time_1);
    if(my_time != time_1)
    {
        fst << "记录日志 : " << t->tm_year + 2000 << " 年 " << t->tm_mon << " 月 ";
        fst << t->tm_mday << " 日 " << t->tm_hour << " 时 " << t->tm_min << " 分" << std::endl;
    }
    
    fst << temp << std::endl;
    my_time = time_1;

    fst.close();
    return *this;
}

int M_log::clean()
{
    std::fstream fst;
    fst.open("E:/vscode/log.txt", std::ios::out);
    if(fst.is_open())
    {
        return 0;
    }
    else
    {
        fst.close();
        return 1;
    }
}

time_t M_log::my_time = 0;

M_log m_log(NULL);