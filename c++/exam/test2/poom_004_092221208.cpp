#include <iostream>

class Vocation
{
protected:
    double dinnerTime, sleepTime, playTime, studyTime, dazeTime;

public:
    std::string state; //生活状态字符串
    int flag = 1; //生活是否健康标志
    Vocation();
    Vocation(double dinnertime, double sleeptime, double playtime, double studytime);
    void SetdinnerTime(double dinnertime);
    double GetdinnerTime(); //吃饭时间
    void SetsleepTime(double sleeptime);
    double GetsleepTime(); //睡觉时间
    void SetplayTime(double playtime);
    double GetplayTime(); //游戏时间
    void SetstudyTime(double studytime);
    double GetstudyTime(); //学习时间
    void SetdazeTime(double dazetime);
    double GetdazeTime(); //发呆时间
    ~Vocation();
};
Vocation::Vocation()
{
}

Vocation::~Vocation()
{
}

Vocation::Vocation(double dinnertime, double sleeptime, double playtime, double studytime)
{
    //调用set函数赋值
    SetdinnerTime(dinnertime);
    SetsleepTime(sleeptime);
    SetplayTime(playtime);
    SetstudyTime(studytime);
    SetdazeTime(24 - dinnerTime - sleepTime - playTime - studyTime);

}

void Vocation::SetdinnerTime(double dinnertime)
{
    dinnerTime = dinnertime; //赋值给类中的私有成员
    if(dinnerTime > 2)
    {
        state = state + "你可真能吃哦\n";
        flag = 0; //不健康了
    }
}

double Vocation::GetdinnerTime()
{
    return dinnerTime;
}

void Vocation::SetsleepTime(double sleeptime)
{
    sleepTime = sleeptime;
    if(sleepTime > 10)
    {
        state = state + "你是一个睡神,真能睡\n";
        flag = 0;
    }
}

double Vocation::GetsleepTime()
{
    return sleepTime;
}

void Vocation::SetplayTime(double playtime)
{
    playTime = playtime;
    if(playTime > 4)
    {
        state = state + "你在游戏上花费时间太多了，荒废青春\n";
        flag = 0;
    }
}

double Vocation::GetplayTime()
{
    return playTime;
}

void Vocation::SetstudyTime(double studytime)
{
    studyTime = studytime;
    if(studyTime > 8)
    {
        state = state + "学习狂魔，励志典范\n";
        flag = 0;
    }
}

double Vocation::GetstudyTime()
{
    return studyTime;
}

void Vocation::SetdazeTime(double dazetime)
{
    dazeTime = dazetime;
    if(dazeTime > 2)
    {
        state = state + "瞎想太多";
        flag = 0;
    }
}

double Vocation::GetdazeTime()
{
    return dazeTime;
}

int main()
{
    double dinnertime, sleeptime, playtime, studytime;
    std::cout << "请输入今天花费于吃饭、睡觉、游戏、学习的时间\n";
    std::cin >> dinnertime >> sleeptime >> playtime >> studytime;
    if (dinnertime + sleeptime + playtime + studytime > 24)
    {
        std::cout << "人才啊，一天当" << dinnertime + sleeptime + playtime + studytime << "小时用\n";
        return 0;
    } 
    Vocation v1(dinnertime, sleeptime, playtime, studytime);
    std::cout << "吃饭花费" << v1.GetdinnerTime() << "小时,";
    std::cout << "睡觉花费" << v1.GetsleepTime() << "小时,";
    std::cout << "游戏花费" << v1.GetplayTime() << "小时,";
    std::cout << "学习花费" << v1.GetstudyTime() << "小时,";
    std::cout << "发呆花费" << v1.GetdazeTime() << "小时\n";
    std::cout << v1.state;
    if (v1.flag)
    {
        std::cout << "非常健康的生活";
    }
    return 0;
}