package chap01;

import java.sql.*;

public class JDBCTest4 {
    public static void main(String[] args) throws Exception {

        // Driver Loading
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/testDB?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");

        String str = "insert into customer(name, address) values(?, ?)";
        PreparedStatement pst = con.prepareStatement(str);
        pst.setString(1, "홍길동");
        pst.setString(2, "광산구");
        pst.execute();

        String str2 = "select * from customer";
        Statement st = con.createStatement();
        ResultSet rs = st.executeQuery(str2);

        while (rs.next()) {
            // 인덱스로도 가져올 수 있다. 1부터 시작
            int num = rs.getInt(1);
            String name = rs.getString(2);
            String addr = rs.getString(3);
            System.out.println(num + ",  " + name + ",  " + addr);
        }

        st.close();
        pst.close();
        con.close();
    }
}
