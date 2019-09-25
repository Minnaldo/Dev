package model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;
import java.util.List;

/**
 * xml문서 내의 파일을 db에 저장하고, 음식관련된 정보를 저장한다
 */

public class FoodDaoImpl implements FoodDao {
    private List<Food> foods;
    private Connection conn;
    private PreparedStatement ps;
    private ResultSet rs;

    public FoodDaoImpl() {
    }

    public void loadData(String string, String string2) {
        FoodSaxParser parser = new FoodSaxParser(string, string2);
        String str = "insert into food values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
        foods = parser.getFoods();
        for (int i = 0; i < foods.size(); i++) {
            try {
                conn = ConnectionProxy.getConnection();
                ps = conn.prepareStatement(str);
                ps.setInt(1, foods.get(i).getCode());
                ps.setString(2, foods.get(i).getName());
                ps.setDouble(3, foods.get(i).getSupportpereat());
                ps.setDouble(4, foods.get(i).getCalory());
                ps.setDouble(5, foods.get(i).getCarbo());
                ps.setDouble(6, foods.get(i).getProtein());
                ps.setDouble(7, foods.get(i).getFat());
                ps.setDouble(8, foods.get(i).getSugar());
                ps.setDouble(9, foods.get(i).getNatrium());
                ps.setDouble(10, foods.get(i).getChole());
                ps.setDouble(11, foods.get(i).getFattyacid());
                ps.setDouble(12, foods.get(i).getTransfat());
                ps.setString(13, foods.get(i).getMaker());
                ps.setString(14, foods.get(i).getMaterial());
                ps.setString(15, foods.get(i).getImg());
                ps.execute();
            } catch (SQLException e) {
                e.printStackTrace();
            } finally {
                close();
            }
        }
    }

    public List<Food> searchAll() {
        List<Food> finds = new LinkedList<Food>();
        String str = "select * from food";
        Food f;
        try {
            ps = conn.prepareStatement(str);
            rs = ps.executeQuery();
            while (rs.next()) {
                f = new Food();
                f.setCode(rs.getInt("code"));
                f.setName(rs.getString("name"));
                f.setSupportpereat(rs.getDouble("supportpereat"));
                f.setCalory(rs.getDouble("calory"));
                f.setCarbo(rs.getDouble("carbo"));
                f.setProtein(rs.getDouble("protein"));
                f.setFat(rs.getDouble("fat"));
                f.setSugar(rs.getDouble("sugar"));
                f.setNatrium(rs.getDouble("natrium"));
                f.setChole(rs.getDouble("chole"));
                f.setFattyacid(rs.getDouble("fattyacid"));
                f.setTransfat(rs.getDouble("transfat"));
                f.setMaker(rs.getString("maker"));
                f.setMaterial(rs.getString("material"));
                f.setImg(rs.getString("img"));
                finds.add(f);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return finds;
    }

    @Override
    public List<Food> search_name(String name) {
        List<Food> finds = new LinkedList<Food>();
        String str = "select * from food where name like ?";
        Food f = null;
        try {
            ps = conn.prepareStatement(str);
            ps.setString(1, "%" + name + "%");
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                f = new Food();
                f.setCode(rs.getInt("code"));
                f.setName(rs.getString("name"));
                f.setSupportpereat(rs.getDouble("supportpereat"));
                f.setCalory(rs.getDouble("calory"));
                f.setCarbo(rs.getDouble("carbo"));
                f.setProtein(rs.getDouble("protein"));
                f.setFat(rs.getDouble("fat"));
                f.setSugar(rs.getDouble("sugar"));
                f.setNatrium(rs.getDouble("natrium"));
                f.setChole(rs.getDouble("chole"));
                f.setFattyacid(rs.getDouble("fattyacid"));
                f.setTransfat(rs.getDouble("transfat"));
                f.setMaker(rs.getString("maker"));
                f.setMaterial(rs.getString("material"));
                f.setImg(rs.getString("img"));
                finds.add(f);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return finds;
    }

    @Override
    public List<Food> search_company(String company) {
        List<Food> finds = new LinkedList<Food>();
        String str = "select * from food where maker like ?";
        Food f = null;
        try {
            ps = conn.prepareStatement(str);
            ps.setString(1, "%" + company + "%");
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                f = new Food();
                f.setCode(rs.getInt("code"));
                f.setName(rs.getString("name"));
                f.setSupportpereat(rs.getDouble("supportpereat"));
                f.setCalory(rs.getDouble("calory"));
                f.setCarbo(rs.getDouble("carbo"));
                f.setProtein(rs.getDouble("protein"));
                f.setFat(rs.getDouble("fat"));
                f.setSugar(rs.getDouble("sugar"));
                f.setNatrium(rs.getDouble("natrium"));
                f.setChole(rs.getDouble("chole"));
                f.setFattyacid(rs.getDouble("fattyacid"));
                f.setTransfat(rs.getDouble("transfat"));
                f.setMaker(rs.getString("maker"));
                f.setMaterial(rs.getString("material"));
                f.setImg(rs.getString("img"));
                finds.add(f);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return finds;
    }

    @Override
    public List<Food> search_material(String material) {
        List<Food> finds = new LinkedList<Food>();
        String str = "select * from food where material like ?";
        Food f = null;
        try {
            ps = conn.prepareStatement(str);
            ps.setString(1, "%" + material + "%");
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                f = new Food();
                f.setCode(rs.getInt("code"));
                f.setName(rs.getString("name"));
                f.setSupportpereat(rs.getDouble("supportpereat"));
                f.setCalory(rs.getDouble("calory"));
                f.setCarbo(rs.getDouble("carbo"));
                f.setProtein(rs.getDouble("protein"));
                f.setFat(rs.getDouble("fat"));
                f.setSugar(rs.getDouble("sugar"));
                f.setNatrium(rs.getDouble("natrium"));
                f.setChole(rs.getDouble("chole"));
                f.setFattyacid(rs.getDouble("fattyacid"));
                f.setTransfat(rs.getDouble("transfat"));
                f.setMaker(rs.getString("maker"));
                f.setMaterial(rs.getString("material"));
                f.setImg(rs.getString("img"));
                finds.add(f);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close();
        }
        return finds;
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
