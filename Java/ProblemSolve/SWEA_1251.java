import java.io.*;
import java.util.*;

/* 하나로 */

public class SWEA_1251 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));

        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            int n = Integer.parseInt(br.readLine());
            double[][] island = new double[n][2];
            StringTokenizer st;
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++)
                island[i][0] = Double.parseDouble(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++)
                island[i][1] = Double.parseDouble(st.nextToken());

            double E = Double.parseDouble(br.readLine());
            int maxEdge = n * (n - 1) / 2;
            double[][] edges = new double[maxEdge][3];
            int idx = 0;
            // kruskal 적용을 위한 각 정점을 이었을 때의 비용 계산
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    double L = (Math.pow(island[i][0] + island[j][0], 2) + Math.pow(island[i][1] + island[j][1], 2))
                            * E;
                    edges[idx][0] = i;
                    edges[idx][1] = j;
                    edges[idx][2] = L;
                    idx++;
                }
            }
            Arrays.sort(edges, new Comparator<double[]>() {

                @Override
                public int compare(double[] o1, double[] o2) {
                    return Double.compare(o1[2], o2[2]);
                }

            });
            double ans = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int a = find((int) edges[i][0]);
                int b = find((int) edges[i][1]);
                if (a != b) {
                    union(a, b);
                    ans += edges[i][2];
                    cnt++;
                }
                if (cnt == n - 1)
                    break;
            }

            System.out.println("#" + tc + " " + (long) Math.round(ans));
        }
    }

    static int[] parents;

    static int find(int x) {
        if (x == parents[x])
            return x;
        return parents[x] = find(parents[x]);
    }

    static void union(int x, int y) {
        int py = find(y);
        int px = find(x);

        parents[py] = px;
    }

}