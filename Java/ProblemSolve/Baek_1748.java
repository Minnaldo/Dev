import java.io.*;

public class Baek_1748 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int ans = 0;
            int n = Integer.parseInt(br.readLine());

            int idx = 1;
            int post = 1;

            while (n > 0) {
                int pow = (int) Math.pow(10, idx);
                int tmp = pow - post;

                if(n > tmp){
                    ans += (tmp*idx);
                    post = pow;
                    n -= tmp;
                }else{
                    ans += (n*idx);
                    n-=tmp;
                }
                idx++;
            }

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}