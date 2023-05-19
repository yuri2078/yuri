package cslg.day_12;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Test1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(input.nextInt());
        }

        ArrayList<Integer> list = new ArrayList<>(set);
        Collections.sort(list);
        for (int x : list) {
            System.out.print(x + " ");
        }
        System.out.println();

        input.close();
    }
}
