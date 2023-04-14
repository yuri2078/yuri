package cslg.day_8;

import java.util.Scanner;

class Rect {
    protected double width;
    protected double height;

    public Rect() {
        width = height = 10;
    }

    public Rect(double width, double height) {
        this.width = width;
        this.height = height;
    }

    // （1) 求矩形面积的方法getArea()
    // （2) 求矩形周长的方法getPerimeter()

    public double getArea() {
        return width * height;
    }

    public double getPerimeter() {
        return 2 * (width + height);
    }
}

class PlainRect extends Rect {
    private double startX;
    private double startY;

    public PlainRect(double startX, double startY, double width, double height) {
        super(width, height);
        this.startY = startX;
        this.startY = startY;
    }

    public PlainRect() {
        super();
        startX = startY = 0;
    }

    boolean isInside(double x, double y) {
        boolean is_x = x > startX && x < (startX + width);
        boolean is_y = y < startY && y > (startY - height);
        return is_x && is_y;
    }
}

public class Test5 {
    private static Scanner reader;

    public static void main(String[] args) {
        PlainRect rect;
        double x, y, w, h;
        int n;
        reader = new Scanner(System.in);
        n = reader.nextInt();
        for (int i = 0; i < n; i++) {
            x = reader.nextDouble();
            y = reader.nextDouble();
            w = reader.nextDouble();
            h = reader.nextDouble();
            rect = new PlainRect(x, y, w, h);
            x = reader.nextDouble();
            y = reader.nextDouble();
            System.out.println(rect.getArea() + "," + rect.getPerimeter() + "," + rect.isInside(x, y));
        }
        rect = new PlainRect();
        System.out.println(rect.getArea() + "," + rect.getPerimeter() + "," + rect.isInside(0, 0));
    }
}