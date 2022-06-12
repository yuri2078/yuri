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
    static int allStudent; //������
    static double allScore; //�ܳɼ�
    static double maxScore; //��߷�
    static double minScore; //��ͷ�
    void StudentInformation(void); //�����Ϣ
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
    std::cout << "ѧ�ţ�" << setiosflags(std::ios::left) << std::setw(8) << no;
    std::cout << "������" << setiosflags(std::ios::left) << std::setw(7) << name;
    std::cout << "�Ա�" << setiosflags(std::ios::left) << std::setw(6) << sex;
    std::cout << "���䣺" << setiosflags(std::ios::left) << std::setw(5) << age;
    std::cout << "������" << score << "\n";
}

void Student::OutPut(void)
{
    std::cout << "ѧ��������"  << setiosflags(std::ios::left) << std::setw(5) << allStudent;
    std::cout << "�ܳɼ���"    << setiosflags(std::ios::left) << std::setw(6) << allScore;
    std::cout << "ƽ�ֳɼ���"  << setiosflags(std::ios::left) << std::setw(7) << allScore / allStudent;
    std::cout << "��߳ɼ���"  << setiosflags(std::ios::left) << std::setw(8) << maxScore;
    std::cout <<  "��ͳɼ���" << minScore << "\n";
}

int Student::allStudent = 0; 
double Student::allScore = 0; 
double Student::maxScore = 0; 
double Student::minScore = 1000; 

int main(void)
{

    Student stu1(1001,"����","��",18,97.5);
    Student stu2(1002,"����","Ů",19,83.);
    Student stu3(1003,"����","��",17,93.);
    Student stu4(1004,"����","Ů",20,62.5);
    Student stu5(1005,"����","��",18,77);
    stu1.StudentInformation();
    stu2.StudentInformation();
    stu3.StudentInformation();
    stu4.StudentInformation();
    stu5.StudentInformation();
    Student::OutPut();
    return 0;
}