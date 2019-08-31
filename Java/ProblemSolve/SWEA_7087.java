import java.io.*`;

public class SWEA_7087 {
    public static void main(String[] args){
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = Integer.parseInt(br.readLine());
                boolean[] visit = new boolean[26];
                for(int i = 0; i<n;i++){
                    visit[br.readLine().charAt(0)-'A'] = true;
                }

                for(int i = 0; i<26; i++){
                    if(!visit[i]){
                        break;
                    }
                    ans++;
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}