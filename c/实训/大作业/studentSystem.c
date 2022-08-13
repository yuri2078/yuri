#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int COUNT = 5; //定义全局变量 用来统计个数

//定义学生类结构体
typedef struct
{
	int number; //学号
	char name[20]; //姓名
	float score_c; //c语言分数
	float score_stb; //stb分数
	float score_sql; //SQL分数
	float score_avg; //平均分
} Student;

//打印菜单
void printMenu(void)
{
	printf("\n");
	printf("\t\t******************学生管理系统*******************\n");
	printf("\t\t******** 0、退出系统       1、信息录入    ********\n");
	printf("\t\t******** 2、信息浏览       3、信息排序    ********\n");
	printf("\t\t******** 4、信息查询       5、信息清屏    ********\n");
	printf("\t\t******** 6、信息删除       7、指定插入    ********\n");
	printf("\n");
}

//数据录入
void inputInformation(Student *student)
{
	//防止出现数据超出存储最大值
	if(COUNT == 50){
		printf("存储信息已达最大值，请删除后重新存储!");
	}
	else
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
		COUNT++; //每录入一个数据， count加1
	}
}

//指定位置插入数据
void locationInsert(Student *student)
{
	int location;
	printf("请输入你想要插入的位置:");
	scanf("%d", &location);
	//防止出现位置越界行为
	location > COUNT ? location = COUNT : 1;
	//先接收数据，后移动数据
	inputInformation(student);
	
	Student temp = student[COUNT - 1];
	int i;
	//循环右移直到指定位置
	for (i = COUNT - 1; i != location && i > 0;i--){
		student[i] = student[i - 1];
	}
	//将数据插入到指定位置
	student[location] = temp;
}

//展示已有数据
void showInformation(Student *student)
{
	int i;
	for(i = 0; i < COUNT; i++)
	{
		//初始化平均分
		student[i].score_avg = (student[i].score_c + student[i].score_sql + student[i].score_stb) / 3;
		printf("学号 : %-5d  姓名 : %-10s stb分数: %5.1f c语言分数: %5.1f SQL分数: %5.1f 平均分: %5.1f\n", student[i].number, \
			student[i].name, student[i].score_stb, student[i].score_c, student[i].score_sql, student[i].score_avg);
	}
}

//排序函数
void sortInformation(Student *student)
{
	int n = 1, f = 1, i, j, flag = 0;
	printf("\n");
	printf("\t\t******************请选择排序方式*******************\n");
	printf("\t\t******** 1、按学号   2、按姓名   3、按平均分 ********\n");
	printf("请选择:");
	scanf("%d", &n);
	printf("请选择升降序( 1、升序 2、降序 ) :");
	scanf("%d", &f);
	//顺序排序法排序
	for (i = 0; i < COUNT -1;i++)
	{
		for (j = i + 1; j < COUNT;j++)
		{
			//通过 n 判断排序条件
			switch (n)
			{
			//通过哦flag 判断是否需要交换
			//通过 f 判断升序还是降序
			case 1 : flag = (f == 1 ? student[i].number > student[j].number : student[i].number < student[j].number); break;
			case 2 : flag = (f == 1 ? strcmp(student[i].name, student[j].name) > 0 : strcmp(student[i].name, student[j].name) < 0); break;
			case 3 : flag = (f == 1 ? student[i].score_avg > student[j].score_avg : student[i].score_avg < student[j].score_avg);break;
			default: break;
			}
			//满足条件则交换数据
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

//查找信息 函数 查找是否有符合条件的学生信息
int searchInformation(Student *student)
{
	int n = 1, i = 0, number;
	char name[20];
	//循环查找 由用户决定继续查找
	do
	{
		printf("\n");
		printf("\t\t******************请选择查询方式*******************\n");
		printf("\t\t******** 1、按学号   2、按姓名   3、退出 ********\n");
		printf("请选择:");
		scanf("%d", &n);
		switch (n)
		{
			//由学号查找
		case 1 :{
			printf("请输入他的学号:");
			scanf("%d", &number); //输入学号
			//循环查找
			for (i = 0; i < COUNT;i++){
				if(number == student[i].number){
					//找到则返回
					break;
				}
			}
			break;
		}
		//由姓名查找
		case 2 :{
			printf("请输入他的姓名:");
			scanf("%s", name); //输入姓名
			//循环查找
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
			//找到则打印数据
			student[i].score_avg = (student[i].score_c + student[i].score_sql + student[i].score_stb) / 3; //先赋值，防止未打印前输出数据
			printf("\n学号 : %-5d  姓名 : %-10s stb分数: %5.1f c语言分数: %5.1f SQL分数: %5.1f 平均分: %5.1f\n", student[i].number, \
				student[i].name, student[i].score_stb, student[i].score_c, student[i].score_sql, student[i].score_avg);
		}
		else{
			printf("\n\n没有找到捏!\n\n");
		}
	} while (1);
}

//删除信息函数 删除用户指定的信息
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
		//由学号决定是否删除
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
		//由姓名决定是否删除
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
		
		//找到则删除
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

//通过输入的数据调用不同函数
void chooseMenu(int x, Student *student)
{
	switch(x)
	{
		case 1 : inputInformation(student); break; //录入信息函数
		case 2 : showInformation(student); break; //浏览信息函数
		case 3 : sortInformation(student); break; //排序函数
		case 4 : searchInformation(student); break; //查找函数
		case 5 : system("cls"); break;  //清屏函数 system("clear");
		case 6 : delInformation(student);break; //删除信息函数
		case 7 : locationInsert(student);break; //指定位置插入函数
	}
}

//欢迎界面
void welcome(Student *student)
{
	int x;
	do
	{
		//循环打印菜单直到退出函数
		printMenu();
		printf("请选择:");
		scanf("%d", &x);
		chooseMenu(x, student); //通过输入 选择调用合适的函数
	}while(x);
}

int main(void)
{
	//默认的5个数据
	Student student[50] = {
		{1001, "yuri", 66.6, 77, 55},
		{1002, "hello", 55, 91, 80},
		{1003, "world", 80, 70, 94},
		{1004, "vim", 67.5, 77, 44},
		{1005, "ubantu", 92, 88, 94}};
	
	//调用欢迎函数
	welcome(student);
	return 0;
}
