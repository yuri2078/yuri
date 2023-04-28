package cslg.day_10;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Test1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        try{
            int x = input.nextInt();
            int y = input.nextInt();
            System.out.println(x / y);
        } catch (InputMismatchException e) {
            System.out.println("format error");
        } catch (ArithmeticException e) {
            System.out.println("0 error");
        }finally {
            System.out.println("over");
        }
        input.close();
    }
}
