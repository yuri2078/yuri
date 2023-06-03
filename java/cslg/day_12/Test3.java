package cslg.day_12;
import java.util.LinkedHashSet;
import java.util.Scanner;

public class Test3 {
	static void getData(LinkedHashSet<Integer> list, Scanner input) {
		for(String s : input.nextLine().split("\\s+")) {
			list.add(Integer.parseInt(s));
		}
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		LinkedHashSet<Integer> list_1 = new LinkedHashSet<>();
		LinkedHashSet<Integer> list_2 = new LinkedHashSet<>();
		getData(list_1, input);
		getData(list_2, input);
		list_1.retainAll(list_2);
		for(Integer x : list_1){
			System.out.print(x.intValue() + " ");
		}
		if(list_1.size() == 0) {
			System.out.println("No Answer");
		}
		System.out.println();
		input.close();
	}
}
