#include <iostream>
class BBank;
class GBank;
class CBank
{
private:
    long long int balance;
public:
    CBank(long long int balance);
    friend long long int BankTotal(CBank *c, BBank *b, GBank *g);
};

CBank::CBank(long long int balance)
{
    this->balance = balance;
}

class BBank
{
private:
    long long int balance;
public:
    BBank(long long int balance);
    friend long long int BankTotal(CBank *c, BBank *b, GBank *g);
};

BBank::BBank(long long int balance)
{
    this->balance = balance;
}

class GBank
{
private:
    long long int balance;
public:
    GBank(long long int balance);
    friend long long int BankTotal(CBank *c, BBank *b, GBank *g);
};

GBank::GBank(long long int balance)
{
    this->balance = balance;
}

long long int BankTotal(CBank *c, BBank *b, GBank *g)
{
    return c->balance + b->balance + g->balance;
}

int main()
{
    long long int money;
    std::cout << "请数您在中国银行的存款额：";
    std::cin >> money;
    CBank c1(money);
    std::cout << "请数您在工商银行的存款额：";
    std::cin >> money;
    BBank b1(money);
    std::cout << "请数您在农业银行的存款额：";
    std::cin >> money;
    GBank g1(money);
    std::cout << "您在三个银行的总存款额为：" << BankTotal(&c1, &b1, &g1);
    return 0;
}