package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionProxy_Member {
    static public Connection getConnection() {
        Connection conn = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/safeMember?useSSL=false&serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8&allowPublicKeyRetrieval=true&useSSL=false", "root", "root");

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
        return conn;
    }
}
