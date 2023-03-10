package cslg.day_3;

import java.util.Scanner;
import java.util.Arrays;

public class test4 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt(), max_ = 1;
		int num[][] = new int[2][n];
		for (int i = 0; i < n; i++) {
			num[0][i] = input.nextInt();
		}

		Arrays.sort(num[0]);
		num[1][0] = 1;
		for (int i = 1; i < n; i++) {
			if (num[0][i] == num[0][i - 1] + 1) {
				num[1][i] = num[1][i - 1] + 1;
			} else {
				num[1][i] = 1;
			}

			if (max_ < num[1][i]) {
				max_ = num[1][i];
			}
		}

		System.out.println(max_);
		for (int i = 0; i < n; i++) {
			if (num[1][i] == max_) {
				for (int j = i - max_ + 1; j <= i; j++) {
					System.out.print(num[0][j] + " ");
				}
				System.out.println();
			}
		}
		input.close();
	}
}
