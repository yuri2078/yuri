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

            int? nullable_int = null; //可空类型 在多余的基础上多了null类型
            Console.WriteLine("nullable_int :{0}|", nullable_int); //啥都没有，不是空格
            int? nullable_int_2 = new int?();
            Console.WriteLine(nullable_int_2);
            int x_6 = nullable_int ?? 666; //如果为null则返回后面那个值


            //数组

            int[] array = {1, 2,4,5}; //声明数组
            int[][] array_tao;
            int[,] array_2;
            array_tao = new int[5][]; //定义桥套数组
            array_tao[0] = array; //嵌套数组赋值
            array = new int[10]; //实例化数组
            array_2 = new int[10, 10]; //申请二维数组
            array = new int[4] { 10, 20, 30, 40 }; //他的长度必须精确
            // array = new int[5] { 10, 20, 30, 40 }; //他的长度必须精确 这里报错

            int[] temp = array; //他们会指向同一个地方 统一块内存区域
            Console.WriteLine(" array[0] : {0}", array[0]);
            Console.WriteLine(" temp[0] : {0}", temp[0]);
            array[0] = 6666;
            Console.WriteLine(" array[0] : {0}", array[0]);
            Console.WriteLine(" temp[0] : {0}", temp[0]);
            
        }
   }
}