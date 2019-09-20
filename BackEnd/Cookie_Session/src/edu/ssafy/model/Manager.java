package edu.ssafy.model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class Manager {
    static public Manager instance = new Manager();

    private Connection conn;
    private PreparedStatement ps;
    private ResultSet rs;   // 쿼리 결과가 테이블로 나올 때

    private Manager() {
    }

    static public Manager getInstance() {
        return instance;
    }

    public boolean addMember(MemberVO m)  {
        String sql = "insert into (?,?,?,?,?,?)";
        boolean ret = false;
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, m.getName());
            ps.setString(2, m.getUserid());
            ps.setString(3, m.getPwd());
            ps.setString(4, m.getEmail());
            ps.setString(5, m.getPhone());
            ps.setInt(6, m.getAdmin());
            ps.execute();
            ret = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return ret;
    }

    public MemberVO getMember(String userid)  {
        MemberVO m = null;
        String sql = "select * from members where userid =?";
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, userid);
            rs = ps.executeQuery();
            while (rs.next()) {
                m = new MemberVO(rs.getString("name"),
                        rs.getString("userid"),
                        rs.getString("pwd"),
                        rs.getString("email"),
                        rs.getString("phone"),
                        rs.getInt("admin"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return m;
    }

    public ArrayList<MemberVO> getMemberList()  {
        String sql = "select * from members";
        ArrayList<MemberVO> list = new ArrayList<>();
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();

            while (rs.next()) {
                list.add(new MemberVO(rs.getString("name"),
                        rs.getString("userid"),
                        rs.getString("pwd"),
                        rs.getString("email"),
                        rs.getString("phone"),
                        rs.getInt("admin")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        return list;
    }

    private void close() throws SQLException {
        if (rs != null) rs.close();
        if (ps != null) ps.close();
        if (conn != null) conn.close();
    }
}
