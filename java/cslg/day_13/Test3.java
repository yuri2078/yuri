import java.io.*;
import java.util.TreeSet;

public class Test3 {
    static int result(StringBuffer str, BufferedWriter writer) {
        TreeSet<String> words = new TreeSet<>();
        for (String s : str.toString().split("[^a-zA-Z]")) {
            if (s.equals("") == false) {
                words.add(s.toLowerCase());
            }
        }
        try {
            for (String s : words) {
                writer.write(s);
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println(e);
        }
        return 0;
    }

    public static void main(String[] args) {
        StringBuffer str = new StringBuffer("");
        try {
            String s;
            BufferedReader reader = new BufferedReader(new FileReader("in.txt"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("words.txt"));
            while ((s = reader.readLine()) != null) {
                str.append(s + " ");
            }
            result(str, writer);
            reader.close();
            writer.close();

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        
    }
}
