import java.io.*;

public class SWEA_5356 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringBuilder sb = new StringBuilder();

                char[][] ch = new char[5][15];

                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < sb.length(); j++) {
                        ch[i][j] = ' ';
                    }
                }

                for (int i = 0; i < 5; i++) {
                    sb.append(br.readLine());
                    for (int j = 0; j < sb.length(); j++) {
                        ch[i][j] = sb.charAt(j);
                    }
                    sb.setLength(0);
                }

                for (int i = 0; i < 15; i++) {
                    for (int j = 0; j < 5; j++) {
                        sb.append(ch[j][i]);
                    }
                }


                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}