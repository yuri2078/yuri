package cslg.day_11;

import java.util.Scanner;
import java.util.Vector;

public class Test1 {

    static void inputData(Vector<Integer> vec, Scanner input) {
        int num = input.nextInt();
        while (num != -1) {
            vec.add(num);
            num = input.nextInt();
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Vector<Integer> A = new Vector<>();
        Vector<Integer> B = new Vector<>();
        inputData(A, input);
        inputData(B, input);

        Vector<Integer> temp = new Vector<>(A);
        temp.retainAll(B);

        A.removeAll(temp);
        for (int i : A) {
            System.out.print(i + " ");
        }
        System.out.println();
        input.close();
    }
}
