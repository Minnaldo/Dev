import java.io.*;

public class Baek_16922 {

    static int[][] arr;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            int ans = 0;
            arr = new int[21][4];

            // arr[0][0] = arr[0][1] = arr[0][2] = arr[0][3] = 1;
            arr[1][0] = arr[1][1] = arr[1][2] = arr[1][3] = 1;

            for (int i = 2; i <= 20; i++) {
                arr[i][0] = 1;
                for (int j = 1; j < 4; j++) {
                    arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
                }
            }

            for (int i = 0; i < 4; i++) {
                ans += arr[n][i];
            }

            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}