package cslg.day_5;

import java.util.Scanner;

class Main {
    public static int countCode(String str) {
        int i, j, count = 0;
        for (i = 0; i < str.length() - 3; i++) {
            if (str.charAt(i) == 'c' && str.charAt(i + 1) == 'o' && str.charAt(i + 3) == 'e') {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        String s;
        Scanner input = new Scanner(System.in);
        s = input.nextLine();
        System.out.println(countCode(s));
        input.close();
    }

}