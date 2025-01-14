package chap02;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionProxy {
    public static Connection getConnection() throws SQLException {
        Connection conn = null;
        try {
            // 1. Driver Loading
            Class.forName("com.mysql.cj.jdbc.Driver");
            // 2. connection 연결
            conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/testDB?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");
        } catch (ClassNotFoundException e) {
            // loading failed
            e.printStackTrace();
        }

        return conn;
    }
}
