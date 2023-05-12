package cslg.day_11;

import java.util.ArrayList;
import java.util.Scanner;

public class Test2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int k = input.nextInt();

        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(1);
        }

        int count = 0;
        int index = 0;
        int num = 1;

        while (count < n - 1) {
            if (list.get(index) == 1 && (num % k == 0 || num % 10 == k)) {
                list.set(index, 0);
                num++;
                count++;
            }
            num += list.get(index);
            index = (index + 1) % n;
        }

        for (int i = 0; i < n; i++) {
            if (list.get(i) == 1) {
                System.out.println(i + 1);
            }
        }
        input.close();

    }
}
