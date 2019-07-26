import java.util.*;

public class SWEA_1976 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t= sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int hh1 = sc.nextInt();
            int mm1 = sc.nextInt();
            int hh2 = sc.nextInt();
            int mm2 = sc.nextInt();

            int ansmm = (mm1+mm2)%60;
            int anshh = (hh1+hh2)%12 + (mm1+mm2)/60;

            System.out.println("#" + tc + " " + anshh+" "+ansmm);
        }
        sc.close();
    }
}