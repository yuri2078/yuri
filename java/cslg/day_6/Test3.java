package cslg.day_6;

import java.util.Scanner;

// 1、 getPerimeter返回矩形的周长
// 2 、getArea返回矩形的面积
// 3 、getDiagonal返回矩形对角线长度
// 4 、isSquare 返回是否是正方形
// 5 、show()  用image.png形式画出该长方形，如果该矩形是边长为1的正方形，则打印图形为*

class Rectangle {
    int x, y;

    Rectangle() {
        x = y = 1;
    }
    
    Rectangle(int width) {
        x = y = width;
    }

    Rectangle(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getPerimeter() {
        return 2 * (x + y);
    }

    public int getArea() {
        return x * y;
    }

    public double getDiagonal() {
        return Math.sqrt(x * x + y * y);
    }

    public boolean isSquare() {
        return x == y;
    }

    public void show() {
        if (x == 1 && y == 1) {
            System.out.println('*');
            return;
        }

        if (x == 1) {
            System.out.print("*\n".repeat(y));
            return;
        }

        if (y == 1) {
            System.out.println("*".repeat(x));
            return;
        }

        for (int i = 0; i < y; i++) {
            StringBuffer str = new StringBuffer("*");
            if ( i == 0 || i == y - 1) {
                str.append("*".repeat(x - 2));
            } else {
                str.append(" ".repeat(x - 2));
            }
            str.append('*');
            System.out.println(str);
        }
    }
}

public class Test3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int w = in.nextInt();
        int h = in.nextInt();
        Rectangle r = new Rectangle(w, h);
        System.out.println(r.getPerimeter());
        System.out.println(r.getArea());
        System.out.printf("%.2f\n", r.getDiagonal());
        System.out.println(r.isSquare());
        r.show();

        in.close();
    }
}