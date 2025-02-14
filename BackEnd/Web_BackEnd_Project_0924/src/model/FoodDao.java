package model;

import java.util.List;

public interface FoodDao {

    void loadData(String string, String string2);

    List<Food> searchAll();

    List<Food> search_material(String material);

    List<Food> search_name(String name);

    List<Food> search_company(String company);

    void close();
}
