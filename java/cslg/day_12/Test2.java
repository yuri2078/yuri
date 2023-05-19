package cslg.day_12;

import java.util.Scanner;
import java.util.TreeMap;

public class Test2 {

	static void getData(TreeMap<Integer, Integer> map, Scanner input) {
		int n = input.nextInt();
		for (int i = 0; i < n; i++) {
			int x = input.nextInt();
			Integer val = map.get(x);
			if (val == null) {
				map.put(x, 1);
			} else {
				map.put(x, val.intValue() + 1);
			}
		}
	}

	static boolean check(TreeMap<Integer, Integer> map_1, TreeMap<Integer, Integer> map_2) {
		if(map_1.size() != map_2.size()) {
			return false;
		}

		for(Integer key : map_1.keySet()) {
			if(map_1.get(key).intValue() != map_2.get(key).intValue()) {
				return false;
			}
		}

		return true;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		TreeMap<Integer, Integer> map_1 = new TreeMap<>();
		TreeMap<Integer, Integer> map_2 = new TreeMap<>();
		getData(map_1, input);
		getData(map_2, input);
		System.out.println(check(map_1, map_2) ? 1 : 0);
		for(Integer key : map_1.keySet()) {
			System.out.println(key.intValue() + " " + map_1.get(key).intValue());
		}
		input.close();
	}
}
