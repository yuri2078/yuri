#include <stdio.h>
#include <windows.h>
#define MODESIZE 100

typedef struct{
	char name[12];//姓名
	char id[8];//ID号
	int salary;//基本工资
	int post_salary;//职务工资
	int subsidy;//岗位津贴
	int insurance;//医疗保险
	int reserved;//公积金
	int end;//结束符号
}worker;


/*

 题目：职工工资管理系统
功能设计要求
1. 输入记录:将每一个职工的姓名、ID号以及基本工资、职务工资、岗位津贴、医疗保险、公积金的数据作为一个记录。•该软件能建立一个新的数据文件或给已建立好的数据文件增加记录。
2. 显示记录:根据用户提供的记录或者根据职工姓名显示一个或几个职工的各项工资和平均工资。
3. 修改记录:可以对数据文件的任意记录的数据进行修改并在修改前后对记录内容进行显示。

*/
worker p[MODESIZE] = {0};//全局记录学生的个数
int workerSize;//全局已经加载的记录学生的个数

void type_in()//输入记录
{
	int i, m;   //i用于for循环，m用于接收创建的联系人人数（都是局部变量） 
	printf("请输入需要创建信息的职工人数最多输入：\t%d人\n" , MODESIZE- workerSize-1);
	scanf("%d", &m);
	for (i = workerSize; i < MODESIZE; i++)
	{

		if (m < MODESIZE - workerSize - 1 && m >= 1) {

		
		printf("请输入姓名:  ");
		scanf("%s", p[i].name);
		getchar();



		printf("请输入ID：  ");
		scanf("%s", p[i].id);


		printf("请输入基本工资:  ");
		scanf("%d", &p[i].salary);


		printf("请输入职务工资:  ");
		scanf("%d", &p[i].post_salary);



		printf("请输入岗位津贴:  ");
		scanf("%d", &p[i].subsidy);

		printf("请输入医疗保险:  ");
		scanf("%d", &p[i].insurance);


		printf("请输入公积金:  ");
		scanf("%d", &p->reserved);
		p[i].end = 20;//文件换行符



		getchar(); system("cls");
		printf("\n一个职工的信息档案创建完毕！请输入下一个职工的信息档案\n");
		system("cls");
		workerSize++;
		m--;
		}
	}
}

void baocun()//显示记录
{
	while (1)
	{


		printf("\t\t1.根据名字查找\n");
		printf("\t\t2.显示浏览所有\n");
		printf("\t\t3.显示平均工资\n");
		printf("\t\t4.返回菜单\n");
		int i = 0;
		scanf("%d", &i);
		switch (i)
		{
		case 1:search_name(); break;
		case 2:display(); break;
		case 3:scoreransalary(); break;
		case 4:return;
		default:
			break;
		}
	}
	
}

void scoreranking()//修改记录
{
	/***************************************************************************************/
 /*修改函数*/
	{
		int c, n,f;
		int m = load();                                      /*导入文件内的信息*/
		printf("\n 原来的职工信息:\n");
		printf("请输入要修改的职工的姓名:\n");
		int len = search_name();//查询到的数据
		printf("\n确实要修改此人信息请按1 ; 不修改请按0\n");
		scanf("%d", &n, 4);
		if (n != 1) { return; }
		while (1)
		{
			printf("\n需要进行修改的选项\n 1.姓名 2.ID 3.基本工资 4.职务工资 5.岗位津贴  6.医疗保险 7.公积金  8.返回菜单\n");
			printf("请输入你想修改的那一项序号:\n");
			scanf("%d", &c, 4);
			if (c > 8 || c < 1) {
				printf("\n选择错误，请重新选择!\n");
				continue;//回到循环
			}
			else {
				break;
			}
		}
			scanf("%d", &f);

			switch (f)
			{
			case 1:printf("姓名改为: ");
				scanf("%s", p[len].name);
				break;
			case 2:printf("ID改为: ");
				scanf("%s", p[len].id);
				break;
			case 3:printf("基本工资改为");
				scanf("%d", &p[len].salary);
				break;
			case 4:printf("职务工资改为: ");
				scanf("%d", &p[len].post_salary);
				break;
			case 5:printf("岗位津贴改为: ");
				scanf("%d", &p[len].subsidy);
				break;
			case 6:printf("医疗保险改为: ");
				scanf("%d", &p[len].insurance);
				break;
			case 7:printf("公积金改为: ");
				scanf("%d", &p[len].reserved);
				break;
			case 8:return;
			}

			printf("\n浏览修改后的所有职工信息:\n");
			printf("\n修改后姓名为%s：ID为%s：基本工资为%d：职位工资为%d：岗位津贴为%d：医疗保险为%s：公积金为%d：",
				p[len].name, p[len].id, p[len].salary, p[len].post_salary, p[len].subsidy, p[len].insurance, p[len].reserved);
		
		system("cls");
		return;

	}
}





void menu()                      /*菜单函数*/
{

	printf("\n");
	printf("              职工工资管理系统\n");
	printf("*******************************************\n");
	printf("           1.输入记录\n");
	printf("           2.显示记录\n");
	printf("           3.修改记录\n");;
	printf("           4.退出系统\n");
	printf("*******************************************\n");
	printf("\n");
}



/***************************************************************************/

int load()  /*导入函数*/
{

	FILE*fp;
	int i = 0;
	fp = fopen("core.txt", "rb");
	if (fp== NULL)     //以rb的方式读取文件 
	{
		printf("core open file\n");     //提示文件无法打开 
		exit(1);
	}
	else
	{
		do
		{
			int size=fread(&p[workerSize], sizeof(worker), 1, fp);//把所有文件都加载到数组里面

			workerSize++;

		} while (feof(fp) ==0);
	}
	workerSize--;
	fclose(fp);
	return(i - 1);

}



/***************************************************************************/
void fobaocun()  /*保存文件函数*/
{
	int i;
	FILE *fp;
	if ((fp = fopen("core.txt", "wb")) == NULL)  /*创建文件并判断是否能打开*/
	{
		printf("core此文件不能打开\n");
		exit(0);
	}
	int size = 0;
	for (i = 0; i<workerSize; i++) {
		int size = fwrite(&p[i], sizeof( worker),1 ,fp);
		if (size != sizeof(worker)) {

			printf("file write error\n");
			printf("文件保存失败");
			system("pause");
			fclose(fp);
			exit(1);//结束程序
			break;
		}

	}
	printf("文件保存成功\n");
	getchar();
	fclose(fp);
}






/**********************************************************************************/
void search()/*查询函数*/
{

	int t, f;
	do
	{
		printf("\n继续查询请按1 ; 返回主页按:2\n");
		scanf("%d", &t);
		if (t >= 1 && t <= 2)
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
		case 1:printf("继续查询\n"); search_name(); break;

		case 2:printf("返回主页\n"); main(); break;
		default:break;
		}
		system("cls");
	}
}
/***********************************************************************************/
int search_name()/*按姓名查找函数*/
{
	int m;
	char name1[10];
	int len;//第多次查找到的
	printf("请输入要查找的姓名:\n");
	scanf("%s", name1);

	for (int i = 0; i < workerSize; i++) {
		if (memcmp(p[i].name, name1, strlen(name1)) == 0)  //匹配名字
		{
			printf("\n已找到此人：\n");
			printf("\n姓名为%s：ID为%s：基本工资为%d：职位工资为%d：岗位津贴为%d：医疗保险为%d：公积金为%d：",
				p[i].name, p[i].id, p[i].salary, p[i].post_salary, p[i].subsidy, p[i].insurance, p[i].reserved);
			m = i;
			getchar();
			return m;
		}

	}

		printf("\n对不起，查无此人\n");
		printf("\n");
		getchar();

	//scoreransalary();//待实现，输出平均工资
	getchar();
	return  m;

}

//分数排名
void scoreransalary(void) {
	worker Score[MODESIZE] = {0};//保存一个职工的所有工作的和
	int kx = 0;
	for (int i = 0; i < workerSize; i++) {
		Score[i] = p[i];

	}


	for (int i = 0; i < workerSize; i++) {//排序
		int top1 = Score[i].salary + Score[i].post_salary + Score[i].subsidy + Score[i].insurance + Score[i].reserved;
		 kx += Score[i].salary + Score[i].post_salary + Score[i].subsidy + Score[i].insurance + Score[i].reserved;
		int top2 = Score[i+1].salary + Score[i+1].post_salary + Score[i+1].subsidy + Score[i+1].insurance + Score[i+1].reserved;
		for (int j = 1; j < workerSize - 1; j++) {
			if (top2 > top1) {
				worker scorer = Score[i];
				Score[i] = Score[j + i];
				Score[j + i] = scorer;
			}

		}

	}
	for (int i = 0; i < workerSize; i++) {
		printf("\n第:%d 姓名为%s：ID为: %s 基本工资为:%d 职位工资为: %d 岗位津贴为:%d 医疗保险为:%d 公积金为:%d\n",
			i,p[i].name, p[i].id, p[i].salary, p[i].post_salary, p[i].subsidy, p[i].insurance, p[i].reserved);

	}
	printf("\n");
	printf("平均工资为:%d元\n", kx / workerSize);
	getchar();
	return;
}

void display() {//显示所有
	for (int i = 0; i < workerSize; i++) {
		printf("\n姓名为%s：ID为%s：基本工资为%d：职位工资为%d：岗位津贴为%d：医疗保险为%d：公积金为%d：\n",
			p[i].name, p[i].id, p[i].salary, p[i].post_salary, p[i].subsidy, p[i].insurance, p[i].reserved);

	}
	getchar();
	system("cls");
}


void main() {
	
	if (workerSize == NULL) {

		 load();//加载文件
	}//程序开始的时候就把文件内容加载到内存
	
	int m = 0;//记录录入的人数
	int n, f;    //n为接收的数字（1-6） ，参数f用于判断do_while的循环是否结束 
	while (1)
	{
		do
		{
			menu();
			printf("请输入你需要操作的序号(1-4):\n");
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
		case 1:printf("           输入记录\n"); printf("\n"); type_in(); break;
		case 2:printf("           显示记录\n"); printf("\n"); system("cls"); baocun(); break;
		case 3:printf("           修改记录\n"); printf("\n"); system("cls"); scoreranking(); exit(1);
		case 4:system("cls");  fobaocun(); printf("\n\n-----谢谢使用！！--------- \n"); printf("\n\n-----已安全保存文件！！--------- \n");  exit(1);
		default:break;
		}

	}

}