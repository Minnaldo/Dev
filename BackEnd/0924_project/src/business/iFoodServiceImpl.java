package business;

import model.Food;
import model.FoodDao;
import model.FoodDaoImpl;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class iFoodServiceImpl implements iFoodService {
    private FoodDao dao;
    private String[] allergys = {"대두", "땅콩", "우유", "게", "새우", "참치", "연어", "쑥", "소고기", "닭고기", "돼지고기", "복숭아", "민들레", "계란흰자"};

    public iFoodServiceImpl() throws SQLException {
        dao = new FoodDaoImpl();
    }

    // TODO
    public Food search(String name) {
        String str = "select * from food where name like ?";
        PreparedStatement pt;
        Food f = null;
        try {
            pt = conn.prepareStatement(str);
            pt.setString(1, "%" + name + "%");
            ResultSet rs = pt.executeQuery();
            f = dao.search_name(name).get(0);
            String s = "";
            for (int i = 0; i < allergys.length; i++) {
                if (f.getMaterial().contains(allergys[i])) {
                    s = s + allergys[i] + " ";
                }
            }
            f.setAllergy(s);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return f;
    }
}
