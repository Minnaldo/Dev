package model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class safeFoodMgrImpl implements isafeFoodMgr {

    private Connection conn;
    private PreparedStatement ps;
    private ResultSet rs;

    public safeFoodMgrImpl() {
    }

    @Override
    public boolean addMember(String id, String pw, String name, String addr, String tel, String allergy) {
        String sql = "insert into memTable values(?,?,?,?,?,?)";
        boolean ret = false;
        try {
            conn = ConnectionProxy_Member.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
            ps.setString(2, pw);
            ps.setString(3, name);
            ps.setString(4, addr);
            ps.setString(5, tel);
            ps.setString(6, allergy);
            ps.execute();
            ret = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return ret;
    }

    @Override
    public boolean loginMemeber(String id, String pw) {
        String sql = "select * from memTable where id = ? and pw = ?";
        boolean ret = false;
        try {
            conn = ConnectionProxy_Member.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
            ps.setString(2, pw);
            rs = ps.executeQuery();
            rs.last();
            int cnt = rs.getRow();
            if (cnt == 1)
                ret = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return ret;
    }

    @Override
    public ArrayList<MemberVO> search(String id) {
        String sql = "select * from memTable where id=?";
        ArrayList<MemberVO> ret = new ArrayList<>();
        try {
            conn = ConnectionProxy_Member.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
            rs = ps.executeQuery();
            while (rs.next()) {
                ret.add(new MemberVO(rs.getString("id"), rs.getString("name"), rs.getString("tel")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return ret;
    }

    @Override
    public void deleteMember(String id) {
        String sql = "delete from memTable where id = ?";
        try {
            conn = ConnectionProxy_Member.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
    }

    //    TODO 뭔가 이상?
    @Override
    public MemberVO searchMember(String id) {
        MemberVO m = null;
        String sql = "select * from memTable where id=?";
        try {
            conn = ConnectionProxy_Member.getConnection();
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            rs.last();
            while (rs.next()) {
// TODO                검색? 조회?
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return m;
    }

    @Override
    public boolean modifyMember(String id, String pw, String name, String addr, String tel, String allergy) {
        String sql = "update memTable set pw=?, name=?, addr=?, tel=?, allergy=? where id=? ";
        boolean ret = false;
        try {
            conn = ConnectionProxy_Member.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, pw);
            ps.setString(2, name);
            ps.setString(3, addr);
            ps.setString(4, tel);
            ps.setString(5, allergy);
            ps.setString(6, id);
            ret = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return ret;
    }

    @Override
    public void close() {
        try {
            if (rs != null) rs.close();
            if (ps != null) ps.close();
            if (conn != null) conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}
