#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Name
{
    int age;
    char name[80];
    struct Name *next;
};
//定义结构体
void show(struct Name *p)
{
    while (p)
    {
        printf("该同学是:%-15s 今年   %-3d  岁 \n", p->name, p->age);
        p = p->next;
    }
}
//定义输出函数
struct Name *add(struct Name *head)
{
    char name[80];
    int age;
    struct Name *p = head;
    printf("请输入需要添加的同学姓名 年龄: ");
    scanf("%s%d", name, &age);
    if (head == NULL)
    {
        head = (struct Name *)malloc(sizeof(struct Name));
        strcpy(head->name, name);
        head->age = age;
        head->next = NULL;
        return head;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = (struct Name *)malloc(sizeof(struct Name));
        strcpy(head->next->name, name);
        head->next->age = age;
        head->next->next = NULL;
    }
    return p;
}
//定义添加成员函数
struct Name *del(struct Name *head)
{
    struct Name *p = head, *t = NULL;
    char s[80];
    printf("请输入你想要删除的同学的名字");
    scanf("%s", s);
    printf("\n\n\n正在查找中.......\n\n\n");
    if(strcmp(head->name, s) == 0) 
    {
        t = head;
        head = head->next;
        free(t);
        return head;
    }
    while (p != NULL && strcmp(p->name, s))
    {
        t = p;
        p = p->next;
    }
    if(p != NULL)
    {
        t->next = p->next;
        printf("已经找到并且删除！\n\n\n");
    }
    else
    {
        printf("抱歉没有找到呢！\n\n\n");
    }
    return head;
}
//定义删除成员函数
void relass(struct Name *p)
{
    struct Name *t = p;
    while (p)
    {
        free(t);
        p = p->next;
        t = p;
    }
}
//定义释放内存呢函数
int main(void)
{
    struct Name *head = NULL;
    int x;
    printf("欢饮来到同学信息录入删除系统--------版本2.0\n");
    printf("请按照序号选择操作\n");
    while(1)
    {
        printf(" 1 添加n个同学\n 2 删除一个同学 \n 3 查看当然数据库\n 4 打印成员并且退出系统\n\n请输入数据:");
        scanf("%d", &x);
        switch(x)
        {
            case 1 : {
                head = add(head);
                break;
            }
            case 2 : {
                head = del(head);
                break;
            }
            case 3 : {
                show(head);
                break;
            }
            case 4 : {
                show(head);
                relass(head);
                return 0;
            }
            default:
            {
                printf("输入错误！程序结束！");
                return 0;
            }     
        }
    }
}