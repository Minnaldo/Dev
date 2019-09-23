package model;

import java.sql.SQLException;
import java.util.ArrayList;

public interface IProductMgr {
    boolean addProduct(String id, String name, String price, String stock, String description);

    ArrayList<ProductVO> getProductList();

    ArrayList<ProductVO> getProductList(String type, String value);

    ProductVO getProduct(String type, String value);

    ProductVO update(String id, String name, String price, String stock, String description);

    boolean removeProduct(String id);

    ProductVO search(String name);

    void close() throws SQLException;
}
