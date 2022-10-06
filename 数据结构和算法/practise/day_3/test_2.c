#include <stdio.h>
#include <stdlib.h>

typedef struct student2
{
    char number[10]; //学号
    char name[20];
    int age;
    float score[6]; // 6门功课成绩;
} stu;

void AccumulatePoints(stu s);
int main()
{
    stu s; //学生信息
    /*补充代码输入学生信息到s中*/
    scanf("%s%s%d", s.number, s.name, &s.age);
    for (int i = 0; i < 6;i++){
        scanf("%f", s.score + i);
    }

    /*计算积分并输出*/
    AccumulatePoints(s);
    return 0;
}


/*根据各科成绩累计课程积分并输出*/
void AccumulatePoints(stu s)
{
    int sum = 0;
    int key[6] = {4, 3, 4, 3, 4, 2};
    for (int i = 0; i < 6; i++){
        s.score[i] > 60 ? sum += key[i] : 1;
    }
    printf("%s %s %d\n%d\n", s.number, s.name, s.age, sum);
}