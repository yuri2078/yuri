#include <iostream>
#include <iomanip>
class Student
{
private:
    int no;
    std::string name;
    std::string sex;
    int age;
    double score;
public:
    Student(int no, std::string name, std::string sex, int age, double secore);
    static int allStudent; //总人数
    static double allScore; //总成绩
    static double maxScore; //最高分
    static double minScore; //最低分
    void StudentInformation(void); //输出信息
    static void OutPut(void);
};

Student::Student(int no, std::string name, std::string sex, int age, double score)
{
    this->no = no;
    this->name = name;
    this->sex = sex;
    this->age = age;
    this->score = score;
    allStudent++;
    if(maxScore < score)
        maxScore = score;
    if(minScore > score)
        minScore = score;
    allScore = allScore + score;
}

void Student::StudentInformation(void)
{
    std::cout << "学号：" << setiosflags(std::ios::left) << std::setw(8) << no;
    std::cout << "姓名：" << setiosflags(std::ios::left) << std::setw(7) << name;
    std::cout << "性别：" << setiosflags(std::ios::left) << std::setw(6) << sex;
    std::cout << "年龄：" << setiosflags(std::ios::left) << std::setw(5) << age;
    std::cout << "分数：" << score << "\n";
}

void Student::OutPut(void)
{
    std::cout << "学生总数："  << setiosflags(std::ios::left) << std::setw(5) << allStudent;
    std::cout << "总成绩："    << setiosflags(std::ios::left) << std::setw(6) << allScore;
    std::cout << "平局成绩："  << setiosflags(std::ios::left) << std::setw(7) << allScore / allStudent;
    std::cout << "最高成绩："  << setiosflags(std::ios::left) << std::setw(8) << maxScore;
    std::cout <<  "最低成绩：" << minScore << "\n";
}

int Student::allStudent = 0; 
double Student::allScore = 0; 
double Student::maxScore = 0; 
double Student::minScore = 1000; 

int main(void)
{

    Student stu1(1001,"张三","男",18,97.5);
    Student stu2(1002,"李四","女",19,83.);
    Student stu3(1003,"王五","男",17,93.);
    Student stu4(1004,"郭六","女",20,62.5);
    Student stu5(1005,"任七","男",18,77);
    stu1.StudentInformation();
    stu2.StudentInformation();
    stu3.StudentInformation();
    stu4.StudentInformation();
    stu5.StudentInformation();
    Student::OutPut();
    return 0;
}