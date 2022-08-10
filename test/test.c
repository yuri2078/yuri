#include <math.h>
#include <stdio.h>
#include <stdlib.h>
struct students
{
    char id[10];
    char name[20];
    float testo, testtw, testth;
};
int main()
{
    char ch;
    int select, i = 0, j, n;
    struct students stu[100];
    do
    {
        printf("\n\t^^^^^^^^^^^^^^^^^^^学生管理系统^^^^^^^^^^^^^^^^^^^\n\n");
        printf("\t*******  0、退出系统     1、信息录入     ********\n\n");
        printf("\t*******  2、信息浏览     3、信息排序     ********\n\n");
        printf("\t*******  4、信息查询     5、信息清屏     ********\n\n");
        printf("\t*******  6、信息删除                     ********\n\n");
        printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
        printf("请选择：");
        scanf("%d", &select);
        if (select == 0)
            break;
        switch (select)
        {
        case 1:
            do
            {
                printf("请输入学生ID:\n");
                scanf("%s", &stu[i].id);
                printf("请输入学生name:\n");
                scanf("%s", &stu[i].name);
                printf("请输入第1门成绩：");
                scanf("%f", &stu[i].testo);
                printf("请输入第2门成绩：");
                scanf("%f", &stu[i].testtw);
                printf("请输入第3门成绩：");
                scanf("%f", &stu[i].testth);
                printf("是否继续录入信息？（y/n）");
                fflush(stdin);
                scanf("%c", &ch);
                i++;
            } while (ch == 'y');
            break;

        case 2:
            printf("\nID(NO)     NAME               STB     C语言     SQL     AVG");
            for (j = 0; j < i; j++)
            {
                printf("\n%-11s%-19s%-8.2f%-10.2f%-8.2f%-8.2f\n", stu[j].id, stu[j].name, stu[j].testo, stu[j].testtw, stu[j].testth, (stu[j].testo + stu[j].testtw + stu[j].testth) / 3.0);
            }
            break;

        case 3:
            do
            {
                int t;
                int s;
                printf("\n========1.按学号排序==========2.按姓名排序=======\n");
                printf("\n========3.按平均分排序===========================\n");
                printf("请选择：");
                scanf("%d", &s);
                if (s != 1 && s != 2 && s != 3)
                    break;
                switch (s)
                {
                case 1:
                    printf("\n========1.升序==========2.降序=======\n");
                    printf("请选择:");
                    scanf("%d", &t);
                    if (t == 1)
                    {
                        for (j = 0; j < i; j++)
                            for (n = j; n < i; n++)
                                if (stu[j].id > stu[n].id)
                                {
                                    stu[99] = stu[j];
                                    stu[j] = stu[n];
                                    stu[n] = stu[99];
                                }
                    }

                        for (j = 0; j < i; j++)
                            printf("\n%-11s%-19s%-8.2f%-10.2f%-8.2f%-8.2f\n", stu[j].id, stu[j].name, stu[j].testo, stu[j].testtw, stu[j].testth, (stu[j].testo + stu[j].testtw + stu[j].testth) / 3.0);
                    break;
                }
            } while (1);
            break;
        }
    } while (1);
}
