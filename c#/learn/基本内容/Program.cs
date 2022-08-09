using System;  //包含命名空间
namespace HelloWorldApplication //定义命名空间
{
   class HelloWorld //定义类
   {
      static void Main(string[] args) //主程序入口 有且只能有一个
      {
         Console.WriteLine("Hello World\n");  //输出一个字符串
         Console.WriteLine("我的年龄是: {0} 岁\n", 66); //格式化输出字符
         Convert.ToInt64(44); //通过内置函数转换
         // Console.ReadLine(); //接收一行数据

//各种数据类型
         Console.WriteLine("sizeof int {0}\n", sizeof(int));
         Console.WriteLine("sizeof double {0}\n", sizeof(double));
         Console.WriteLine("sizeof float {0}\n", sizeof(float));
         Console.WriteLine("sizeof decimal {0}\n", sizeof(decimal));

         //对象object 是所有类型的终极类
         object obj = 666; //装箱
         int x = (int)obj; //拆箱
         Console.WriteLine("ojb = {0} x = {1} \n", obj, x);

         //动态存储类型 dynamic 运行是检查值
         dynamic name = "张三";
         Console.WriteLine("name = {0}\n", name);

         //String 字符串类型 加上@ 则表示把转移字符当普通字符对待
         String string_1 = @"https://2078.site
         他甚至可以换行
         换行符号算在字符窜长度中";
         Console.WriteLine("string_1 = {0}\n", string_1);

         //宝贝指针 以后在说

         //类型转换
         int x_zhuan = (int)555.4; //强制转化
         String y_zhuan = x_zhuan.ToString(); //内置函数转换

         foreach(char i in y_zhuan) //foreach迭代可迭代对象
         {
            Console.WriteLine("{0}  ", i);
         }

         
         
//其他
         

      }
   }
}