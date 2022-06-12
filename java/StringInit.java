import java.util.Arrays;
public class StringInit {

    public static void dfs(int path[],int n,int d){

        if (d >= n) 
        {
            for (int i = 0; i < path.length; i++) 
            {
                System.out.print(path[i]);
            }
            System.out.println();
        } else 
        {
            for (int i = 0; i < 2; i++) 
            {
                path[d]=i;
                dfs(path,n,d+1);
            }
        }
    }

    public static void main(String[] args) 
    {

        int[] A=new int[4]; //申请4个整形数据的内存空间
        Arrays.fill(A,0); //全部用0填充
        dfs(A,4,0); //调用函数
    }
}