package cslg.day_3;

import java.util.Scanner;

public class test7 {

    static void createMartix(int start, int k) {
        int martix[][] = new int[k][k];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= i; j++) {
                martix[j][i] = start++;
            }

            for (int j = i - 1; j >= 0; j--) {
                martix[i][j] = start++;
            }
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                System.out.printf("%4d", martix[i][j]);
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        createMartix(input.nextInt(), input.nextInt());
        input.close();
    }
}
