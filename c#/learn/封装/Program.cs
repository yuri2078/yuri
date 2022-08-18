using System;
namespace 封装
{
    class DataMumber
    {
        public int x_1 = 1; //大家都能访问
        private int x_2 = 2; //只能类中访问
        protected int x_3 = 3; //派生类也可以访问
        internal int x_4 = 4; //同一个程序集可以访问
        protected internal int x_5 = 5; //访问限于当前程序集或派生自包含类的类型。

    }
    class test_1
    {
        static void Main(string[] args)
        {
            DataMumber test = new DataMumber();
            Console.WriteLine("你好捏!");
            Console.WriteLine(test.x_1);
            // Console.WriteLine(test.x_2);  //不可访问
            // Console.WriteLine(test.x_3);  //不可访问
            Console.WriteLine(test.x_4);
            Console.WriteLine(test.x_5);

            方法 n = new 方法(); //需要实例化一个对象才能调用该方法
            Console.WriteLine("444 和 666 中 {0} 最大\n", n.max(444, 666));
            n.dtob(16);

            int x = 222;
            int y = 222;
            Console.WriteLine("调用函数前 x : {0} y : {1} ", x, y);
            n.changeValue(out x, out y);
            Console.WriteLine("调用函数后 x : {0} y : {1} ", x, y);

            int[] array = new int[5] { 1,2,3,4,5};
            //数组作为函数参数
            n.arrayFun(array);
            Console.WriteLine("嵌套数组作为参数");

            int[][] array_tao= new int[5][]{ array, new int[] {2,4}, new int[] {5,6}, new int[]{7,8}, new int[]{9,10} };
            n.arrayTaoFun(array_tao);

            Console.WriteLine("二维数组作为参数");
            int[,] erweiArray = new int[5, 3] { { 1, 3, 4 }, { 1, 3, 4 }, { 1, 3, 4 },{ 1, 3, 4 },  { 1, 3, 4 } };
            n.twoArray(erweiArray);
            Console.WriteLine("常量数组作为参数");
            n.sum(1, 2, 3, 4, 5, 5);
        }
    }

    class 方法
    {
        //值传递
        public int max(int x, int y)
        {
            return x > y ? x : y;
        }

        public void dtob(int x)
        {
            if (x > 0)
            {
                dtob(x / 2);
                Console.WriteLine("{0}", x % 2); //可以递归调用
            }
        }

        //引用传递
        public void swap(ref int x, ref int y)
        {
            int temp = x;
            x = y;
            y = temp;
        }

        //可以修改原来的值
        public void changeValue(out int x, out int y)
        {
            x = 666;
            y = 777;
        }

        //数组作为参数
        public void arrayFun(int[] arr)
        {
            foreach(int i in arr){
                Console.WriteLine(i);
            }
        }


        // 嵌套数组作为参数
        public void arrayTaoFun(int[][] arr)
        {
            foreach(int[] i in arr)
            {
                foreach(int j in i){
                    Console.WriteLine(j);
                }
            }
        }

        // 二维数组作为参数
        public void twoArray(int [,]arr)
        {
            foreach(int i in arr)
            {
                Console.WriteLine(i);
            }
        }

        //支持常量数组
        public int sum(params int[] arr)
        {
            int s = 0;
            foreach(int i in arr){
                s += i;
            }
            return s;
        }
    }
}