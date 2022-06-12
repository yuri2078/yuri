#include <iostream>

class Product
{
private:
    int num; //����Ա���
    int pieces; //����
    double price; //����
    double money; //���۶�

public:
    Product(int num, int pieces, double price);
    void display(void);
    static double allMoney; //�����۶�
    static int allPieces; //�ܼ���
    static int people; //������
};

Product::Product(int num, int pieces, double price)
{
    this->num = num;
    this->pieces = pieces;
    this->price = price;
    if(pieces <= 10)
    {
        money = pieces * price;
    }
    else
    {
        money = pieces * price * 0.98; //����10��0.98��
    }
    allMoney = allMoney + money; //���۶����
    allPieces = allPieces + pieces; //�������
    people++; //������1
}

void Product::display(void)
{
    std::cout << "���" << num << "Ա�������۶��ǣ�" << money << "\n";
}

int Product::allPieces = 0;
double Product::allMoney = 0;
int Product::people = 0;

int main()
{
    Product Prod[3] = {Product(101, 5, 23.5), Product(102, 12, 24.56), Product(103, 100, 21.5)};
    for (int i = 0; i < Product::people;i++)
    {
        Prod[i].display();
    }
    std::cout << "�����ܽ���ǣ�" << Product::allMoney << "\n";
    std::cout << "����ƽ��ֵ�ǣ�" << Product::allMoney / Product::allPieces << "\n";
    return 0;
}