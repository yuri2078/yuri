package cslg.day_3;

import java.util.Scanner;

public class test6 {
    static int check(String str, int[][] num) {
        int pos = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) != '*') {
                num[str.charAt(i) - 48 - 1][i] = 1;
                pos += str.charAt(i) - 48;
            }
        }
        int x = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 - pos - 1, y = str.indexOf('*');
        num[x][y] = 1;

        for (int i = 0; i < 8; i++) {
            if (i != x && num[i][y] == 1 || i != y && num[x][i] == 1) {
                return -1;
            }
        }

        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (num[i][j] == 1) {
                return -1;
            }
        }

        for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
            if (num[i][j] == 1) {
                return -1;
            }
        }

        for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
            if (num[i][j] == 1) {
                return -1;
            }
        }

        for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++) {
            if (num[i][j] == 1) {
                return -1;
            }
        }

        return x + 1;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int num[][] = new int[8][8], pos = 0;
        pos = check(str, num);
        if (pos == -1) {
            System.out.println("No Answer");
        } else {
            System.out.println(pos);
        }
        input.close();
    }
}
