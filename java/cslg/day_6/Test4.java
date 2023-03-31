package cslg.day_6;

import java.util.Scanner;
// /成员变量

// 两个int类型的变量分别表示分子和分母。
// 1、Fraction(int a,int b); //两个参数的构造方法，构造一个a/b的分数。
// 2、double toDouble(); //将分数转换为double
// 3、Fraction plus(Fraction r);//将自己和分数r相加，产生一个新的Fraction的对象。注意小学四年级学过两个分数如何相加的
// 4、Fraction multiply(Fraction r);//将自己和分数r相乘，产生一个新的Fraction的对象。
// 5、void print(); //将自己以“分子/分母”的形式输出到标准输出，并带有回车换行。如果分数是1/1，应该输出1。当分子大于分母时，不需要提出整数部分，即31/30是一个正确的输出。

class Fraction {
    int molecular; // 分子
    int denominator; // 分母

    Fraction(int a, int b) {
        int x = gys(a, b);
        a = a / x;
        b = b / x;
        molecular = a;
        denominator = b;
    }

    double toDouble() {
        return (double) molecular / denominator;
    }

    Fraction plus(Fraction r) {
        int new_denominator = gbs(this.denominator, r.denominator);
        int new_molecular = molecular * (new_denominator / denominator)
                + r.molecular * (new_denominator / r.denominator);
        return new Fraction(new_molecular, new_denominator);
    }

    Fraction multiply(Fraction r) {
        return new Fraction(this.molecular * r.molecular, this.denominator * r.denominator);
    }

    void print() {
        if (molecular != denominator) {
            System.out.println(molecular + "/" + denominator);
        } else {
            System.out.println(1);
        }
    }

    int gbs(int x, int y) {
        int n = x;
        while ((n % x) != 0 || (n % y) != 0) {
            n++;
        }
        return n;
    }

    int gys(int x, int y) {
        int n = x;
        while ((x % n) != 0 || (y % n) != 0) {
            n--;
        }
        return n;
    }
}

public class Test4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Fraction a = new Fraction(in.nextInt(), in.nextInt());
        Fraction b = new Fraction(in.nextInt(), in.nextInt());
        a.print();
        b.print();
        a.plus(b).print();
        a.multiply(b).plus(new Fraction(5, 6)).print();
        System.out.printf("%.2f\n", a.toDouble());
        System.out.printf("%.2f\n", b.toDouble());
        in.close();
    }
}
