#include<stdio.h>
#include<Windows.h>

struct communication {
	char name[16];
	char natplace[8];//����
	char phone_1[12];//�绰����1
	char phone_2[12];//�绰����2
	char email[20];//��������
	int end;//���ݽ���
	
}work[20], work1;

void menu()                      /*�˵�����*/
{
	printf("\n");

	printf("              ͨѶ��Ϣ����ϵͳ\n");
	printf("*******************************************\n");
	printf("           1.��Ϣ¼�빦��\n");
	printf("           2.��Ϣ�������\n");
	printf("           3.��Ϣ��ѯ����\n");
	printf("           4.��Ϣ�޸Ĺ���\n");
	printf("           5.ϵͳ�˳�����\n");
	printf("*******************************************\n");
	printf("\n");

}

/***************************************************************************/
void baocun(int m)  /*�����ļ�����*/
{
	int i;
	FILE *fp;
	if ((fp = fopen("worker_list.txt", "wb")) == NULL)  /*�����ļ����ж��Ƿ��ܴ�*/
	{
		printf("���ļ����ܴ�\n");
		exit(0);
	}
	for (i = 0; i < m; i++)
		if (fwrite(&work[i], sizeof(struct communication), 1, fp) != 1)
			printf("file write error\n");
	fclose(fp);
}

/***********************************************************************************/
void type_in()   /*¼�뺯��*/
{
	int i, m;   //i����forѭ����m���ڽ��մ�������ϵ�����������Ǿֲ������� 
	printf("��������Ҫ������Ϣ����ϵ������(1--20):\n");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		printf("����������:  ");
		scanf("%s", work[i].name);
		getchar();
		printf("�����뼮�᣺  ");
		scanf("%s", work[i].natplace);
		printf("������绰����1:  ");
		scanf("%s", work[i].phone_1);
		printf("������绰����2:  ");
		scanf("%s", work[i].phone_2);
		printf("�������������:  ");
		scanf("%s", &work[i].email);
		getchar(); system("cls");
		printf("\nһ����ϵ�˵���Ϣ����������ϣ���������һ����ϵ�˵���Ϣ\n");
		printf("\n");

	}
	baocun(m);
}

/***************************************************************************/

int load()  /*���뺯��*/
{
	FILE*fp;
	int i = 0;
	if ((fp = fopen("worker_list.txt", "rb")) == NULL)     //��rb�ķ�ʽ��ȡ�ļ� 
	{
		printf("cannot open file\n");     //��ʾ�ļ��޷��� 
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
void scan()  /*�������*/
{
	int i;
	int m = load();    //����load()����m���н��գ�����forѭ���ж� 
	printf("\n����\t����\t�绰����1\t�绰����2\t��������             \n");
	for (i = 0; i < m; i++)
	
		printf("\n %s\t%s\t  %s\t  %s    \t%s\t\n",work[i].name,
			work[i].natplace,work[i].phone_1, work[i].phone_2, work[i].email);

	printf("�����������\n");
	getchar();
	getchar(); system("cls");
}

/**********************************************************************************/
void search()/*��ѯ����*/
{
	int t, f;
	do
	{
		printf("\n��������ѯ�밴1 ;  ������ҳ��2\n");
		scanf("%d", &t);
		if (t >= 1 && t <= 3)
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
			case 1:printf("��������ѯ\n"); search_name(); break;
			case 2:main(); break;
			default:break;
		}
		system("cls");
	}
}

/***********************************************************************************/
void search_name()/*���������Һ���*/
{
	char name1[10];
	int i, t;
	int m = load();
	printf("������Ҫ���ҵ�����:\n");
	scanf("%s", name1);
	for (i = 0; i < m; i++)
		if (strcmp(name1, work[i].name) == 0)  //����strcmp�������������ַ����ıȽϣ�������ַ�����ȷ���0
		{
			printf("\n���ҵ����ˣ����¼Ϊ��\n");
			printf("\n����\t����\t�绰����1\t�绰����2\t��������             \n");
			printf("\n %s\t%s\t  %s\t  %s    \t%s\t\n", work[i].name,
				work[i].natplace, work[i].phone_1, work[i].phone_2, work[i].email);
			break;
		}
	if (i == m)
		printf("\n�Բ��𣬲��޴���\n");
	printf("\n");
	printf("���ز�ѯ�����밴1,������ѯ��ϵ���밴2\n");
	scanf("%d", &t);
	switch (t)
	{
		case 1:search(); break;
		case 2: break;
		default:break;
	}
}

/***************************************************************************************/
void change()  /*�޸ĺ���*/
{
	struct communication ks;
	int b, c, i, n, t, f;
	int m = load();                                      /*�����ļ��ڵ���Ϣ*/
	printf("\n ԭ����ְ����Ϣ:\n");
	scan();
	printf("\n");
	printf("������Ҫ�޸ĵ�ְ��������:\n");
	scanf("%s", ks.name);
	for (f = 1, i = 0; f&&i < m; i++)
	{
		if (strcmp(work[i].name, ks.name) == 0)//���������ҵ���������ͬ������
		{
			printf("\n���ҵ����ˣ����¼Ϊ��\n");
			printf("\n����\t����\t�绰����1\t�绰����2\t��������             \n");
			printf("\n %s\t%s\t  %s\t  %s    \t%s\t\n", work[i].name,
				work[i].natplace, work[i].phone_1, work[i].phone_2, work[i].email);
			printf("\nȷʵҪ�޸Ĵ�����Ϣ�밴1 ; ���޸��밴0\n");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("\n��Ҫ�����޸ĵ�ѡ��\n  1.���� 2.���� 3.�绰����1 4.�绰����2  5.�������� \n");
				printf("�����������޸ĵ���һ�����:\n");
				scanf("%d", &c);
				if (c > 5 || c < 1)
					printf("\nѡ�����������ѡ��!\n");
			}
			f = 0;
		}

	}
	if (f == 1)
		printf("\n�Բ�����Ϣ����!\n");
	do
	{
		switch (c)
		{

		case 1:printf("������Ϊ: ");
			scanf("%s", ks.name);
			strcpy(work[i - 1].name, ks.name);
			break;
		case 2:printf("�����Ϊ");
			scanf("%s", ks.natplace);
			strcpy(work[i - 1].natplace, ks.natplace);
			break;
		case 3:printf("�绰����1��Ϊ: ");
			scanf("%s",ks.phone_1);
			strcpy(work[i - 1].phone_1, ks.phone_1);
			break;
		case 4:printf("�绰����2��Ϊ: ");
			scanf("%s", ks.phone_2);
			strcpy(work[i - 1].phone_2, ks.phone_2);
			break;
		case 5:printf("��������2��Ϊ: ");
			scanf("%s", ks.email);
			strcpy(work[i - 1].email, ks.email);
			break;
	
		}
		printf("\n");
		printf("\n�Ƿ�ȷ�����޸ĵ���Ϣ?\n �� �밴1 ; \n��,�����޸� �밴2:  \n");
		scanf("%d", &b);

	} while (b == 2);
	printf("\n����޸ĺ��������ϵ����Ϣ:\n");
	printf("\n");
	baocun(m);
	scan();
	printf("\n�����޸��밴1�������޸��밴0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:change(); break;
	case 0:break;
	default:break;
	}system("cls");
}

int main()
{
	int m=0;//��¼¼�������
	int n, f;    //nΪ���յ����֣�1-5�� ������f�����ж�do_while��ѭ���Ƿ���� 
	while (1)
	{
		do
		{
			menu();
			printf("����������Ҫ���������(1-5):\n");
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
		case 1:printf("               ��Ϣ¼�빦��\n"); printf("\n"); type_in(); break;
		case 2:printf("               ��Ϣ�������\n"); printf("\n"); system("cls"); scan(); break;
		case 3:printf("               ��Ϣ��ѯ����\n"); printf("\n"); system("cls"); search(); break;
		case 4:printf("               ��Ϣ�޸Ĺ���\n"); printf("\n"); system("cls"); change(); break;
		case 5:system("cls"); printf("\n\n\n\n\n\n                      ------ллʹ�ã���--------- \n"); return 0;
		default:break;
		}

	}
	return 0;
}
