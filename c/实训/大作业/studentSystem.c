#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int COUNT = 5;

typedef struct
{
	int number;
	char name[20];
	float score_c;
	float score_stb;
	float score_sql;
	float score_avg;
} Student;

void printMenu(void)
{
	printf("\n");
	printf("\t\t******************学生管理系统*******************\n");
	printf("\t\t******** 0、退出系统       1、信息录入   ********\n");
	printf("\t\t******** 2、信息浏览       3、信息排序   ********\n");
	printf("\t\t******** 4、信息查询       5、信息清屏   ********\n");
	printf("\t\t******** 6、信息删除       7、保持对齐   ********\n");
	printf("\n");

}

void inputInformation(Student *student)
{
	printf("输入学生学号:");
	scanf("%d", &student[COUNT].number);
	printf("输入学生名字:");
	scanf("%s", student[COUNT].name);
	printf("输入学生std分数:");
	scanf("%f", &student[COUNT].score_stb);
	printf("输入学生c语言分数:");
	scanf("%f", &student[COUNT].score_c);
	printf("输入学生SQL分数:");
	scanf("%f", &student[COUNT].score_sql);
	COUNT++;
}

void showInformation(Student *student)
{
	int i;
	for(i = 0; i < COUNT; i++)
	{
		student[i].score_avg = (student[i].score_c + student[i].score_sql + student[i].score_stb) / 3;
		printf("学号 : %-5d  姓名 : %-10s stb分数: %5.1f c语言分数: %5.1f SQL分数: %5.1f 平均分: %5.1f\n", student[i].number,
			student[i].name, student[i].score_stb, student[i].score_c, student[i].score_sql, student[i].score_avg);
	}
}

void sortInformation(Student *student)
{
	int n = 1, f = 1, i, j, flag;
	printf("\n");
	printf("\t\t******************请选择排序方式*******************\n");
	printf("\t\t******** 1、按学号   2、按姓名   3、按平均分 ********\n");
	printf("请选择:");
	scanf("%d", &n);
	printf("请选择升降序( 1、升序 2、降序 ) :");
	scanf("%d", &f);
	for (i = 0; i < COUNT -1;i++)
	{
		for (j = i + 1; j < COUNT;j++)
		{
			switch (n)
			{
			case 1 : flag = (f == 1 ? student[i].number > student[j].number : student[i].number < student[j].number); break;
			case 2 : flag = (f == 1 ? strcmp(student[i].name, student[j].name) > 0 : strcmp(student[i].name, student[j].name) < 0); break;
			case 3 : flag = (f == 1 ? student[i].score_avg > student[j].score_avg : student[i].score_avg < student[j].score_avg);break;
			default: break;
			}
			if(flag)
			{
				Student temp;
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
		}
	}
}

int searchInformation(Student *student)
{
	int n = 1, i = 0, number;
	char name[20];

	do
	{
		printf("\n");
		printf("\t\t******************请选择查询方式*******************\n");
		printf("\t\t******** 1、按学号   2、按姓名   3、退出 ********\n");
		printf("请选择:");
		scanf("%d", &n);
		switch (n)
		{
		case 1 :{
			printf("请输入他的学号:");
			scanf("%d", &number);
			for (i = 0; i < COUNT;i++){
				if(number == student[i].number){
					break;
				}
			}
			break;
		}
		case 2 :{
			printf("请输入他的姓名:");
			scanf("%s", name);
			for (i = 0; i < COUNT;i++){
				if(strcmp(name, student[i].name) == 0){
					break;
				}
			}
			break;
		}
		default:
			return 0;
		}
		
		if(i != COUNT){
			printf("\n学号 : %-5d  姓名 : %-10s stb分数: %5.1f c语言分数: %5.1f SQL分数: %5.1f 平均分: %5.1f\n", student[i].number,
				student[i].name, student[i].score_stb, student[i].score_c, student[i].score_sql, student[i].score_avg);
		}
		else{
			printf("\n\n没有找到捏!\n\n");
		}
	} while (1);
	
}

int delInformation(Student *student)
{
	int n = 1, i = 0, number;
	char name[20];

	do
	{
		printf("\n");
		printf("\t\t******************请选择删除方式*******************\n");
		printf("\t\t******** 1、按学号   2、按姓名   3、退出 ********\n");
		printf("请选择:");
		scanf("%d", &n);
		switch (n)
		{
		case 1 :{
			printf("请输入他的学号:");
			scanf("%d", &number);
			for (i = 0; i < COUNT;i++){
				if(number == student[i].number){
					break;
				}
			}
			break;
		}
		case 2 :{
			printf("请输入他的姓名:");
			scanf("%s", name);
			for (i = 0; i < COUNT;i++){
				if(strcmp(name, student[i].name) == 0){
					break;
				}
			}
			break;
		}
		default:
			return 0;
		}
		
		if(i != COUNT)
		{
			printf("已删除!");
			COUNT--;
			for (; i < COUNT && i < 49; i++){
				student[i] = student[i + 1];
			}
		}
		else{
			printf("\n\n没有找到捏!\n\n");
		}
	} while (1);
	
}

void chooseMenu(int x, Student *student)
{
	switch(x)
	{
		case 1 : inputInformation(student); break;
		case 2 : showInformation(student); break;
		case 3 : sortInformation(student); break;
		case 4 : searchInformation(student); break;
		case 5 : system("clear");break;
		case 6 : delInformation(student);break;
		default: break;
	}
}

void welcome(Student *student)
{
	int x;
	do
	{
		printMenu();
		printf("请选择:");
		scanf("%d", &x);
		chooseMenu(x, student);
	}while(x);
}

int main(void)
{
	Student student[50] = {
		{1001, "yuri", 66.6, 77, 55},
		{1002, "hello", 55, 91, 80},
		{1003, "world", 80, 70, 94},
		{1004, "vim", 67.5, 77, 44},
		{1005, "ubantu", 92, 88, 94} };	
	welcome(student);
	return 0;
}
