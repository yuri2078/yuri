package cslg.day_6;

import java.util.Scanner;

class Rectangle {
	int x1, y1, x2, y2;
	Rectangle(int x1, int y1, int x2, int y2) {
		this.x1 = x1;
		this.x2 = x2;
		this.y1 = y1;
		this.y2 = y2;
	}

	int intersect(Rectangle r2) {
		int max_x1 = Math.max(x1, x2);
		int max_x2 = Math.max(r2.x1, r2.x2);
		int min_x1 = Math.min(x1, x2);
		int min_x2 = Math.min(r2.x1, r2.x2);

		int max_y1 = Math.max(y1, y2);
		int max_y2 = Math.max(r2.y1, r2.y2);
		int min_y1 = Math.min(y1, y2);
		int min_y2 = Math.min(r2.y1, r2.y2);

		int x = Math.min(max_x1, max_x2) - Math.max(min_x2, min_x1);
		int y = Math.min(max_y2, max_y1) - Math.max(min_y2, min_y1);

		if (x < 0 || y < 0) {
			return 0;
		}

		return x * y;
	}
}

public class Test2 {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int x1 = input.nextInt();
		int y1 = input.nextInt();
		int x2 = input.nextInt();
		int y2 = input.nextInt();
		Rectangle r1 = new Rectangle(x1, y1, x2, y2);

		x1 = input.nextInt();
		y1 = input.nextInt();
		x2 = input.nextInt();
		y2 = input.nextInt();
		Rectangle r2 = new Rectangle(x1, y1, x2, y2);
		int area = r1.intersect(r2);
		System.out.println(area);
		input.close();
	}
}

