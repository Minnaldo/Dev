import java.io.*;
import java.util.StringTokenizer;

public class SWEA_6485 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {

                int n = Integer.parseInt(br.readLine());

                Pair[] arr = new Pair[n];
                for (int i = 0; i < n; i++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    arr[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                }

                int p = Integer.parseInt(br.readLine());
                int[] busstop = new int[p];
                int[] ans = new int[p];
                for (int i = 0; i < p; i++) {
                    busstop[i] = Integer.parseInt(br.readLine());
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < p; j++) {
                        if (arr[i].first <= busstop[j] && busstop[j] <= arr[i].second) {
                            ans[j]++;
                        }
                    }
                }

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < p; i++) {
                    sb.append(ans[i]).append(" ");
                }

                System.out.println("#" + tc + " " + sb.toString().trim());

            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}