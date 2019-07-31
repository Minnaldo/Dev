import java.util.*;
import java.io.*;

public class SWEA_1234 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            for (int tc = 1; tc <= 1; tc++) {
                String ans = "";

                int n = sc.nextInt();
                StringBuilder sb = new StringBuilder(sc.next());

                for (int idx = 0; idx < sb.length(); idx++) {
                    if (sb.charAt(idx) == sb.charAt(idx + 1)) {
                        sb = sb.delete(idx, idx+2);
                        idx = 0;
                    }
                }

                // TODO 19.08.01
                // 왜 마지막 케이스의 00은 안지워질까?
                for(int i = 0; i<sb.length()-1;i++){
                    if (sb.charAt(i) == sb.charAt(i + 1)) {
                        sb = sb.delete(i, i+2);
                    }
                }

                System.out.println("#" + tc + " " + sb);
            }
            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}