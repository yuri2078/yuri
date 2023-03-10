package cslg.day_3;

import java.util.Arrays;
import java.util.Scanner;

/**
 * test5
 */
public class test5 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int arrays[] = new int[40], len = 0;
        for (String s : str.split("\\s+")) {
            arrays[len++] = Integer.parseInt(s);
        }

        str = input.nextLine();
        for (String s : str.split("\\s+")) {
            arrays[len++] = Integer.parseInt(s);
        }

        int num[][] = new int[2][len];
        num[0] = Arrays.copyOf(arrays, len);
        Arrays.sort(num[0]);

        for (int i = 1; i < len; i++) {
            if (num[0][i] == num[0][i - 1]) {
                num[1][i] = num[1][i - 1] = 1;
            }
        }

        for (int i = len - 1; i >= 0; i--) {
            if (num[1][i] == 0) {
                System.out.print(num[0][i] + " ");
            }
        }

        System.out.println();
        
        for (int i = len - 1; i >= 0; i--) {
            if (num[1][i] == 1) {
                num[1][i] = num[1][i - 1] = 0;
                System.out.print(num[0][i] + " ");
            }
        }

        System.out.println();

        
        input.close();
    }
}
