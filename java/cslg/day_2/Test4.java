package cslg.day_2;

import java.util.Scanner;

public class Test4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        toFraction(input.nextDouble());
        input.close();
    }

    // 0.35
    static void toFraction(double x) {
        String str = "" + x;
        boolean flag = true;
        int integer = 0, molecule = 0, molecule_len = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '.') {
                flag = false;
                continue;
            }
            if (flag) {
                integer = integer * 10 + str.charAt(i) - 48;
            } else {
                molecule_len++;
                molecule = molecule * 10 + str.charAt(i) - 48;
            }
        }
        int denominator = (int) Math.pow(10, molecule_len);
        int front = gys(molecule, denominator);
        System.out.printf("%d %d %d\n", integer, molecule / front, denominator / front);

    }

    static int gys(int x, int y) {
        int n = x;
        while ((x % n) != 0 || (y % n) != 0) {
            n--;
        }
        return n;
    }
}
