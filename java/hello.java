public class hello
{
    public static void main(String[] args)
    {
        int i=0;
        while(i<10)
        {
            System.out.println(i);
            i++;
        }
    }
    public static long  fac(int n)
    {
        long s = 1;
        for(int i = 1;i<=n;i++)
        {
            s = s * i;
        }
        return s;
    }
}
