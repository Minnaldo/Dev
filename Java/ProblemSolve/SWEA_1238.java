import java.io.*;
import java.util.*;

// TODO

public class SWEA_1238 {

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            for (int tc = 1; tc <= 1; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int start = Integer.parseInt(st.nextToken());
                int ans = 0;
                int cnt = 0;
                ArrayList<ArrayList<Pair>> arr = new ArrayList<>();
                boolean[] visit = new boolean[n];
                st = new StringTokenizer(br.readLine());

                for (int i = 0; i < n; i++) {
                    arr.add(new ArrayList<Pair>());
                }

                for (int i = 0; i < (n / 2); i++) {
                    int y = Integer.parseInt(st.nextToken());
                    int x = Integer.parseInt(st.nextToken());
                    arr.get(y).add(new Pair(x, 0));
                }

                Queue<Pair> q = new LinkedList<>();
                q.add(new Pair(start, 1));
                visit[start] = true;

                while (!q.isEmpty()) {
                    int caller = q.peek().first;
                    int len = q.peek().second;
                    System.out.println(len);
                    for (int i = 0; i < arr.get(caller).size(); i++) {
                        if (!visit[arr.get(caller).get(i).first]) {

                            arr.get(caller).set(i, new Pair(i, len + 1));
                            // arr.get(caller).get(i).second++;
                            q.add(arr.get(caller).get(i));
                            visit[arr.get(caller).get(i).first] = true;
                        }
                    }

                    q.poll();
                }

                for (int i = 0; i < arr.size(); i++) {
                    for (int j = 0; j < arr.get(i).size(); j++) {
                        ans = cnt > arr.get(i).get(j).second ? ans : arr.get(i).get(j).first;
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}