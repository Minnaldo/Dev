package bin;

public class ProductMgr {

    /**
     * Product객체 배열
     */
    private Product[] parr;
    /**
     * Product객체 배열의 인덱스
     */
    int idx = 0;
    /**
     * Product객체 배열의 최댓값
     */
    int max = 10;

    ProductMgr() {
        parr = new Product[10];
    }

    public void addProduct(Product p) {
        if (idx > max) {
            Product[] tmp = new Product[max * 2];
            System.arraycopy(parr, 0, tmp, 0, parr.length);
            parr = tmp;
            max *= 2;
        } else {
            parr[idx] = p;
            idx++;
        }
    }

    public String searchAll() {
        String tmp = "";
        for (int i = 0; i < idx; i++) {
            tmp += parr[i].toString() + "\n";
        }

        return tmp;
    }

    public String searchProductNum(int proNum) {
        for (int i = 0; i < idx; i++) {
            if (parr[i].getProductNum() == proNum) {
                return parr[i].toString();
            }
        }
        return "찾는 물품이 없습니다";
    }

    // 상품명으로 부분검색 가능
    public String searchName(String name) {
        for (int i = 0; i < idx; i++) {
            if (parr[i].getName().contains(name) || parr[i].getName().equals(name)) {
                return parr[i].toString();
            }
        }
        return "찾는 물품이 없습니다";
    }

    public String searchTV() {
        String tmp = "";
        for (int i = 0; i < idx; i++) {
            if (parr[i] instanceof TV) {
                tmp += parr[i].toString() + "\n";
            }
        }

        return tmp;
    }

    public String searchRefrigerator() {
        String tmp = "";
        for (int i = 0; i < idx; i++) {
            if (parr[i] instanceof Refrigerator) {
                tmp += parr[i].toString() + "\n";
            }
        }

        return tmp;
    }

    public void delNum(int proNum) {
        for (int i = 0; i < idx; i++) {
            if (parr[i].getPrice() == proNum) {
                parr[i] = parr[idx];
                idx--;
                break;
            }
        }
    }

    public int getStockPriceSum() {
        int sum = 0;

        for (int i = 0; i < idx; i++) {
            sum += parr[i].getPrice();
        }

        return sum;
    }

    public String searchInch(int inch) {
        String tmp = "";
        for (int i = 0; i < idx; i++) {
            if (parr[i] instanceof TV) {
                TV t = (TV) parr[i];
                if (t.getInch() < inch) {
                    tmp += t.toString() + "\n";
                }
            }
        }
        return tmp;
    }

    public String searchVol(int volum) {
        String tmp = "";
        for (int i = 0; i < idx; i++) {
            if (parr[i] instanceof Refrigerator) {
                Refrigerator ref = (Refrigerator) parr[i];
                if (ref.getVolume() >= volum) {
                    tmp += ref.toString() + "\n";
                }
            }
        }

        return tmp;
    }
}
