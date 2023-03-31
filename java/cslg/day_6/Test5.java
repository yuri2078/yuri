package cslg.day_6;

import java.util.*;

class MyDate {
    private int year;
    private int month;
    private int day;

    public MyDate(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public MyDate next() { // 求当前天的下一天
        int mon[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            mon[2] = 29;
        }
        int new_year = year;
        int new_month = month;
        int new_day = day;
        if (new_day == mon[new_month]) {
            new_day = 1;
            if (new_month == 12) {
                new_month = 1;
                new_year++;
            }
        } else {
            new_day++;
        }
        return new MyDate(new_year, new_month, new_day);
    }

    public MyDate next(int n) { // 求当前天过n天后是哪一天
        int mon[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int new_year = year;
        int new_month = month;
        int new_day = day;
        
        while (n > 0) {
            if (n <= mon[new_month] - new_day) {
                new_day += n;
                break;
            } else {
                n = n - (mon[new_month] - new_day);
                if (new_month == 12) {
                    new_month = 1;
                    new_year++;
                } else {
                    new_month++;
                }
                new_day = 0;
            }

            if ((new_year % 4 == 0 && new_year % 100 != 0) || (new_year % 400 == 0)) {
                mon[2] = 29;
            } else {
                mon[2] = 28;
            }
        }
        return new MyDate(new_year, new_month, new_day);
    }

    public int getDays(MyDate other) { // 求当前天与other天之间相关的天数
        if (this.year > other.year) {
            return -other.getDays(this);
        }
        int days = (other.year - year + 1) * 366;
        int left = 0, right = days;
        while (left <= right) {
            int h = (left + right) / 2;
            MyDate new_data = next(h);
            if (new_data.year == other.year && new_data.month == other.month && new_data.day == other.day) {
                return h;
            } else {
                int com_year = new_data.year - other.year;
                int com_month = new_data.month - other.month;
                int com_day = new_data.day - other.day;
                if (com_year < 0 || (com_year == 0 && com_month < 0) || (com_year == 0 && com_month == 0 && com_day < 0)) {
                    left = h + 1;
                } else {
                    right = h - 1;
                }
            }
        }
        return 1;
    }

    public void show() {
        System.out.printf("%d-%02d-%02d\n", year, month, day);
    }

    public static MyDate getDate(String str) { // 将字符串分解后生成一个日期对象
        String[] words = str.split("-");

        return new MyDate(Integer.parseInt(words[0]), Integer.parseInt(words[1]), Integer.parseInt(words[2]));
    }
}

public class Test5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str1 = in.next();
        // int n = in.nextInt();
        String str2 = in.next();
        MyDate d1 = MyDate.getDate(str1);
        MyDate d2 = MyDate.getDate(str2);
        // d1.next(n).show();
        System.out.println(d1.getDays(d2));
        in.close();
    }
}
