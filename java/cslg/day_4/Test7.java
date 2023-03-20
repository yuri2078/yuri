package cslg.day_4;

import java.util.*;

class Test7 {
    static Scanner in = new Scanner(System.in);

    static String[] delimitedString(String x, char begin, char end) {
        String strs[] = new String[1000];
        int count = 0, start = 0;
        while (start < x.length()) {
            int new_start = x.indexOf(begin, start);
            int new_end = x.indexOf(end, start);
            if (new_start == -1 || new_end == -1) {
                break;
            }
            strs[count++] = x.substring(new_start, new_end + 1);
            start = new_end + 1;
        }

        return Arrays.copyOf(strs, count);
    }

    public static void main(String[] args) {
        int n;
        String x, mod;
        char begin, end;
        x = in.nextLine();
        mod = in.nextLine();
        begin = mod.charAt(0);
        end = mod.charAt(1);
        String[] y;
        y = delimitedString(x, begin, end);
        if (y != null) {
            for (int i = 0; i < y.length; i++) {
                System.out.println(y[i]);
            }
        }
    }
}