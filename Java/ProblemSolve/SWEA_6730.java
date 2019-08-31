import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class SWEA_6730 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int n = Integer.parseInt(br.readLine());
                int[] arr = new int[n];
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int i = 0; i < n; i++)
                    arr[i] = Integer.parseInt(st.nextToken());

                int asc = arr[1] - arr[0], desc = arr[n - 2] - arr[n - 1];
                asc = asc < 0 ? 0 : asc;
                desc = desc < 0 ? 0 : desc;

                for (int i = 0; i < n - 1; i++) {
                    int tmpAsc = arr[i + 1] - arr[i];
                    int tmpDesc = arr[i] - arr[i + 1];

                    asc = asc > tmpAsc ? asc : tmpAsc;
                    desc = desc > tmpDesc ? desc : tmpDesc;
                }

                System.out.println("#" + tc + " " + asc + " " + desc);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}