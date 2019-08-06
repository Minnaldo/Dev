package Network;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerTest {

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // TODO Auto-generated method stub
        ServerSocket ss = new ServerSocket(7000);
//		BufferedWriter bw=null;
//		BufferedReader br =null;
        ObjectInputStream ois = null;
        ObjectOutputStream oos = null;
        try {
            while (true) {
                System.out.println("서버는 기다리는중...");
                Socket cli = ss.accept();

//				InputStream is = cli.getInputStream();
//				br = new BufferedReader(new InputStreamReader(is));
//				String str = br.readLine();
//				System.out.println("client 로부터 날아온 문자열 " + str);
                ois = new ObjectInputStream(
                        new BufferedInputStream(
                                cli.getInputStream()));
                Customer cus = (Customer) ois.readObject();
                System.out.println("client로 부터 날아온 문자열 " + cus.toString());

//				bw = new BufferedWriter(new OutputStreamWriter(cli.getOutputStream()));
//				bw.write(str + " - 서버로부터 날아온 문자열 \n");
//				bw.flush();
                oos = new ObjectOutputStream(
                        new BufferedOutputStream(
                                cli.getOutputStream()));
                oos.writeObject(cus);
                oos.flush();
            }
        } catch (IOException e) {
        } finally {
//			bw.close();
//			br.close();
            ois.close();
            oos.close();
            ss.close();
        }
    }
}
