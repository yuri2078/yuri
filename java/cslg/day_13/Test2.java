import java.io.*;

public class Test2 {
    static int result(StringBuffer str) {
        // System.out.println(str.length());
        int index = 0, pos = str.indexOf("/*", index);
        double sum = 0;
        while (pos != -1) {
            sum += str.indexOf("*/", index) - pos - 2;
            index = str.indexOf("*/", index) + 2;
            pos = str.indexOf("/*", index);
        }
        
        return (int)(sum * 100 / (str.length() - 1));
    }

    public static void main(String[] args) {
        StringBuffer str = new StringBuffer("");
        try {
            String s;
            BufferedReader reader = new BufferedReader(new FileReader("filein.c"));
            while ((s = reader.readLine()) != null) {
                str.append(s + "\n");
            }
            reader.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }

        System.out.printf("%d%%\n", result(str));
    }
}
