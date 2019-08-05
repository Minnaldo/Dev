import java.util.*;
import java.io.*;

public class extract {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int size = 100;
            String[] str = new String[size];
            int AAAAAAA = sc.nextInt();
            for (int i = 0; i < size; i++) {
                str[i] = sc.next();
                System.out.print(str[i].charAt(41));
            }

            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}