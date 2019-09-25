package model;

import java.util.List;

public interface FoodDao {

<<<<<<< Updated upstream
    void loadData(String string, String string2);

    List<Food> searchAll();

    List<Food> search_material(String material);

    List<Food> search_name(String name);

    List<Food> search_company(String company);
=======
    public void loadData(String string, String string2);

    public List<Food> searchAll();

    public List<Food> search_material(String material);

    public List<Food> search_name(String name);

    public List<Food> search_company(String company);
>>>>>>> Stashed changes

    void close();
}
