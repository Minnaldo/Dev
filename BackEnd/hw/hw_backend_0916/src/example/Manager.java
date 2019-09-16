package example;

import java.util.ArrayList;

public class Manager {
    private ArrayList<Product> list = new ArrayList<>();

    private static Manager instance = new Manager();

    public static Manager getInstance() {
        return instance;
    }

    private Manager() {
    }

    //상품 입력
    public void addProduct(String name, String price, String desc) {
        list.add(new Product(list.size()+1, name, price, desc));
    }

    //조회
    public Product find(String name) {
        for (Product p : list) {
            if (p.getName().equals(name)) {
                return p;
            }
        }
        return null;
    }

    //목록조회
    public ArrayList<Product> search() {
        return list;
    }
}
