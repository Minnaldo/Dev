import java.io.*;

// 전형적인 에라토스테네스의 체를 이용한 문제

public class SWEA_3131 {
    public static void main(String[] args) {
        try {
            int size = (int) Math.pow(10, 6);
            int size2 = (int) Math.sqrt(size);
            boolean[] visit = new boolean[size + 1];

            visit[0] = visit[1] = true;

            for (int i = 2; i <= size2; i++) {
                for (int j = i * 2; j <= size; j += i) {
                    visit[j] = true;
                }
            }
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            StringBuilder sb = new StringBuilder();
            for (int i = 2; i <= size; i++) {
                if (!visit[i]) {
                    sb.append(i + " ");
                }
            }

            bw.write(sb.toString().trim());
            bw.flush();
        } catch (Exception e) {

        }
    }
}