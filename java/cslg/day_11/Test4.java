package cslg.day_11;

import java.util.HashMap;
import java.util.Scanner;

public class Test4 {

	static void move(HashMap<Integer, Integer> map, int[] num, int x, int k) {
		int flag = 1;
		if(k < 0) {
			k = -k;
			flag = -1;
		}
		for(int i = 0; i < k; i++) {
			int pos = map.get(x);
			int val = num[pos + flag];

			num[pos] = val;
			num[pos + flag] = x;

			map.put(val, pos);
			map.put(x, pos + flag);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
	  int n = input.nextInt();
		HashMap<Integer, Integer> map = new HashMap<>();
		int num[] = new int[n + 1], times = input.nextInt();
		for(int i = 1; i <= n; i++) {
      num[i] = i;
			map.put(i, i);
		}
		for(int i = 0; i < times; i++) {
			int x = input.nextInt();
			int k = input.nextInt();
			move(map, num, x, k);
		}		

		for(int i = 1; i <= n; i++) {
			System.out.print(num[i] + " ");
		}
		System.out.println();
		input.close();
	}
}
