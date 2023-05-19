//package cslg.day_12;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

public class Test5 {
	static void getData(TreeMap<Integer, TreeSet<Integer>> get_key, TreeMap<Integer, TreeSet<Integer>> return_key, ArrayList<Integer> key_pos) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int x = input.nextInt();
		key_pos.add(0);
		for(int i = 1; i <= n; i++) {
			key_pos.add(i);
		}

		for(int i = 0; i < x; i++) {
			int key = input.nextInt();
			int get_time = input.nextInt();
			int class_timie = input.nextInt();
			TreeSet<Integer> get_val = get_key.get(get_time);
			TreeSet<Integer> ret_val = return_key.get(get_time + class_timie);
			if(get_val == null) {
				get_key.put(get_time, new TreeSet<>());
				get_val = get_key.get(get_time);
			}
			if(ret_val == null) {
				return_key.put(get_time + class_timie, new TreeSet<>());
				ret_val = return_key.get(get_time + class_timie);
			}
			get_val.add(key);
			ret_val.add(key);
		}
		input.close();
	}

	public static void main(String[] args) {
		TreeMap<Integer, TreeSet<Integer>> get_key = new TreeMap<>();
		TreeMap<Integer, TreeSet<Integer>> return_key = new TreeMap<>();
		ArrayList<Integer> key_pos = new ArrayList<>();
		getData(get_key, return_key, key_pos);
		for(int i = 1;!get_key.isEmpty() || !return_key.isEmpty() ; i++) {
			TreeSet<Integer> ret_set = return_key.get(i);
			if(ret_set != null) {
				for(Integer key : ret_set) {
					for(int j = 1; j < key_pos.size(); j++) {
						if(key_pos.get(j) == 0) {
							key_pos.set(j, key.intValue());
							break;
						}
					}
				}
				return_key.remove(i);
			}

			TreeSet<Integer> get_val = get_key.get(i);
			if (get_val != null) {
				for(Integer key : get_val) {
					for(int j = 1; j < key_pos.size(); j++) {
						if(key_pos.get(j) == key.intValue()) {
							key_pos.set(j, 0);
							break;
						}
					}
				}
				get_key.remove(i);
			}
		}

		for(int i = 1; i < key_pos.size(); i++) {
			System.out.print(key_pos.get(i) + " ");
		}
		System.out.println();
	}
}


