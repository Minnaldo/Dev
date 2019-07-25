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
    int max = 1;

    ProductMgr() {
        parr = new Product[max];
    }

    public void addProduct(Product p) {
        if (isDuplicate(p)) {
            if (idx < max) {
                parr[idx++] = p;
            } else {
                Product[] tmp = new Product[max * 2];
                max *= 2;
                System.arraycopy(parr, 0, tmp, 0, parr.length);
                parr = tmp;
//            addProduct(p);
                parr[idx++] = p;
            }
        }
    }

    public String searchAll() {
        String tmp = "";
        if (idx > 0) {
            for (int i = 0; i < idx; i++) {
                tmp += parr[i].toString() + "\n";
            }
        } else {
            tmp = "품목이 존재하지 않습니다.";
        }

        return tmp;
    }

    public String searchProductNum(int proNum) {
        boolean flag = false;
        String tmp = "";
        for (int i = 0; i < idx; i++) {
            if (parr[i].getProductNum() == proNum) {
                flag = true;
                tmp += parr[i].toString() + "\n";
            }
        }

        if (!flag) {
            return "찾는 물품이 없습니다";
        } else {
            return tmp;
        }

    }

    // 상품명으로 부분검색 가능
    public String searchName(String name) {
        boolean flag = false;
        String tmp = "";
        for (int i = 0; i < idx; i++) {
            if (parr[i].getName().contains(name) || parr[i].getName().equals(name)) {
                tmp += parr[i].toString() + "\n";
            }
        }

        if (!false) {
            return "찾는 물품이 없습니다";
        } else {
            return tmp;
        }
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

    // TODO 이동을 시키니 문제가 생긴다
    public void delNum(int proNum) {
        for (int i = 0; i < idx; i++) {
            if (parr[i].getProductNum() == proNum) {
                parr[i] = parr[idx--];
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

    // TV 화면 크기로 검색
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

    // 냉장고 용량으로 검색
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

    // 중복된 제품번호의 물품이 입력되면, 재고 수량을 합계
    public boolean isDuplicate(Product p) {
        for (int i = 0; i < idx; i++) {
            if (parr[i].getProductNum() == p.getProductNum()) {
                parr[i].setStock(parr[i].getStock() + p.getStock());
                return true;
            }
        }
        return false;
    }

}
