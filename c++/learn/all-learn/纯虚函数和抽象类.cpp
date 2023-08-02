#include <iostream>
class Base
  {
  public:
    virtual void play(void) = 0;
    //在虚函数的基础上加上 = 0 则为纯虚函数
    //他无法实例化对象 无论堆区 还是 栈区
    //有有一个纯虚函数则称之为 抽象类
    //他的子类也不能创建实例 除非重写纯虚类
  };

class Test1 : public Base
  {
  };

class Test2 : public Base
  {
  public:
    virtual void play(void)
    {
      std::cout << "hello\n";
    }
  };

void test()
{
  // Base b1;  //报错，不可以实例化对象
  // new Base; //报错，不可以实例化对象
  // Test1 t1; //报错，不可以实例化对象
  Test2 t2; //没报错，可以实例化对象
}


int main()
{
  return 0;
}
