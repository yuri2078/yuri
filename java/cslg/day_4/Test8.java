package cslg.day_4;

import java.util.*;

public class Test8 {
    static Scanner in = new Scanner(System.in);

    static String delimitedString(String x, char start, char end) {
        int i, m = -1, n = -1;
        for (i = 0; i < x.length(); i++) {
            if (x.charAt(i) == start)
                m = i;
            if (x.charAt(i) == end)
                n = i;
        }
        if (n != -1 && n < m)
            return null;
        if (n == -1)
            return x.substring(m, x.length());
        else
            return x.substring(m, n + 1);
            // int new_start = x.lastIndexOf(start);
            // int new_end = x.lastIndexOf(end) + 1;
            // if(new_end == 0) {
            //   new_end = x.length();
            // }

            // if(new_start == -1 || new_start >= new_end) {
            //   return null;
            // }
            // return x.substring(new_start,new_end);

    }

    public static void main(String[] args) {
        String x, mod;
        char begin, end;
        x = in.nextLine();
        mod = in.nextLine();
        begin = mod.charAt(0);
        end = mod.charAt(1);
        String y;
        y = delimitedString(x, begin, end);
        if (y != null)
            System.out.println(y);
    }
}