package hw_java_0730;

import java.util.ArrayList;

public interface IProductMgr {
    void add(Product p) throws DuplicateException;

    ArrayList<Product> searchAll();

    ArrayList<Product> searchProNum(int proNum) throws CodeNotFoundException;

    ArrayList<Product> searchName(String name);

    ArrayList<Product> searchOnlyTv();

    ArrayList<Product> searchOnlyRefrigerator();

    ArrayList<Product> searchUpTo400Liter() throws ProductNotFoundException;

    ArrayList<Product> searchUpTo50inch() throws ProductNotFoundException;

    void changeProductPrice(int proNum, int price);

    void removeProduct(int proNum);

    int priceSum();
    boolean isDuplicate(Product p);
}
