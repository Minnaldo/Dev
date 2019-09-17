package edu.ssafy.model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionProxy {
    public static Connection getConnection() throws SQLException {
        Connection conn = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/ssafyweb?useSSL=false&serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "root", "root");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return conn;
    }
}
