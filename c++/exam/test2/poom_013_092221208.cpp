#include <iostream>

class Student
{
private:
    int num;
    double score;
public:
    Student(int num, double score);
    int Get_num(void) { return num; }
    double Get_score(void) { return score; }
};

Student::Student(int num, double score)
{
    this->num = num;
    this->score = score;
}

Student *max(Student * s)
{
    Student *p = s;
    for (int i = 1; i < 5;i++)
    {
        s++;
        if(s->Get_score() > p->Get_score())
        {
            p = s;
        }
    }
    return p;
}

int main()
{
    Student *max(Student * s);
    Student stud[5] = {Student(101, 78.5), Student(102, 85.5), Student(103, 98.5), Student(104, 100.0), Student(105, 95.5)}, *p;
    p = max(stud);
    std::cout << "��߷�ѧ����ѧ��: " << p->Get_num() << ", ����: " << p->Get_score();
    return 0;
}