import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class SWEA_1945 {

    public static void main(String[] args) {
        try {
            FileInputStream fis = new FileInputStream("input.txt");
            BufferedReader br = new BufferedReader(new InputStreamReader(fis));

            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {

                int input = Integer.parseInt(br.readLine());
                int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

                while (input > 1) {
                    //System.out.println(input);
                    if (input % 11 == 0) {
                        input /= 11;
                        cnt4++;
                    } else if (input % 7 == 0) {
                        input /= 7;
                        cnt3++;
                    } else if (input % 5 == 0) {
                        input /= 5;
                        cnt2++;
                    } else if (input % 3 == 0) {
                        input /= 3;
                        cnt1++;
                    } else if (input % 2 == 0) {
                        input /= 2;
                        cnt++;
                    }
                }
                // if (input % 2 == 0)
                System.out.println("#" + tc + " " + (cnt ) + " " + cnt1 + " " + cnt2 + " " + cnt3 + " " + cnt4);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}