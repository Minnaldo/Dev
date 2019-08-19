package chap01;

// DML / DDL을 사용해본다

import java.sql.*;

public class JDBCTest3 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/testDB?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");

        Statement st = con.createStatement();
        // auto_increment : primary key and int 일 때, 자동으로 값이 증가
        String str = "create table customer(num int primary key auto_increment, name varchar(20), address varchar(1000))";
        // execute query는 조회 나머지는 실행
        boolean flag = st.execute(str);

        if (flag) {
            System.out.println("Table Created");
        } else {
            System.out.println("Query falied");
        }

        st.close();
        con.close();
    }
}
