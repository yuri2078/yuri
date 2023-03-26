package cslg.day_5;

// ...111100.01111.01100111...0111..110000.011..

import java.util.Scanner;
import java.util.Arrays;

public class Test4 {

    static int change(String str) {
        int flag = str.charAt(0) == '0' ? 1 : -1;
        int sum = 0, x = 1;
        for (int i = str.length() - 1; i > 0; i--) {
            sum += x * (str.charAt(i) - 48);
            x = x * 2;
        }

        return sum * flag;
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int num[] = new int[100], len = 0;
        for (String s : input.nextLine().split("\\D+")) {
            if (s.length() != 0) {
                num[len++] = change(s);
            }
        }
        int number[] = Arrays.copyOf(num, len);
        Arrays.sort(number);
        for (int i = 0; i < len; i++) {
            System.out.print(number[len - i - 1] + " ");
        }

        input.close();
    }
}
