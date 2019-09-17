package edu.ssafy.model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class MemManager {

    private static MemManager instance = new MemManager();
    private ArrayList<MemVO> list = new ArrayList<>();

    //    mysql
    private Connection conn;
    private PreparedStatement st;
    private ResultSet rs;

    private MemManager() {
    }

    public static MemManager getInstance() {
        return instance;
    }

    public boolean addMem(String name, String id, String pwd, String addr, String age, String tel) {
        String str = "insert into memberweb(id, pw, name,  addr, age, tel) values(?,?,?,?,?,?)";
        boolean ret = false;

        try {
            conn = ConnectionProxy.getConnection();
            st = conn.prepareStatement(str);
            st.setString(1, id);
            st.setString(2, pwd);
            st.setString(3, name);
            st.setString(4, addr);
            st.setString(5, age);
            st.setString(6, tel);
            st.execute();
            ret = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }

        return ret;
    }

    public boolean delMem(String id) {
        boolean ret = false;
        String sql = "delete from memberweb where id=?";
        try {
            conn = ConnectionProxy.getConnection();
            st = conn.prepareStatement(sql);
            st.setString(1, id);
            st.execute();
            ret = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }

        return ret;
    }

    public boolean updateMem(String name, String id, String pwd, String addr, String age, String tel) {
        String str = "update memberweb set id=?, pw=?, addr=?, age=?, tel=? where name=?";
        boolean ret = false;
        try {
            conn = ConnectionProxy.getConnection();

            st = conn.prepareStatement(str);
            st.setString(1, id);
            st.setString(2, pwd);
            st.setString(3, addr);
            st.setString(4, age);
            st.setString(5, tel);
            st.setString(6, name);
            st.execute();
            ret = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }

        return ret;
    }

    public ArrayList<MemVO> searchAll() {
        String sql = "select * from memberweb";
        ArrayList<MemVO> alist = new ArrayList<>();
        try {
            conn = ConnectionProxy.getConnection();
            st = conn.prepareStatement(sql);
            rs = st.executeQuery();
            while (rs.next()) {
                alist.add(new MemVO(rs.getString("id"), rs.getString("name"), rs.getString("pw"), rs.getString("addr"), rs.getString("age"), rs.getString("tel")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }

        return alist;
    }

    public MemVO memInfo(String id) {
        String sql = "select * from memberweb where id=?";
        MemVO m = null;
        try {
            conn = ConnectionProxy.getConnection();
            st = conn.prepareStatement(sql);
            st.setString(1, id);
            rs = st.executeQuery();
            while (rs.next()) {
                m = new MemVO(rs.getString("id"), rs.getString("name"), rs.getString("pw"), rs.getString("addr"), rs.getString("age"), rs.getString("tel"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }

        return m;
    }

    public boolean memberChk(String id, String pw) {
        String sql = "select * from memberweb where id=? AND pw=?";
        boolean ret = false;
        try {
            conn = ConnectionProxy.getConnection();
            st = conn.prepareStatement(sql);
            st.setString(1, id);
            st.setString(2, pw);
            st.execute();
            ret = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return ret;
    }

    public ArrayList<MemVO> searchMem(String name) {
        String sql = "";
        ArrayList<MemVO> aList = new ArrayList<>();
        try {
            conn = ConnectionProxy.getConnection();
            if (name != "") {
                sql = "select * from memberweb where name=?";
                st = conn.prepareStatement(sql);
                st.setString(1, name);
            } else {
                sql = "select * from memberweb";
                st = conn.prepareStatement(sql);
            }
            rs = st.executeQuery();
            while (rs.next()) {
                aList.add(new MemVO(rs.getString("id"), rs.getString("name"), rs.getString("pw"), rs.getString("addr"), rs.getString("age"), rs.getString("tel")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return aList;
    }

    public void close() {
        try {
            if (conn != null) {
                conn.close();
            }
            if (st != null) {
                st.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
