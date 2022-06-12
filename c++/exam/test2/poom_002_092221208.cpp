#include <iostream>

class CropsYield
{
private:
    float acer_veget, output_per_acerV; //蔬菜
    float acer_fruit, output_per_acerF; //水果
    float acer_grain, output_per_acerG; //稻谷
public:
    CropsYield(float veget, float fruit, float grain); //赋值给成员数据 亩数
    ~CropsYield(); //析构函数
    void SetPerProduct(float veget, float fruit, float grain); //赋值给成员数据 亩产数
    void OutPut(void); //求产量函数
};

CropsYield::CropsYield(float veget, float fruit, float grain)
{
    acer_veget = veget;
    acer_fruit = fruit;
    acer_grain = grain;
}

CropsYield::~CropsYield()
{

}

void CropsYield::SetPerProduct(float veget, float fruit, float grain)
{
    output_per_acerV = veget;
    output_per_acerF = fruit;
    output_per_acerG = grain;
}

void CropsYield::OutPut(void)
{
    std::cout << "蔬菜的产量为: " << acer_veget * output_per_acerV << '\n';
    std::cout << "水果的产量为: " << acer_fruit * output_per_acerF << '\n';
    std::cout << "稻谷的产量为: " << acer_grain * output_per_acerG << '\n';
}

int main()
{
    CropsYield cy(1.2, 2, 3);
    cy.SetPerProduct(500, 400, 700);
    cy.OutPut();
    return 0;
}