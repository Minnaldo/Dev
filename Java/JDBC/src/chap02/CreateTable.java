package chap02;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class CreateTable {
    CreateTable() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/testDB?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");

            Statement st = con.createStatement();
            // auto_increment : primary key and int 일 때, 자동으로 값이 증가
            String str = "create table customer(num int primary key auto_increment, name varchar(20), age int, addr varchar(1000))";
            // execute query는 조회 나머지는 실행
            boolean flag = st.execute(str);
            System.out.println("테이블 생성");

            st.close();
            con.close();
        } catch (ClassNotFoundException e) {
//            e.printStackTrace();
        } catch (SQLException e) {
//            e.printStackTrace();
        }
    }
}
