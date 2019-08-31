import java.io.*;

public class SWEA_5356 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringBuilder sb = new StringBuilder();

                char[][] ch = new char[5][15];
                int maxlen = 0;
                for (int i = 0; i < 5; i++) {
                    ch[i] = br.readLine().toCharArray();
                    maxlen = maxlen > ch[i].length ? maxlen : ch[i].length;
                }

                for (int i = 0; i < 5; i++) {
                    sb.append(ch[i]);
                    if (ch[i].length < maxlen) {
                        for (int j = 0; j < maxlen - ch[i].length; j++) {
                            sb.append('*');
                        }
                    }
                    ch[i] = sb.toString().toCharArray();
                    sb.setLength(0);
                }

                for (int i = 0; i < ch[0].length; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (ch[j][i] != '*')
                            sb.append(ch[j][i]);
                    }
                }

                System.out.println("#" + tc + " " + sb.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}