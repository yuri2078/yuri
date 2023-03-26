package cslg.day_5;

import java.util.*;

public class Ex4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        String[] words = str.split("\\D+");
        int i, j, x, f, sum;
        int[] num = new int[100];
        for (i = 0; i < words.length; i++) {
            if (!words[i].isEmpty()) {
                if (words[i].charAt(0) == '0')
                    f = 1;
                else
                    f = -1;
                sum = 0;
                x = 1;
                for (j = words[i].length() - 1; j > 0; j--) {
                    sum += x * (words[i].charAt(j) - '0');
                    x *= 2;
                }
                num[i] = sum * f;
            }

        }
        int[] n = Arrays.copyOf(num, words.length);
        Arrays.sort(n);
        for (i = 0; i < words.length; i++)
            System.out.printf("%d ", n[i]);
    }
}

// ...111100.01111.01100111...0111..110000.011..