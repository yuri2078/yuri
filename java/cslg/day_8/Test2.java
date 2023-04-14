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

class Cylinder {
    double height;
    Circle circle;

    Cylinder(Circle circle, double h) {
        this.circle = circle;
        height = h;
    }

    double getArea() {

        return 2 * circle.getArea() + height * circle.getPerimeter();
    }

    double getVolume() {
        return circle.getArea() * height;
    }
}

public class Test2 {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        double radius = input.nextDouble();
        double height = input.nextDouble();
        Cylinder c = new Cylinder(new Circle(radius), height);
        System.out.printf("%.2f\n", c.getArea());
        System.out.printf("%.2f\n", c.getVolume());
        input.close();
    }
}
