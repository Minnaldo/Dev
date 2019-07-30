package chap07;

import java.io.*;

public class IOTest4 {
    public static void main(String[] args) throws IOException {
        FileOutputStream fos = null;
        DataOutputStream dos = null;

        try {
            fos = new FileOutputStream("sample3.txt");
            dos = new DataOutputStream(new BufferedOutputStream(fos));
            dos.writeInt(256); // int형 데이터로 넣었다.
            dos.writeDouble(3.141592);
            dos.writeUTF("Hello SSaffy");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                dos.close();
                fos.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        DataInputStream dis = null;
        try {
            dis = new DataInputStream(new BufferedInputStream(new FileInputStream("sample3.txt")));

            int a = dis.readInt();
            double b = dis.readDouble();
            String c = dis.readUTF();
            System.out.println(a + ", " + b + ", " + c);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                dis.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}
