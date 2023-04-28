package cslg.day_10;

import java.util.Scanner;

public class Test3 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        double r = sc.nextDouble();

        RoundTable t1 = new RoundTable(3, 100, r);
        System.out.println("Area=" + t1.getArea());
        sc.close();
    }
}

interface MoveAble {
    public void move();
}

abstract class TableInfo implements MoveAble {
    int legs;
    int hight;

    public TableInfo(int legs, int hight) {
        this.legs = legs;
        this.hight = hight;
    }

    public void move() {
        System.out.println("被人搬动了！");
    }
}

interface CalculateAble {
    public double getArea();
}

class RoundTable extends TableInfo implements CalculateAble {
    private double r;

    public RoundTable(int legs, int hight, double r) {
        super(legs, hight);
        this.r = r;
    }

    public double getArea() {
        double a = 0;
        try {
            a = test(r);
        } catch (AreaException e) {
            System.out.println("Exception  is:  " + e);
        }
        return a;
    }

    private double test(double r) throws AreaException {
        if (r <= 0) {
            throw new AreaException("Round  table  radius<=0");
        }
        return 3.14 * r * r;
    }
}

class AreaException extends Exception {
    String error;

    AreaException(String error) {
        this.error = error;
    }

    public String toString() {
        return "AreaException: " + error;
    }
}