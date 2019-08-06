package hw_java_0805;

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;

public class ProductMgrImpl implements IProductMgr {
    private static ArrayList<Product> pArr = new ArrayList<>();
    private static ProductMgrImpl instance = new ProductMgrImpl();

    public static ProductMgrImpl getInstance() {
        return instance;
    }

    private ProductMgrImpl() {
        open();
    }

    @Override
    public void add(Product p) throws DuplicateException {
        if (isDuplicate(p)) {
            for (int i = 0; i < pArr.size(); i++) {
                if (pArr.get(i).getNum() == p.getNum() || pArr.get(i).getName().equals(p.getName())) {
                    pArr.get(i).setStock(pArr.get(i).getStock() + p.getStock());
                }
            }
            throw new DuplicateException("이미 존재하는 상품입니다. 재고 수량은 합산됩니다.");
        } else {
            pArr.add(p);

        }
    }

    @Override
    public ArrayList<Product> searchAll() {
        return pArr;
    }

    @Override
    public ArrayList<Product> searchProNum(int proNum) throws CodeNotFoundException {
        boolean flag = false;
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : pArr) {
            if (p.getNum() == proNum) {
                tmp.add(p);
                flag = true;
            }
        }

        if (!flag)
            throw new CodeNotFoundException("해당하는 상품번호를 찾을 수 없습니다.");
        return tmp;
    }

    @Override
    public ArrayList<Product> searchName(String name) {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : pArr) {
            if (p.getName().contains(name)) {
                tmp.add(p);
            }
        }
        return tmp;
    }

    @Override
    public ArrayList<Product> searchOnlyTv() {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : pArr) {
            if (p instanceof TV) {
                tmp.add(p);
            }
        }
        return tmp;
    }

    @Override
    public ArrayList<Product> searchOnlyRefrigerator() {
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : pArr) {
            if (p instanceof Refrigerator) {
                tmp.add(p);
            }
        }

        return tmp;
    }

    @Override
    public ArrayList<Product> searchUpTo400Liter() throws ProductNotFoundException {
        boolean flag = false;
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : pArr) {
            if (p instanceof Refrigerator) {
                Refrigerator tv = (Refrigerator) p;
                if (tv.getLiter() >= 400) {
                    tmp.add(p);
                    flag = true;
                }
            }
        }
        if (!flag)
            throw new ProductNotFoundException("조건에 맞는 상품을 찾을 수 없습니다.");
        return tmp;
    }

    @Override
    public ArrayList<Product> searchUpTo50inch() throws ProductNotFoundException {
        boolean flag = false;
        ArrayList<Product> tmp = new ArrayList<>();
        for (Product p : pArr) {
            if (p instanceof TV) {
                TV tv = (TV) p;
                if (tv.getInch() >= 50) {
                    tmp.add(p);
                    flag = true;
                }
            }
        }
        if (!flag)
            throw new ProductNotFoundException("조건에 맞는 상품을 찾을 수 없습니다.");
        return tmp;
    }

    @Override
    public void changeProductPrice(int proNum, int price) {
        boolean flag = false;
        for (Product p : pArr) {
            if (p.getNum() == proNum) {
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
        for (int i = 0; i < pArr.size(); i++) {
            if (pArr.get(i).getNum() == proNum) {
                pArr.remove(i);
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
        for (Product p : pArr) {
            sum += p.getPrice() * p.getStock();
        }
        return sum;
    }

    private static void open() {
        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("product.dat")));
            Product p;
            while ((p = (Product) ois.readObject()) != null) {
                pArr.add(p);
            }
            System.out.println("상품 정보를 성공적으로 불러들였습니다.");
        } catch (FileNotFoundException e) {
//            e.printStackTrace();
            System.err.println("상품 정보를 찾지 못하였습니다.");
        } catch (ClassNotFoundException e) {
//            e.printStackTrace();
            System.err.println("상품 정보 클래스를 찾지 못하였습니다.");
        } catch (IOException e) {
//            e.printStackTrace();
        } finally {
            try {
                if (ois != null)
                    ois.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    // 스레드를 이용한 파일 저장
    public void close() {
        Thread saveThread = new Thread(new Runnable() {
            @Override
            public void run() {
                ObjectOutputStream oos = null;
                try {
                    oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("product.dat")));
                    for (Product p : pArr) {
                        oos.writeObject(p);
                    }
                    System.out.println("저장이 완료되었습니다.");
                } catch (IOException e) {
                    System.err.println("저장 중 문제가 생겼습니다.");
                } finally {
                    if (oos != null)
                        try {
                            oos.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                }
            }
        });

        saveThread.start();
    }

    @Override
    public boolean isDuplicate(Product p) {
        for (Product pp : pArr) {
            if (pp.getNum() == p.getNum() || pp.getName().equals(p.getName()))
                return true;
        }
        return false;
    }

    @Override
    public void send() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                ArrayList<Product> tmp = new ArrayList<>();
                // TV만 추가
                for (Product p : pArr) {
                    if (p instanceof TV) {
                        tmp.add(p);
                    }
                }
                // 냉장고만 추가
                for (Product p : pArr) {
                    if (p instanceof Refrigerator) {
                        tmp.add(p);
                    }
                }
                try (Socket socket = new Socket("localhost", 8080)) {
                    ObjectOutputStream oos = new ObjectOutputStream(new BufferedOutputStream(socket.getOutputStream()));
                    oos.writeObject(tmp);

                    oos.flush();
                    oos.close();
                } catch (UnknownHostException e) {
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }).start();
    }
}
