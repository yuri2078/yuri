#include <stdio.h>
typedef struct stu
{
    int sno;
    char name[10];
    int age;
} stu;
int main(void)
{
    stu student[3] = {1, "zhang", 20, 2, "li", 19, 3, "wang", 20}, *p;
    int i;
    p = student;
    for (i = 0; i < 3;i++)
    {
        printf("%s", p->name + i);
        p++;
    }
    return 0;
}