package chap01;

import java.sql.*;

public class JDBCTest2 {
    public static void main(String[] args) {

        ResultSet rs = null;
        PreparedStatement pst = null;   // PreparedStatement와 CreateStatement의 차이는?
        Connection con = null;

        try {
            // 1. Driver Loading
            Class.forName("com.mysql.cj.jdbc.Driver");

            // 2. Connection
            con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/scott?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");

            // 3. Query
            // Dynamic sql 사용
            Statement st = con.createStatement();
            String sql = "select * from emp where sal > ? and deptno = ? and ename = ?";
            // connection에서 sql문장 실행이 이루어짐
            pst = con.prepareStatement(sql);
            // ?를 넣었던 부분에 값을 넣어준다. 조건절(Where)을 쓸때 유용하다
            // sql을 할당 후 값을 지정해주어야 한다.
            pst.setInt(1, 2000);
            pst.setInt(2, 10);
            pst.setString(3, "KING");

            // 4. Exectue Query
            rs = pst.executeQuery(); // 위에서 작성한 쿼리를 실행

            // 5. get result
            while (rs.next()) {
                String ename = rs.getString("ename");
                int sal = rs.getInt("sal");
                int deptno = rs.getInt("deptno");
                System.out.println(ename + ",  " + sal + ",  " + deptno);
            }


        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            // 6. close resource
            try {
                if (rs != null)
                    rs.close();
                if (pst != null)
                    pst.close();
                if (con != null)
                    con.close();
            } catch (SQLException e) {
                // close Error
                System.out.println("Close Error");
            }
        }
    }
}
