package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionProxy {

    public static Connection getConnection() throws SQLException {
        Connection con = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/safeMember?useSSL=false&serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "root",
                    "root");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return con;
    }
}