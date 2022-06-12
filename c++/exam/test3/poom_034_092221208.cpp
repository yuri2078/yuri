#include <iostream>
class Cun_product
{
private:
    double veget_result;
    double fruit_result;
    double grain_result;

public:
    friend Cun_product operator+(const Cun_product &c2);
    Cun_product()
    {
        veget_result = fruit_result = grain_result = 0 ;
    }
    
    ~Cun_product()
    {

    }

    Cun_product(double veget_result, double fruit_result, double grain_result)
    {
        this->veget_result = veget_result;
        this->fruit_result = fruit_result;
        this->grain_result = grain_result;
    }

    void output(void)
   {
       std::cout << "乡村农作物产量如下\n";
       std::cout << "蔬菜总产量是" << veget_result << "\n";
       std::cout << "水果总产量是" << fruit_result << "\n";
       std::cout << "稻谷总产量是" << grain_result << "\n";
   }

   Cun_product operator+ (const Cun_product c2)
   {
       Cun_product c;
       c.veget_result = this->veget_result + c2.veget_result;
       c.fruit_result = this->fruit_result + c2.fruit_result;
       c.grain_result = this->grain_result + c2.grain_result;
       return c;
   }

};
int main()
{
    Cun_product cun_A(1.2, 3, 4);
    Cun_product cun_B(2.3, 5, 1);
    Cun_product cun_C(1.4, 3, 2);
    Cun_product cun_D(3.5, 1, 4);
    Cun_product cun_E = cun_A + cun_B + cun_C + cun_D;
    cun_E.output();
    return 0;
}