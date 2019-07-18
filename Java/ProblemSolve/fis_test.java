import java.io.*;

public class fis_test {
    public static void main(String[] args) {

        try (FileInputStream fis = new FileInputStream("input.txt")) {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));

            int aa = 0;
            int idx = 0;
            while ((aa = br.read()) != -1 && idx < 20) {
                System.out.print(aa + " ");
                idx++;
            }

            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}