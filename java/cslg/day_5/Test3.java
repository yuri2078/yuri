package cslg.day_5;

import java.util.Scanner;

public class Test3 {
    static String change(String str) {
        StringBuffer buffer = new StringBuffer("");
        for (char c = str.charAt(0); c < str.charAt(2); c++) {
            buffer.append(c);
        }
        return buffer.toString();
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int pos = -1, start = 0;
        while ((pos = str.indexOf('-', start)) != -1) {
            if (pos > 0 && pos < str.length() - 1) {
                char front = str.charAt(pos - 1);
                char back = str.charAt(pos + 1);
                boolean flag = false;
                if (Character.isLowerCase(front) && Character.isLowerCase(back)) {
                    flag = true;
                }

                if (Character.isUpperCase(front) && Character.isUpperCase(back)) {
                    flag = true;
                }

                if (Character.isDigit(front) && Character.isDigit(back)) {
                    flag = true;
                }

                if (flag) {
                    str = str.replace(str.substring(pos - 1, pos + 1), change(str.substring(pos - 1, pos + 2)));
                }
            }

            start = pos + 1;

        }

        System.out.println(str);

        input.close();
    }
}
