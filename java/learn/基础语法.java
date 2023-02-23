package learn; // 包名

public class 基础语法 { // 类名需要和文件名保持一致
    public static void main(String[] args) {
        System.out.println("基础语法练习!"); // 打印字符串

        int[] array = new int[10]; // 创建数组
        array[1] = 666;
        for (int i : array) {
            if (i == 6) {
                break;
            }
        }

        for (int i = 0; i < array.length; i++) {
            
        }
        System.out.print('\n');
    }
    
    // 基本数据类型-关键字
    public void baseData() {
        byte a = 0; // byte：-128 ~ 127
        short b = 0; // short: -32768 ~ 32767
        int c = 0; // int: -2147483648 ~ 2147483647 --- float
        long d = 0; // -9223372036854775808 ~ 9223372036854775807 ---- double
        boolean e = true; // bool类型   
        String str = "yuri"; // 字符串类型 他的本质是引用，不同于c++ 
        final double PI = 3.14159; // 常量类型关键字 不可修改
        var s = new String(); // 自动类型推导 auto 运算符
        float f = (float) a; // 类型强转
        String more_str = """
                这是第一行 // 有个换行
                这是第二行 // 有个换行
                """; // 这也有个换行

        // 打印东西，结果报错难看
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
        System.out.println(e);
        System.out.println(str);
        System.out.println(PI);
        System.out.println(s);
        System.out.println(f);
        System.out.println(more_str);

        // 整数运算在除数为0时会报错，而浮点数运算在除数为0时，不会报错，但会返回几个特殊值
        // NaN表示Not a Number 0 / 0
        // Infinity表示无穷大 1.0 / 0
        // -Infinity表示负无穷大 -1.0 / 0

        // 别的东西参考c++

    }
    

}