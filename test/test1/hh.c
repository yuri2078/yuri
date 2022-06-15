#include <stdio.h>
#include <windows.h>
#define MODESIZE 100

typedef struct{
	char name[12];//����
	char id[8];//ID��
	int salary;//��������
	int post_salary;//ְ����
	int subsidy;//��λ����
	int insurance;//ҽ�Ʊ���
	int reserved;//������
	int end;//��������
}worker;


/*

 ��Ŀ��ְ�����ʹ���ϵͳ
�������Ҫ��
1. �����¼:��ÿһ��ְ����������ID���Լ��������ʡ�ְ���ʡ���λ������ҽ�Ʊ��ա��������������Ϊһ����¼��?������ܽ���һ���µ������ļ�����ѽ����õ������ļ����Ӽ�¼��
2. ��ʾ��¼:�����û��ṩ�ļ�¼���߸���ְ��������ʾһ���򼸸�ְ���ĸ���ʺ�ƽ�����ʡ�
3. �޸ļ�¼:���Զ������ļ��������¼�����ݽ����޸Ĳ����޸�ǰ��Լ�¼���ݽ�����ʾ��

*/
worker p[MODESIZE] = {0};//ȫ�ּ�¼ѧ���ĸ���
int workerSize = 0;//ȫ���Ѿ����صļ�¼ѧ���ĸ���

void type_in()//�����¼
{
	int i, m;   //i����forѭ����m���ڽ��մ�������ϵ�����������Ǿֲ������� 
	printf("��������Ҫ������Ϣ��ְ������������룺\t%d��\n" , MODESIZE- workerSize-1);
	scanf("%d", &m);
	for (i = workerSize; i < MODESIZE; i++)
	{

		if (m < MODESIZE - workerSize - 1 && m >= 1) {

		
		printf("����������:  ");
		scanf("%s", p[i].name);
		getchar();



		printf("������ID��  ");
		scanf("%s", p[i].id);


		printf("�������������:  ");
		scanf("%d", &p[i].salary);


		printf("������ְ����:  ");
		scanf("%d", &p[i].post_salary);



		printf("�������λ����:  ");
		scanf("%d", &p[i].subsidy);

		printf("������ҽ�Ʊ���:  ");
		scanf("%d", &p[i].insurance);


		printf("�����빫����:  ");
		scanf("%d", &p->reserved);
		p[i].end = 20;//�ļ����з�



		getchar(); system("cls");
		printf("\nһ��ְ������Ϣ����������ϣ���������һ��ְ������Ϣ����\n");
		system("cls");
		workerSize++;
		m--;
		}
	}
}

void baocun()//��ʾ��¼
{
	while (1)
	{


		printf("\t\t1.�������ֲ���\n");
		printf("\t\t2.��ʾ�������\n");
		printf("\t\t3.��ʾƽ������\n");
		printf("\t\t4.���ز˵�\n");
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

void scoreranking()//�޸ļ�¼
{
	/***************************************************************************************/
 /*�޸ĺ���*/
	{
		int c, n,f;
		int m = load();                                      /*�����ļ��ڵ���Ϣ*/
		printf("\n ԭ����ְ����Ϣ:\n");
		printf("������Ҫ�޸ĵ�ְ��������:\n");
		int len = search_name();//��ѯ��������
		printf("\nȷʵҪ�޸Ĵ�����Ϣ�밴1 ; ���޸��밴0\n");
		scanf("%d", &n);
		if (n != 1) { return; }
		while (1)
		{
			printf("\n��Ҫ�����޸ĵ�ѡ��\n 1.���� 2.ID 3.�������� 4.ְ���� 5.��λ����  6.ҽ�Ʊ��� 7.������  8.���ز˵�\n");
			printf("�����������޸ĵ���һ�����:\n");
			scanf("%d", &c);
			if (c > 8 || c < 1) {
				printf("\nѡ�����������ѡ��!\n");
				continue;//�ص�ѭ��
			}
			else {
				break;
			}
		}
			scanf("%d", &f);

			switch (f)
			{
			case 1:printf("������Ϊ: ");
				scanf("%s", p[len].name);
				break;
			case 2:printf("ID��Ϊ: ");
				scanf("%s", p[len].id);
				break;
			case 3:printf("�������ʸ�Ϊ");
				scanf("%d", &p[len].salary);
				break;
			case 4:printf("ְ���ʸ�Ϊ: ");
				scanf("%d", &p[len].post_salary);
				break;
			case 5:printf("��λ������Ϊ: ");
				scanf("%d", &p[len].subsidy);
				break;
			case 6:printf("ҽ�Ʊ��ո�Ϊ: ");
				scanf("%d", &p[len].insurance);
				break;
			case 7:printf("�������Ϊ: ");
				scanf("%d", &p[len].reserved);
				break;
			case 8:return;
			}

			printf("\n����޸ĺ������ְ����Ϣ:\n");
			printf("\n�޸ĺ�����Ϊ%s��IDΪ%s����������Ϊ%d��ְλ����Ϊ%d����λ����Ϊ%d��ҽ�Ʊ���Ϊ%s��������Ϊ%d��",
				p[len].name, p[len].id, p[len].salary, p[len].post_salary, p[len].subsidy, p[len].insurance, p[len].reserved);
		
		system("cls");
		return;

	}
}


void menu()                      /*�˵�����*/
{

	printf("\n");
	printf("              ְ�����ʹ���ϵͳ\n");
	printf("*******************************************\n");
	printf("           1.�����¼\n");
	printf("           2.��ʾ��¼\n");
	printf("           3.�޸ļ�¼\n");;
	printf("           4.�˳�ϵͳ\n");
	printf("*******************************************\n");
	printf("\n");
}

/***************************************************************************/


int load()  /*���뺯��*/
{

	FILE*fp;
	int i = 0;
	fp = fopen("core.txt", "wb+");
	if (fp == NULL)     //��rb�ķ�ʽ��ȡ�ļ� 
	{
		printf("core open file\n");     //��ʾ�ļ��޷��� 
		exit(1);
	}
	else
	{
		do
		{
			int size=fread(&p[workerSize], sizeof(worker), 1, fp);//�������ļ������ص���������

			workerSize++;

		} while (feof(fp) ==0);
	}
	workerSize--;
	fclose(fp);
	return(i - 1);
}


/***************************************************************************/
void fobaocun()  /*�����ļ�����*/
{
	int i;
	FILE *fp;
	if ((fp = fopen("core.txt", "wb")) == NULL)  /*�����ļ����ж��Ƿ��ܴ�*/
	{
		printf("core���ļ����ܴ�\n");
		exit(0);
	}
	int size = 0;
	for (i = 0; i<workerSize; i++) {
		int size = fwrite(&p[i], sizeof( worker),1 ,fp);
		if (size != sizeof(worker)) {

			printf("file write error\n");
			printf("�ļ�����ʧ��");
			system("pause");
			fclose(fp);
			exit(1);//��������
			break;
		}

	}
	printf("�ļ�����ɹ�\n");
	getchar();
	fclose(fp);
}


/**********************************************************************************/
void search()/*��ѯ����*/
{

	int t, f;
	do
	{
		printf("\n������ѯ�밴1 ; ������ҳ��:2\n");
		scanf("%d", &t);
		if (t >= 1 && t <= 2)
		{
			f = 1;
			break;
		}
		else
		{
			f = 0;
			printf("����������������ѡ��!");
		}
	} while (f == 0); system("cls");
	while (f == 1)
	{
		switch (t)
		{
		case 1:printf("������ѯ\n"); search_name(); break;

		case 2:printf("������ҳ\n"); main(); break;
		default:break;
		}
		system("cls");
	}
}
/***********************************************************************************/
int search_name()/*���������Һ���*/
{
	int m;
	char name1[10];
	int len;//�ڶ�β��ҵ���
	printf("������Ҫ���ҵ�����:\n");
	scanf("%s", name1);

	for (int i = 0; i < workerSize; i++) {
		if (memcmp(p[i].name, name1, strlen(name1)) == 0)  //ƥ������
		{
			printf("\n���ҵ����ˣ�\n");
			printf("\n����Ϊ%s��IDΪ%s����������Ϊ%d��ְλ����Ϊ%d����λ����Ϊ%d��ҽ�Ʊ���Ϊ%d��������Ϊ%d��",
				p[i].name, p[i].id, p[i].salary, p[i].post_salary, p[i].subsidy, p[i].insurance, p[i].reserved);
			m = i;
			getchar();
			return m;
		}

	}

		printf("\n�Բ��𣬲��޴���\n");
		printf("\n");
		getchar();

	//scoreransalary();//��ʵ�֣����ƽ������
	getchar();
	return  m;

}

//��������
void scoreransalary(void) {
	worker Score[MODESIZE] = {0};//����һ��ְ�������й����ĺ�
	int kx = 0;
	for (int i = 0; i < workerSize; i++) {
		Score[i] = p[i];

	}


	for (int i = 0; i < workerSize; i++) {//����
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
		printf("\n��:%d ����Ϊ%s��IDΪ: %s ��������Ϊ:%d ְλ����Ϊ: %d ��λ����Ϊ:%d ҽ�Ʊ���Ϊ:%d ������Ϊ:%d\n",
			i,p[i].name, p[i].id, p[i].salary, p[i].post_salary, p[i].subsidy, p[i].insurance, p[i].reserved);

	}
	printf("\n");
	printf("ƽ������Ϊ:%dԪ\n", kx / workerSize);
	getchar();
	return;
}

void display() {//��ʾ����
	for (int i = 0; i < workerSize; i++) {
		printf("\n����Ϊ%s��IDΪ%s����������Ϊ%d��ְλ����Ϊ%d����λ����Ϊ%d��ҽ�Ʊ���Ϊ%d��������Ϊ%d��\n",
			p[i].name, p[i].id, p[i].salary, p[i].post_salary, p[i].subsidy, p[i].insurance, p[i].reserved);

	}
	getchar();
	system("cls");
}


void main() {
	
	if (workerSize == 0) {

		 load();//�����ļ�
	}//����ʼ��ʱ��Ͱ��ļ����ݼ��ص��ڴ�
	
	int m = 0;//��¼¼�������
	int n, f;    //nΪ���յ����֣�1-6�� ������f�����ж�do_while��ѭ���Ƿ���� 
	while (1)
	{
		do
		{
			menu();
			printf("����������Ҫ���������(1-4):\n");
			scanf("%d", &n);
			if (n >= 1 && n <= 5)
			{
				f = 1;
				break;
			}
			else
			{
				f = 0;

				printf("����������������ѡ��!");
			}
		} while (f == 0);

		switch (n)
		{
		case 1:printf("           �����¼\n"); printf("\n"); type_in(); break;
		case 2:printf("           ��ʾ��¼\n"); printf("\n"); system("cls"); baocun(); break;
		case 3:printf("           �޸ļ�¼\n"); printf("\n"); system("cls"); scoreranking(); exit(1);
		case 4:system("cls");  fobaocun(); printf("\n\n-----ллʹ�ã���--------- \n"); printf("\n\n-----�Ѱ�ȫ�����ļ�����--------- \n");  exit(1);
		default:break;
		}

	}

}