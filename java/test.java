import java.util.Scanner;
public class test 
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.println("������������ : ");
        int x = input.nextInt();
        int y = input.nextInt();
        System.out.printf("���ǵĺ��� : %d \n",add(x,y));
        input.close();
    }

    public static int add(int x, int y)
    //add��������� int ��ʾ����һ������ֵ�����͵���
    {
        return x + y;
    }

}
