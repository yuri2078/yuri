package cslg.day_9;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

// （1）将各种几何体泛化成形状类Shape,类中有统一的计算面积的抽象接口double getArea();在Shape的子类三角形类Triangle,矩形类Rectangle,圆类Circle中给出计算面积的具体实现；重写各子类的String toString()方法，让其返回“几何体名称：面积”字符串信息。

// （2）定义一个形状数组存放一组几何形体，最后按面积从小到输出。

// （3）面积保留两位小数，提示用静态方法String.format("%.2f",表达式) 对计算结果格式化返回一个字符串，具体如何使用，请查阅相关文档

// （4）已知三角形的三条边a,b,c，可以用海伦公式计算三角形的面积

abstract class Shape {
    public String name;

    public abstract double getArea();
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        super.name = "Circle";
        this.radius = radius;
    }

    public double getArea() {
        String val = String.format("%.2f", Math.PI * radius * radius);
        return Double.parseDouble(val);
    }
}

class Rectangle extends Shape {
    double width;
    double height;

    Rectangle(double width, double height) {
        super.name = "Rectangle";
        this.width = width;
        this.height = height;
    }

    public double getArea() {
        String val = String.format("%.2f", width * height);
        return Double.parseDouble(val);
    }
}

class Triangle extends Shape {
    private double a;
    private double b;
    private double c;

    public double getArea() {
        double s = (a + b + c) / 2;
        String val = String.format("%.2f", Math.sqrt(s * (s - a) * (s - b) * (s - c)));
        return Double.parseDouble(val);
    }

    Triangle(double a, double b, double c) {
        super.name = "Triangle";
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

public class Test1 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = Integer.parseInt(input.nextLine());
        Shape shapes[] = new Shape[n];
        for (int i = 0; i < n; i++) {
            String strs[] = input.nextLine().split("\\s+");
            Double a = 0.0, b = 0.0, c = 0.0;
            a = Double.parseDouble(strs[1]);
            if (strs.length > 2) {
                b = Double.parseDouble(strs[2]);
            }
            if (strs.length > 3) {
                c = Double.parseDouble(strs[3]);
            }
            switch (strs[0].charAt(0)) {
                case 'R': {
                    shapes[i] = new Rectangle(a, b);
                    break;
                }
                case 'T': {
                    shapes[i] = new Triangle(a, b, c);
                    break;
                }
                case 'C': {
                    shapes[i] = new Circle(a);
                    break;
                }

                default:
                    break;
            }
        }
        Arrays.sort(shapes, new Comparator<Shape>() {
            public int compare(Shape x, Shape y) {
                double val = x.getArea() - y.getArea();
                if (val == 0) {
                    return 0;
                }
                return val > 0 ? 1 : -1;
            }
        });

        for (Shape shape : shapes) {
            System.out.printf("%s:%.2f\n", shape.name, shape.getArea());
            // System.out.println(shape.name + ":" + shape.getArea());
        }
        input.close();
    }
}