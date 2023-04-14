package cslg.day_8;

import java.util.Scanner;

class Circle {
    private double radius;

    public Circle() {
        radius = 0;
    }

    public Circle(double r) {
        radius = r;
    }

    double getArea() {
        return Math.PI * radius * radius;
    }

    double getPerimeter() {
        return 2 * Math.PI * radius;
    }
}

class Cylinder extends Circle {
    double height;

    Cylinder(double r, double h) {
        super(r);
        height = h;
    }

    double getArea() {

        return 2 * super.getArea() + height * getPerimeter();
    }

    double getVolume() {
        return super.getArea() * height;
    }
}

public class Test1 {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        double radius = input.nextDouble();
        double height = input.nextDouble();

        Cylinder c = new Cylinder(radius, height);
        System.out.printf("%.2f\n", c.getArea());
        System.out.printf("%.2f\n", c.getVolume());
        input.close();
    }
}
