package chap07;

import java.io.*;

public class IOTest3 {
    public static void main(String[] args) throws IOException {
//        FileOutputStream fos = new FileOutputStream("Sample2.txt");
//        BufferedOutputStream bos = new BufferedOutputStream(fos);
//        String s = "Hello ssafy";
//        bos.write(s.getBytes());
//
//        OutputStreamWriter osw = new OutputStreamWriter(fos);
//        BufferedWriter bw = new BufferedWriter(osw);
//        bw.write("Hello SSAFY too");
//        bw.flush();
//        bw.close();

        // 위의 코드를 한줄로
        BufferedWriter bw2 = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("Sample2.txt")));
        bw2.write("Hello Saffy Three");
        bw2.close();

        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("Sample2.txt")));
        String str = "";
        while ((str = br.readLine()) != null) {
            System.out.println(str);
        }

        // close는 finally 블록에 등록하여, 할당된 메모리를 회수할 수 있도록 한다
        br.close();
    }
}
