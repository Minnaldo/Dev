package hw_java_0729;

import java.util.ArrayList;

public interface IProductMgr {
    void add(Product p);
    ArrayList<Product> searchAll();
    ArrayList<Product> searchProNum(int proNum);
    ArrayList<Product> searchName(String name);
    ArrayList<Product> searchOnlyTv();
    ArrayList<Product> searchOnlyRefrigerator();
    ArrayList<Product> searchUpTo400Liter();
    ArrayList<Product> searchUpTo50inch();
    void changeProductPrice(int proNum, int price);
    void removeProduct(int proNum);
    int priceSum();
    boolean isDuplicate(Product p);
}
