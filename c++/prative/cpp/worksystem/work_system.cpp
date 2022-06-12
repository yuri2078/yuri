#include <iostream>
#include <cstring>
#include <fstream>
class Worker
{
public:
    char name[20];
    char sex[10];
    int age;
    int num;
    char post[20];
    char duty[20];

public:
    friend std::ostream &operator<<(std::ostream &cout, const Worker &w);
    friend std::ofstream &operator<<(std::ofstream &ofs, const Worker &w);
    friend std::istream &operator>>(std::istream &cin, Worker &w);
    Worker()
    {
        strcpy(this->name,"张三");
        strcpy(this->sex, "男");
        this->age = 18;
        this->num = 1000;
        strcpy(this->post, "普通员工");
        strcpy(this->duty, "干活就行");
    }

};

std::ostream & operator<< (std::ostream &cout, const Worker *w)
{
    std::cout << "编号: " << w->num << "  姓名：" << w->name << "  年龄：" << w->age;
    std::cout << "   性别：" << w->sex << "   职位：" << w->post << "   职责：" << w->duty << "\n";
    return std::cout;
}

std::ofstream &operator<<(std::ofstream &ofs, Worker *w)
{
    ofs.write((const char *)w, sizeof(Worker));
    return ofs;
}

std::istream & operator>> (std::istream &cin, Worker *w)
{
    int f = 3;
    char sex[2][10] = {"男", "女"};
    char post[3][20] = {"普通员工", "员工经理", "员工老板"};
    char duty[3][20] = {"干活就行", "分配任务", "等着拿钱"};
    std::cout << "请输入员工的编号:";
    std::cin >> w->num;
    std::cout << "请输入员工的姓名:";
    std::cin >> w->name;
    while (f != 1 && f != 2)
    {
        std::cout << "请选择他的性别 : 1、" << sex[0] << "  2、" << sex[1] << "\n请选择：";
        std::cin >> f;
    }
    strcpy(w->sex, sex[f-1]);
    std::cout << "请输入员工的年龄:";
    std::cin >> w->age;
    f = 5;
    while (f != 1 && f != 2 && f !=3)
    {
        std::cout << "请选择他的职位 : 1、" <<  post[0] << "  2、" << post[1]  << "  3、" << post[2] << "\n请选择：";
        std::cin >> f;
    }
    strcpy(w->post, post[f-1]);
    strcpy(w->duty, duty[f-1]);
    std::cout << "收录结束！\n";
    return std::cin;
}

int start_system(void)
{
    Worker *w;
    int len = 0;
    int f = 8;
    for (int i = 0; i < 25;i++)
    {
        std::cout << "*";
    }
    std::cout << "\n 欢迎来到员工管理系统\n";
    std::fstream file;
    file.open("worker_system.txt", std::ios::in);
    if(!file.is_open())
    {
        file.open("worker_system.txt", std::ios::out);
        file.close();
        file.open("worker_system.txt", std::ios::in);
        if(!file.is_open())
        {
            std::cout << "糟糕，出问题了！";
            return 0;
        }
    }
    while(file.get() != EOF)
    {
        len++;
    }
    len = len / sizeof(Worker);
    file.clear();
    file.seekg(0, std::ios::beg);
    file.close();
    while(f)
    {
        switch (f)
        {
            case 1: 
            {
                if(len == 0)
                {
                    std::cout << "\n\n\n\n没有数据你查看个棒槌!\n\n\n";
                }
                else
                {
                    char temp[sizeof(Worker)];
                    file.open("worker_system.txt", std::ios::in | std::ios::binary);
                    for (int i = 0; i < len;i++)
                    {
                        file.seekg( i * sizeof(Worker),std::ios::beg);
                        file.read(temp, sizeof(Worker));
                        w = (Worker *)temp;
                        std::cout << w;
                    }
                    file.close();
                }
                f = 8;
                break;
            };
            case 2: 
            {
                file.open("worker_system.txt", std::ios::app | std::ios::binary);
                Worker *temp = new Worker;
                std::cin >> temp;
                file.write((const char *)temp, sizeof(Worker));
                len++;
                file.close();
                f = 8;
                break;
            };
            case 3: 
            {
                int num, flag = 1;
                std::cout << "\n请输入你想要删除的员工的编号吧：";
                std::cin >> num;
                char temp[sizeof(Worker)];
                file.open("worker_system.txt", std::ios::in | std::ios::binary);
                for (int i = 0; i < len;i++)
                {
                    file.seekg( i * sizeof(Worker),std::ios::beg);
                    file.read(temp, sizeof(Worker));
                    w = (Worker *)temp;
                    if(w->num == num)
                    {
                        std::cout << "\n找到了捏! 是下面的数据吗？ 是否删除?\n\n" << w << "\n";
                        char ch = 'w';
                        while(ch != 'y' && ch != 'n')
                        {
                            std::cout << "删除请按 y ，取消请按 n :";
                            std::cin >> ch;
                        }

                        if(ch == 'y')
                        {
                            std::fstream temp_wirte,temp_read;
                            temp_wirte.open("temp.txt", std::ios::out | std::ios::binary);
                            temp_read.open("worker_system.txt", std::ios::in | std::ios::binary);
                            for (int i = 0; i < len;i++)
                            {
                                char temp[sizeof(Worker)];
                                Worker *change;
                                temp_read.seekg( i * sizeof(Worker),std::ios::beg);
                                temp_read.read(temp, sizeof(Worker));
                                change = (Worker *)temp;
                                if(change->num != w->num)
                                {
                                    temp_wirte.write(temp, sizeof(Worker));
                                }
                                std::cout << w;
                            }
                            len--;
                            temp_read.close();
                            temp_wirte.close();
                            temp_read.open("temp.txt", std::ios::in | std::ios::binary);
                            temp_wirte.open("worker_system.txt", std::ios::out | std::ios::binary);
                            for (int i = 0; i < len;i++)
                            {
                                char temp[sizeof(Worker)];
                                temp_read.seekg( i * sizeof(Worker),std::ios::beg);
                                temp_read.read(temp, sizeof(Worker));
                                temp_wirte.write(temp, sizeof(Worker));
                                std::cout << w;
                            }
                            temp_read.close();
                            temp_wirte.close();
                            std::cout << "\n已经删除成功了捏！\n";
                        }
                        else 
                        {
                            std::cout << "\n已经取消删除了捏！\n";
                        }
                        file.close();
                        flag = 0;
                        break;
                    }
                }
                f = 8;
                if(flag)
                    std::cout << "\n\n找不到捏!\n\n";
                break;
            };
            case 4: 
            {
                f = 0;
                break;
            };
            case 5: 
            {
                f = 8;
                break;
            };
            case 6: 
            {
                f = 8;
                break;
            };
            case 7: 
            {
                f = 8;
                break;
            };
            
            default: 
            {
                std::cout << "\n1、显示所有员工信息\n2、增加新员工\n3、删除员工\n4、退出管理系统\n";
                std::cout << "5、查找员工信息\n6、修改员工信息\n7、对员工信息进行排序\n";
                std::cout << "请选择你的来意:";
                std::cin >> f;
                break;
            };
        }
    }
    file.close();
    return 0;
}

int main()
{
    
    start_system();
    return 0;
}