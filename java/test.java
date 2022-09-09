import java.util.Scanner;
public class test 
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入两个数 : ");
        int x = input.nextInt();
        int y = input.nextInt();
        System.out.printf("他们的和是 : %d \n",add(x,y));
        input.close();
    }

    public static int add(int x, int y)
    //add这就是类名 int 表示这是一个返回值是整型的类
    {
        return x + y;
    }

}
