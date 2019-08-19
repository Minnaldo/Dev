package chap02;

import java.sql.*;
import java.util.ArrayList;

// Singleton pattern이 필요 없는 이유
// 데이터를 갖고있지 않고, mysql에 연결만 도와주는 클래스이므로 많인 생겨도 상관 없다
// 연결선은 아무리 많아도 상관이 없음
public class DBManager {
    private Connection conn;
    private PreparedStatement pst;
    private ResultSet rs;

    // static Block
    // 클래스가 lading 될 때 한번만 실행된다
    static {
        try {
            // 1. Driver Loading
            Class.forName("com.mysql.cj.jdbc.Driver");
            new CreateTable();
        } catch (ClassNotFoundException e) {
            // loading failed
//            e.printStackTrace();
        }
    }

    // Manager 클래스에서는 예외처리를 하면 안된다
    public DBManager() throws SQLException {
        // 2. connection 연결
        conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/testDB?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");
    }

    public boolean insertCustomer(String name, int age, String addr) {
        String str = "insert into customer(name, age, addr) values(?, ?, ?)";
        boolean res = false;
        try {
            pst = conn.prepareStatement(str);
            pst.setString(1, name);
            pst.setInt(2, age);
            pst.setString(3, addr);
            res = pst.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;
    }

    public boolean updateCustomer(int num, String name, int age, String addr) throws SQLException {
        String sql = "update customer set name=?, age = ?, addr = ? where num = ?";
        pst = conn.prepareStatement(sql);
        pst.setString(1, name);
        pst.setInt(2, age);
        pst.setString(3, addr);
        pst.setInt(4, num);
        boolean ret = pst.execute();
        return ret;
    }

    public boolean deleteCostumer(int num) throws SQLException {
        String sql = "delete from customer where num = ?";
        pst = conn.prepareStatement(sql);
        pst.setInt(1, num);
        boolean ret = pst.execute();
        return ret;
    }

    public ArrayList<CustomerVO> queryCustomer() {
        String sql = "select * from customer";
        ArrayList<CustomerVO> list = null;
        try {
            pst = conn.prepareStatement(sql);
            rs = pst.executeQuery();
            list = new ArrayList<>();
            while (rs.next()) {
                CustomerVO vo = new CustomerVO();
                vo.setNum(rs.getInt("num"));
                vo.setName(rs.getString("name"));
                vo.setAddr(rs.getString("addr"));
                vo.setAge(rs.getInt("age"));
                list.add(vo);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return list;
    }

    public CustomerVO queryCustomer(int num) {
        String sql = "select * from customer where num = ?";
        CustomerVO ret = null;
        try {
            pst = conn.prepareStatement(sql);
            pst.setInt(1, num);
            rs = pst.executeQuery();
            if (rs.next()) {
                ret = new CustomerVO();
                ret.setAddr(rs.getString("addr"));
                ret.setAge(rs.getInt("age"));
                ret.setName(rs.getString("name"));
                ret.setNum(rs.getInt("num"));
            } else {
                return null;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return ret;
    }

    public void close() throws SQLException {
        try {
            if (conn != null) {
                conn.close();
            }
            if (pst != null) {
                pst.close();
            }
            if (rs != null) {
                rs.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
