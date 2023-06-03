import java.io.*;
import java.util.TreeSet;

public class Test4 {
    static int result(StringBuffer str, BufferedWriter writer) {
        TreeSet<String> words = new TreeSet<>();
        for (String s : str.toString().split("\\s+")) {
            if (s.equals("") == false) {
                words.add(s.toLowerCase());
            }
        }
        try {
            for (String s : words) {
                writer.write(s + " ");
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
            BufferedReader reader = new BufferedReader(new FileReader("sort.in"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("sort.out"));
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
