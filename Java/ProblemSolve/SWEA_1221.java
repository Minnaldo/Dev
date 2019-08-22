import java.io.*;
import java.util.*;

/**
 *  GNS
 */

public class SWEA_1221 {

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {

            int t = Integer.parseInt(br.readLine());

            String[] keys = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

            for (int tc = 1; tc <= 10; tc++) {
                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

                int n = Integer.parseInt(br.readLine().split(" ")[1]);
                HashMap<String, Integer> hmap = new HashMap<>();
                hmap.put("ZRO", 0);
                hmap.put("ONE", 0);
                hmap.put("TWO", 0);
                hmap.put("THR", 0);
                hmap.put("FOR", 0);
                hmap.put("FIV", 0);
                hmap.put("SIX", 0);
                hmap.put("SVN", 0);
                hmap.put("EGT", 0);
                hmap.put("NIN", 0);

                // input
                StringTokenizer st = new StringTokenizer(br.readLine());
                while (st.hasMoreTokens()) {
                    String key = st.nextToken();
                    hmap.put(key, hmap.get(key) + 1);
                }

                StringBuilder sb = new StringBuilder();
                for (String val : keys) {
                    for (int i = 0; i < hmap.get(val); i++)
                        sb.append(val).append(" ");
                }

                bw.write("#" + tc + "\n" + sb.toString().trim()+"\n");
                bw.flush();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}