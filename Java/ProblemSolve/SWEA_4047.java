import java.io.*;

public class SWEA_4047 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringBuilder ans = new StringBuilder();

                StringBuilder str = new StringBuilder(br.readLine());
                Card card = new Card();
                boolean flag = false;
                int start = 0, end = 3;
                loop: while (end <= str.length()) {
                    String tmp = str.substring(start, end);
                    int idx = Integer.parseInt(tmp.substring(1, 3));
                    switch (tmp.charAt(0)) {
                    case 'S':
                        if (!card.spade[idx])
                            card.spade[idx] = true;
                        else {
                            ans.append("ERROR");
                            flag = true;
                            break loop;
                        }
                        break;
                    case 'C':
                        if (!card.clover[idx])
                            card.clover[idx] = true;
                        else {
                            ans.append("ERROR");
                            flag = true;
                            break loop;
                        }
                        break;
                    case 'D':
                        if (!card.diamod[idx])
                            card.diamod[idx] = true;
                        else {
                            ans.append("ERROR");
                            flag = true;
                            break loop;
                        }
                        break;
                    case 'H':
                        if (!card.heart[idx])
                            card.heart[idx] = true;
                        else {
                            ans.append("ERROR");
                            flag = true;
                            break loop;
                        }

                        break;
                    }

                    start += 3;
                    end += 3;
                }

                int s = 0, c = 0, h = 0, d = 0;
                if (!flag) {
                    for (int i = 1; i <= 13; i++) {
                        if (!card.heart[i])
                            h++;
                        if (!card.diamod[i])
                            d++;
                        if (!card.clover[i])
                            c++;
                        if (!card.spade[i])
                            s++;
                    }
                    ans.append(s + " ").append(d + " ").append(h + " ").append(c);
                }

                System.out.println("#" + tc + " " + ans.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Card {
        boolean[] spade;
        boolean[] heart;
        boolean[] clover;
        boolean[] diamod;

        Card() {
            spade = new boolean[14];
            heart = new boolean[14];
            clover = new boolean[14];
            diamod = new boolean[14];
        }
    }
}