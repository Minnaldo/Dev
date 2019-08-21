import java.io.*;
import java.util.*;

public class SWEA_7102 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int m = Integer.parseInt(st.nextToken());
                int max = m * n;

                int[] arr = new int[max + 1];
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        arr[i + j]++;
                    }
                }
                ArrayList<Pair> aa = new ArrayList<>();
                for (int i = 1; i <= max; i++) {
                    aa.add(new Pair(i, arr[i]));
                }

                Collections.sort(aa, new Comparator<Pair>() {
                    @Override
                    public int compare(Pair o1, Pair o2) {
                        return o2.second - o1.second;
                    }
                });
                StringBuilder sb = new StringBuilder();
                int chk = aa.get(0).second;
                sb.append(aa.get(0).first).append(" ");
                for (int i = 1; i < aa.size(); i++) {
                    if (aa.get(i).second == chk) {
                        sb.append(aa.get(i).first).append(" ");
                    } else {
                        break;
                    }
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