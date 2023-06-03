package cslg.day_12;

import java.util.Scanner;
import java.util.TreeMap;

public class Test4 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		TreeMap<Integer, Integer> map = new TreeMap<>();
		int n = input.nextInt();
		int count = 0;
		int max_key = 0;
		System.out.println(max_key);
		for(int i = 0; i < n; i++) {
			int key = input.nextInt();
			Integer val = map.get(key);
			if(val == null) {
				map.put(key, 1);
				if(count == 0) {
					count = 1;
					max_key = key;
				}
			} else {
				map.put(key, val.intValue() + 1);
				if(count < val.intValue() + 1) {
					count = val.intValue() + 1;
					max_key = key;
				}
			}
		}
		for(Integer key : map.keySet()) {
			if(map.get(key).intValue() == count) {
		    System.out.println(key.intValue() + " " + count);
			}
		}	
		input.close();
	}
}
