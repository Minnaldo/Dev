package model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class ProductMgr {

    private Connection conn;
    private ResultSet rs;
    private PreparedStatement ps;

    static public ProductMgr instance = new ProductMgr();

    static public ProductMgr getInstance() {
        return instance;
    }

    private ProductMgr() {
    }

    public boolean addProduct(String id, String name, String price, String stock, String description) {
        String sql = "insert into products (?,?,?,?,?)";
        boolean ret = false;
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
            ps.setString(2, name);
            ps.setString(3, price);
            ps.setString(4, stock);
            ps.setString(5, description);
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

//    public ArrayList<ProductVO> getProductList() {
//        String sql = "select * from products";
//        ArrayList<ProductVO> list = new ArrayList<>();
//        try {
//            conn = ConnectionProxy.getConnection();
//            ps = conn.prepareStatement(sql);
//            rs = ps.executeQuery();
//            while (rs.next()) {
//                list.add(new ProductVO(rs.getString("id"), rs.getString("name"), rs.getString("price"), rs.getString("stock"),rs.getString("description")));
//            }
//        } catch (SQLException e) {
//            e.printStackTrace();
//        } finally {
//            try {
//                close();
//            } catch (SQLException e) {
//                e.printStackTrace();
//            }
//        }
//        return list;
//    }

    public ArrayList<ProductVO> getProducList(String type, String value) {
        String sql = "";

        ArrayList<ProductVO> list = new ArrayList<>();
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            if (type.equals("name")) {
                sql = "select * from products where name=?";
                ps.setString(1, value);
            } else if (type.equals("price")) {
                sql = "select * from products where price<=?";
                ps.setString(1, value);
            } else if (type == null) {
                sql = "select * from products";
            }
            rs = ps.executeQuery();
            while (rs.next()) {
                list.add(new ProductVO(rs.getString("id"), rs.getString("name"), rs.getString("price"), rs.getString("stock"), rs.getString("description")));
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

    public ProductVO getProduct(String id) {
        ProductVO p = null;
        String sql = "select * from products where id=?";
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            while (rs.next()) {
                p = new ProductVO(rs.getString("id"), rs.getString("name"), rs.getString("price"), rs.getString("stock"), rs.getString("description"));
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
        return p;
    }

    public boolean removeProduct(String id) {
        boolean ret = false;
        String sql = "delete from products where id=?";
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
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

    private void close() throws SQLException {
        if (rs != null) rs.close();
        if (ps != null) ps.close();
        if (conn != null) conn.close();
    }
}
