package model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class ProductMgrImpl implements IProductMgr {
    private Connection conn;
    private ResultSet rs;
    private PreparedStatement ps;

    public ProductMgrImpl() {
    }

    public boolean addProduct(String id, String name, String price, String stock, String description) {
        String sql = "insert into products values (?, ?, ?, ?, ?)";
        boolean ret = false;
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
            ps.setString(2, name);
            ps.setString(3, price);
            ps.setInt(4, Integer.parseInt(stock));
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

    public ArrayList<ProductVO> getProductList() {
        String sql = "select * from products order by name";
        ArrayList<ProductVO> list = new ArrayList<>();
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
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

    public ArrayList<ProductVO> getProductList(String type, String value) {
        String sql = "";
        ArrayList<ProductVO> list = new ArrayList<>();
        try {
            conn = ConnectionProxy.getConnection();
            if (type.equals("name")) {
                sql = "select * from products where name like ? order by name";
                ps = conn.prepareStatement(sql);
                ps.setString(1, "%" + value + "%");
            } else if (type.equals("price")) {
                sql = "select * from products where price<=? order by price";
                ps = conn.prepareStatement(sql);
                ps.setInt(1, Integer.parseInt(value));
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

    public ProductVO getProduct(String type, String value) {
        ProductVO p = null;
        String sql = "";
        if (type.equals("name")) {
            sql = "select * from products where name like ?";
        } else if (type.equals("id")) {
            sql = "select * from products where id like ?";
        }
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, "%" + value + "%");
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

    public ProductVO update(String id, String name, String price, String stock, String description) {
        String sql = "update products set id = ?, name =? , price =?,stock=?, description=? where id=?";
        boolean result = false;
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
            ps.setString(2, name);
            ps.setString(3, price);
            ps.setString(4, stock);
            ps.setString(5, description);
            ps.setString(6, id);
            ps.execute();
            result = true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        return getProduct("id", id);
    }

    public boolean removeProduct(String id) {
        boolean ret = false;
        String sql = "delete from products where id=?";
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, id);
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

    public ProductVO search(String name) {
        ProductVO p = null;
        String sql = "select * from products where name=?";
        try {
            conn = ConnectionProxy.getConnection();
            ps = conn.prepareStatement(sql);
            ps.setString(1, name);
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

    public void close() throws SQLException {
        if (rs != null) rs.close();
        if (ps != null) ps.close();
        if (conn != null) conn.close();
    }
}
