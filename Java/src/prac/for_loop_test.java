

public class for_loop_test{
    public static void main (String [] args)
    {
        int sum = 0;


        for(int i = 0; i<9; i++)
        {
            sum += i;
            System.out.println(i);
        }
        System.out.println(sum);
        sum = 0;
        System.out.println("\n\n\n");
        for(int i = 0; i<9; ++i)
        {
            sum += i;
            System.out.println(i);
        }
        System.out.println(sum);
    }
}