package chap01;

import java.sql.*;

public class JDBCTest {
    public static void main(String[] args) {
        try {
            // jdbc드라이버를 동적할당(?)
            Class.forName("com.mysql.cj.jdbc.Driver");
            // DirverManager클래스 java.sql폴더에 존재, Connection(DB와 연결된 객체)을 리턴한다
            // JDBC가 MySQL에 접속한다. 주소 뒤는 db명
            Connection con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/scott?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");
            // MySQL에 명령을 하기 위한 객체
            // 수정은 리턴타입이 boolean
            // 조회는 데이터 타입
            Statement statement = con.createStatement();

            //select(조회) 문구가 들어감
            ResultSet rs = statement.executeQuery("select * from emp");

            // 값이 있으면 계속 돌면서 값을 가져온다.
            while (rs.next()) {
                // column의 데이터를 string 형으로 가져온다.
                String ename = rs.getString("ename");
                int sal = rs.getInt("sal");
                int deptno = rs.getInt("deptno");
                System.out.println(ename + ", " + sal + ", " + deptno);
            }

            // close는 필수!
            rs.close();
            statement.close();
            con.close();

            // 수정 문구, insert/ update/create/delete 등 이 들어감
//            boolean exe = statement.execute("");

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }
}
