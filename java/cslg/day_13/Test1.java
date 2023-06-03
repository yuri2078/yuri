import java.io.*;

public class Test1 {

  public static void main(String[] args) throws IOException {
    try {
      StringBuffer str;
      String s;
      BufferedReader reader = new BufferedReader(new FileReader("text1.dat"));
      BufferedWriter writer = new BufferedWriter(new FileWriter("text2.dat"));
      while ((s = reader.readLine()) != null) {
        str = new StringBuffer(s);
        writer.write(str.reverse().toString());
        writer.newLine();
      }

      reader.close();
      writer.close();
    } catch (IOException e) {
      System.out.println(e.getMessage());
    }
    
  }
}
