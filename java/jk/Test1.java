package java.jk;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test1{

  static boolean chech(StringBuffer buffer) {
    String email = buffer.toString();
    String emailRegex = "[a-z0-9A-Z]+@[a-z0-9A-Z]+.[a-z0-9A-Z]+";
    Pattern pattern = Pattern.compile(emailRegex);
    Matcher matcher = pattern.matcher(email);
    System.out.println(matcher.find());
    return matcher.matches();
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    StringBuffer buffer = new StringBuffer(input.next());
    System.out.println("字符串翻转 -> " + buffer.reverse());
    if(chech(buffer)){
      System.out.println("邮箱合法!");
    } else {
      System.out.println("邮箱不合法!");
    }

    input.close();
  }
}
