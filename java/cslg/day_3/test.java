package cslg.day_3;

import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String s[] = str.split("\\s+");
        for (int i = 0; i < s.length; i++) {
            int x = Integer.parseInt(s[i]);
            System.out.println(x);
        }
        input.close();
    }
}
