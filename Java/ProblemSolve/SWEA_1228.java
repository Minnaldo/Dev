import java.util.*;

class SWEA_1228{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
            for (int tc = 1; tc <= 10; tc++) {

                int n = sc.nextInt();
                sc.nextLine();
                String chiper = sc.nextLine().replaceAll(" ", "");
                int iLen = sc.nextInt();
                sc.nextLine();

                StringBuilder sb = new StringBuilder(chiper);

                Scanner sc2 = new Scanner(sc.nextLine());
                int x, y;
                String tmpStr;

                while (sc2.hasNext()) {
                    char c = sc2.next().charAt(0);
                    switch (c) {
                    case 'I':
                        x = sc2.nextInt();
                        y = sc2.nextInt();
                        tmpStr = "";
                        for (int a = 0; a < y; a++) {
                            tmpStr += sc2.next();
                        }
                        sb.insert(x * 6, tmpStr);
                        break;
                    }
                }

                System.out.print("#" + tc + " ");
                for (int i = 0; i < 9; i++) {
                    System.out.print(sb.substring(i * 6, i * 6 + 6) + " ");
                }
                System.out.println(sb.substring(54, 60));
                sc2.close();
            }
            sc.close();
}
}