package hw_java_0729;

import java.util.ArrayList;

public class ProductMgrImpl implements IProductMgr {

    private ArrayList<Product> parr = new ArrayList<>();

    private static ProductMgrImpl instance = new ProductMgrImpl();

    public static ProductMgrImpl getInstance() {
        return instance;
    }

    @Override
    public void add(Product p) {
        if (isDuplicate(p)) {
            for (int i = 0; i < parr.size(); i++) {
                if (parr.get(i).getName().equals(p.getName()) || parr.get(i).getProNum() == p.getProNum())
                    parr.get(i).setStock(parr.get(i).getStock() + p.getStock());
            }
        } else {
            parr.add(p);
        }
        System.out.println("저장되었습니다");
    }

    @Override
    public ArrayList<Product> searchAll() {
        return parr;
    }

    @Override
    public ArrayList<Product> searchProNum(int proNum) {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : parr) {
            if (p.getProNum() == proNum) {
                tmp.add(p);
            }
        }

        return tmp;
    }

    @Override
    public ArrayList<Product> searchName(String name) {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : parr) {
            if (p.getName().contains(name)) {
                tmp.add(p);
            }
        }

        return tmp;
    }

    @Override
    public ArrayList<Product> searchOnlyTv() {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : parr) {
            if (p instanceof TV) {
                tmp.add(p);
            }
        }

        return tmp;
    }

    @Override
    public ArrayList<Product> searchOnlyRefrigerator() {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : parr) {
            if (p instanceof Refrigerator) {
                tmp.add(p);
            }
        }

        return tmp;
    }

    @Override
    public ArrayList<Product> searchUpTo400Liter() {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : parr) {
            if (p instanceof Refrigerator) {
                Refrigerator tv = (Refrigerator) p;
                if (tv.getLiters() >= 400) {
                    tmp.add(p);
                }
            }
        }

        return tmp;
    }

    @Override
    public ArrayList<Product> searchUpTo50inch() {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : parr) {
            if (p instanceof TV) {
                TV tv = (TV) p;
                if (tv.getInch() >= 50) {
                    tmp.add(p);
                }
            }
        }

        return tmp;
    }

    @Override
    public void changeProductPrice(int proNum, int price) {
        boolean flag = false;
        for (Product p : parr) {
            if (p.getProNum() == proNum) {
                p.setPrice(price);
                System.out.println("가격이 변경되었습니다");
                flag = true;
            }
        }

        if (!flag)
            System.out.println("찾으시는 물건이 없습니다.");
    }

    @Override
    public void removeProduct(int proNum) {
        boolean flag = false;
        for (int i = 0; i < parr.size(); i++) {
            if (parr.get(i).getProNum() == proNum) {
                parr.remove(i);
                System.out.println("물품이 삭제되었습니다.");
                flag = true;
                break;
            }
        }
        if (!flag)
            System.out.println("삭제하려는 물품이 없습니다.");
    }

    @Override
    public int priceSum() {
        int sum = 0;
        for (Product p : parr) {
            sum += p.getPrice() * p.getStock();
        }
        return sum;
    }

    private ProductMgrImpl() {
    }

    @Override
    public boolean isDuplicate(Product p) {
        for (Product pp : parr) {
            if (pp.getProNum() == p.getProNum() || pp.getName().equals(p.getName()))
                return true;
        }
        return false;
    }
}
