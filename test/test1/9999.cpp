#include "9999.h"
#include<stdio.h>
#include<Windows.h>
using namespace std;


/*
设计一个实用的小型通讯录程序，具有添加，查询和删除功能。
由姓名，籍贯，电话号码1，电话号码2，电子邮箱组成，姓名可以由字符和数字混合编码。
电话号码可由字符和数字组成。实现功能：
（1）系统以菜单方式工作
（2）信息录入功能
（3）信息浏览功能
4）信息查询功能
（5）信息修改功能
（6）系统退出功能
*/



typedef   struct communication worker;







void menu()                      /*菜单函数*/
{
	printf("\n");

	printf("              通讯信息管理系统\n");
	printf("*******************************************\n");
	printf("           1.信息录入功能\n");
	printf("           2.信息浏览功能\n");
	printf("           3.信息查询功能\n");
	printf("           4.信息修改功能\n");
	printf("           5.系统退出功能\n");
	printf("*******************************************\n");
	printf("\n");

}


int main()
{
	int m=0;//记录录入的人数
	int n, f;    //n为接收的数字（1-5） ，参数f用于判断do_while的循环是否结束 
	while (2)
	{
		do
		{
			menu();
			printf("请输入你需要操作的序号(1-5):\n");
			scanf("%d", &n);
			if (n >= 1 && n <= 5)
			{
				f = 1;
				break;
			}
			else
			{
				f = 0;

				printf("您输入有误，请重新选择!");
			}
		} while (f == 0);

		switch (n)
		{
		case 1:printf("               信息录入功能\n"); printf("\n"); type_in(); break;
		case 2:printf("               信息浏览功能\n"); printf("\n"); system("cls"); scan(); break;
		case 3:printf("               信息查询功能\n"); printf("\n"); system("cls"); search(); break;
		case 4:printf("               信息修改功能\n"); printf("\n"); system("cls"); change(); break;
		case 5:system("cls"); printf("\n\n\n\n\n\n                      ------谢谢使用！！--------- \n"); return 0;
		default:break;
		}

	}
	return 0;
}


/***************************************************************************/
void baocun(int m)  /*保存文件函数*/
{
	int i;
	FILE *fp;
	if ((fp = fopen("worker_list.txt", "wb")) == NULL)  /*创建文件并判断是否能打开*/
	{
		printf("此文件不能打开\n");
		exit(0);
	}
	for (i = 0; i < m; i++)
		if (fwrite(&work[i], sizeof(struct communication), 1, fp) != 1)
			printf("file write error\n");
	fclose(fp);
}


/***********************************************************************************/
void type_in()   /*录入函数*/
{
	int i, m;   //i用于for循环，m用于接收创建的联系人人数（都是局部变量） 
	printf("请输入需要创建信息的联系人人数(1--20):\n");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		printf("请输入姓名:  ");
		scanf("%s", work[i].name);
		getchar();
		printf("请输入籍贯：  ");
		scanf("%s", work[i].natplace);
		printf("请输入电话号码1:  ");
		scanf("%s", work[i].phone_1);
		printf("请输入电话号码2:  ");
		scanf("%s", work[i].phone_2);
		printf("请输入电子邮箱:  ");
		scanf("%s", &work[i].email);
		getchar(); system("cls");
		printf("\n一个联系人的信息档案创建完毕！请输入下一个联系人的信息\n");
		printf("\n");

	}
	baocun(m);
}



/***************************************************************************/


int load()  /*导入函数*/
{
	FILE*fp;
	int i = 0;
	if ((fp = fopen("worker_list.txt", "rb")) == NULL)     //以rb的方式读取文件 
	{
		printf("cannot open file\n");     //提示文件无法打开 
		exit(0);
	}
	else
	{
		do
		{
			fread(&work[i], sizeof(struct communication), 1, fp);
			i++;
		} while (feof(fp) == 0);
	}
	fclose(fp);
	return(i - 1);
}









/*******************************************************************************/
void scan()  /*浏览函数*/
{
	int i;
	int m = load();    //调用load()，用m进行接收，用于for循环判断 
	printf("\n姓名\t籍贯\t电话号码1\t电话号码2\t电子邮箱             \n");
	for (i = 0; i < m; i++)
	
		printf("\n %s\t%s\t  %s\t  %s    \t%s\t\n",work[i].name,
			work[i].natplace,work[i].phone_1, work[i].phone_2, work[i].email);

	printf("按任意键继续\n");
	getchar();
	getchar(); system("cls");
}






/**********************************************************************************/
void search()/*查询函数*/
{
	int t, f;
	do
	{
		printf("\n按姓名查询请按1 ;  返回主页按2\n");
		scanf("%d", &t);
		if (t >= 1 && t <= 3)
		{
			f = 1;
			break;
		}
		else
		{
			f = 0;
			printf("您输入有误，请重新选择!");
		}
	} while (f == 0); system("cls");
	while (f == 1)
	{
		switch (t)
		{
		case 1:printf("按姓名查询\n"); search_name(); break;
		case 2:main(); break;
		default:break;
		}
		system("cls");
	}
}
/***********************************************************************************/
void search_name()/*按姓名查找函数*/
{
	char name1[10];
	int i, t;
	int m = load();
	printf("请输入要查找的姓名:\n");
	scanf("%s", name1);
	for (i = 0; i < m; i++)
		if (strcmp(name1, work[i].name) == 0)  //调用strcmp函数（）进行字符串的比较，如果两字符串相等返回0
		{
			printf("\n已找到此人，其记录为：\n");
			printf("\n姓名\t籍贯\t电话号码1\t电话号码2\t电子邮箱             \n");
			printf("\n %s\t%s\t  %s\t  %s    \t%s\t\n", work[i].name,
				work[i].natplace, work[i].phone_1, work[i].phone_2, work[i].email);
			break;
		}
	if (i == m)
		printf("\n对不起，查无此人\n");
	printf("\n");
	printf("返回查询函数请按1,继续查询联系人请按2\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:search(); break;
	case 2: break;
	default:break;
	}
}







/***************************************************************************************/
void change()  /*修改函数*/
{
	struct communication ks;
	int b, c, i, n, t, f;
	int m = load();                                      /*导入文件内的信息*/
	printf("\n 原来的职工信息:\n");
	scan();
	printf("\n");
	printf("请输入要修改的职工的姓名:\n");
	scanf("%s", ks.name);
	for (f = 1, i = 0; f&&i < m; i++)
	{
		if (strcmp(work[i].name, ks.name) == 0)//从数组中找到和输入相同的名字
		{
			printf("\n已找到此人，其记录为：\n");
			printf("\n姓名\t籍贯\t电话号码1\t电话号码2\t电子邮箱             \n");
			printf("\n %s\t%s\t  %s\t  %s    \t%s\t\n", work[i].name,
				work[i].natplace, work[i].phone_1, work[i].phone_2, work[i].email);
			printf("\n确实要修改此人信息请按1 ; 不修改请按0\n");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("\n需要进行修改的选项\n  1.姓名 2.籍贯 3.电话号码1 4.电话号码2  5.电子邮箱 \n");
				printf("请输入你想修改的那一项序号:\n");
				scanf("%d", &c);
				if (c > 5 || c < 1)
					printf("\n选择错误，请重新选择!\n");
			}
			f = 0;
		}

	}
	if (f == 1)
		printf("\n对不起，信息有误!\n");
	do
	{
		switch (c)
		{

		case 1:printf("姓名改为: ");
			scanf("%s", ks.name);
			strcpy(work[i - 1].name, ks.name);
			break;
		case 2:printf("籍贯改为");
			scanf("%s", ks.natplace);
			strcpy(work[i - 1].natplace, ks.natplace);
			break;
		case 3:printf("电话号码1改为: ");
			scanf("%s",ks.phone_1);
			strcpy(work[i - 1].phone_1, ks.phone_1);
			break;
		case 4:printf("电话号码2改为: ");
			scanf("%s", ks.phone_2);
			strcpy(work[i - 1].phone_2, ks.phone_2);
			break;
		case 5:printf("电子邮箱2改为: ");
			scanf("%s", ks.email);
			strcpy(work[i - 1].email, ks.email);
			break;
	
		}
		printf("\n");
		printf("\n是否确定所修改的信息?\n 是 请按1 ; \n不,重新修改 请按2:  \n");
		scanf("%d", &b);

	} while (b == 2);
	printf("\n浏览修改后的所有联系人信息:\n");
	printf("\n");
	baocun(m);
	scan();
	printf("\n继续修改请按1，不再修改请按0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:change(); break;
	case 0:break;
	default:break;
	}system("cls");
}