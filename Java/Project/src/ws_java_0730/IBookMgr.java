package ws_java_0730;

import java.util.ArrayList;

public interface IBookMgr {
    // 도서 최초 입력 기능
    void add(Book b);

    // 전체 도서 정보 출력
    ArrayList<Book> search();

    // 도서가 판매되어 재고 수량을 빼는 기능
    void sell(String isbn, int quantity) throws QuantityException, ISBNNotFoundException;

    // 도서가 구매되어 재고 수량을 더하는 기능
    void buy(String isbn, int quantity) throws ISBNNotFoundException;

    // 재고 도서들의 수량 * 금액 (; 총재고금액)
    int getTotalAmount();

}
