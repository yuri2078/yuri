import java.util.Scanner;
public class sum {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("sfsdf:");
        int x = input.nextInt();
        System.out.printf("flj  \n", x, sumNumber(x));
        input.close();
    }
    public static int sumNumber(int x)
    {
        int s=0;
        while(x != 0)
        {
            s=s+x%10;
            x=x/10;
        }
        return s;
    }
}
