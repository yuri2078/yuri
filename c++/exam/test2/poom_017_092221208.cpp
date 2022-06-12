#include <iostream>

class Product
{
private:
    int num; //销售员编号
    int pieces; //件数
    double price; //单价
    double money; //销售额

public:
    Product(int num, int pieces, double price);
    void display(void);
    static double allMoney; //总销售额
    static int allPieces; //总件数
    static int people; //总人数
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
        money = pieces * price * 0.98; //超过10件0.98折
    }
    allMoney = allMoney + money; //销售额相加
    allPieces = allPieces + pieces; //件数相加
    people++; //人数加1
}

void Product::display(void)
{
    std::cout << "编号" << num << "员工，销售额是：" << money << "\n";
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
    std::cout << "销售总金额是：" << Product::allMoney << "\n";
    std::cout << "销售平均值是：" << Product::allMoney / Product::allPieces << "\n";
    return 0;
}