package cslg.day_11;

import java.util.ArrayList;
import java.util.Scanner;

class Ticket {
	public int start;
	public int left;
	public int need;
	public ArrayList<Integer> list = null;

	public Ticket(int start, int left) {
		this.start = start;
		this.left = left;
	}

	public Ticket(int need) {
		list = new ArrayList<>();
		this.need = need;
	}

	public void addData(int start, int size) {
		for (int i = 0; i < size; i++) {
			list.add(i + start);
		}
	}
}

public class Test3 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Ticket[] tickets = new Ticket[20];
		for (int i = 0; i < 20; i++) {
			tickets[i] = new Ticket(i * 5 + 1, 5);
		}
		int n = input.nextInt();
		Ticket buy[] = new Ticket[n];

		for (int i = 0; i < n; i++) {
			buy[i] = new Ticket(input.nextInt());
			for (int j = 0; j < 20; j++) {
				if (buy[i].need <= tickets[j].left) {
					buy[i].addData(tickets[j].start, buy[i].need);
					tickets[j].start += buy[i].need;
					tickets[j].left -= buy[i].need;
					buy[i].need = 0;
					break;
				}
			}
			while (buy[i].need != 0) {
				for (int j = 0; j < 20; j++) {
					if (buy[i].need <= tickets[j].left) {
						buy[i].addData(tickets[j].start, buy[i].need);
						tickets[j].left -= buy[i].need;
						tickets[j].start += buy[i].need;
						buy[i].need = 0;
						break;
					} else {
						buy[i].addData(tickets[j].start, tickets[j].left);
						buy[i].need -= tickets[j].left;
						tickets[j].left = 0;
					}

				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int x : buy[i].list) {
				System.out.print(x + " ");
			}
			System.out.println();
		}

		input.close();

	}
}
