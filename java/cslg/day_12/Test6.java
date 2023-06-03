package cslg.day_12;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

class Book {
	String name;
	int price;

	public Book (String name, int price) {
		this.name = name;
		this.price = price;
	}

	public int hashCode() {
		return name.length() * price;	
	}

}

public class Test6 {
	public static void getData(TreeSet<Book> books) {
		Scanner input = new Scanner(System.in);
		String str[] = input.nextLine().split("\\s+");
		while(str[0].compareTo("bye") != 0 ) {
			books.add(new Book(str[0], Integer.parseInt(str[1])));
			str = input.nextLine().split("\\s+");
		}
		input.close();
	}

	public static void main(String[] args) {
		TreeSet<Book> books = new TreeSet<>(new Comparator<Book>() {
		  public int compare(Book b1, Book b2) {
        if(b1.price == b2.price) {
          return b1.name.compareTo(b2.name);
        }
        return b1.price - b2.price;
      }
		});
		getData(books);
		ArrayList<Book> list = new ArrayList<>(books);
		Collections.sort(list, new Comparator<Book>() {
			public int compare(Book a, Book b) {
				if(a.price == b.price) {
					return a.name.compareTo(b.name);
				}
				return a.price - b.price;
			}
		});
		for(Book book : list) {
			System.out.println(book.name + " " + book.price);
		}
	}
}
