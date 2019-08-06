package com.ssafy.bms;

import java.util.Scanner;

public class BookMain {
    Scanner s = new Scanner(System.in);
    IBookMgr mgr = BookMgrImpl.getInstance();

    public static void main(String[] args) {
        BookMain m = new BookMain();
        int num = 0;
        while (true) {
            num = m.menu();
            if (num == 0)
                break;
            switch (num) {
                case 1:
                    m.insert();
                    break;
                case 2:
                    m.search();
                    break;
                case 3:
                    m.searchIsbn();
                    break;
                case 4:
                    m.searchTitle();
                    break;
                case 5:
                    m.update();
                    m.search();
                    break;
                case 6:
                    m.delete();
                    m.search();
                    break;
                case 7:
                    m.save();
                    break;
                case 8:
                    m.load();
                    m.search();
                    break;
                case 9:
                    m.sortIsbn();
                    break;
                case 10:
                    m.countWord();
                    break;
            }// end switch

        } // end while
    }

    public int menu() {
        int result = 0;
        System.out.println("==================================");
        System.out.println("========== 도서 관리 프로그램 ===========");
        System.out.println("==================================");
        System.out.println("1. 도서 등록");
        System.out.println("2. 도서 목록 보기");
        System.out.println("3. 도서 검색(ISBN으로 검색)");
        System.out.println("4. 도서 검색(도서명으로 검색)");
        System.out.println("5. 도서 수정");
        System.out.println("6. 도서 삭제");
        System.out.println("7. 도서 정보 파일 저장");
        System.out.println("8. 도서 정보 파일로 부터 읽어오기");
        System.out.println("9. ISBN으로 정렬해서 목록보기");
        System.out.println("10.도서명 중 가장 빈도수 높은 단어 구하기");
        System.out.println("0. 종료");
        System.out.println("원하는  번호를 선택 하세요.");
        result = Integer.parseInt(s.nextLine());
        return result;

    }

    public void insert() {
        System.out.println("도서 정보를 입력하세요. 형식:ISBN,도서명,저자,금액");
        String[] info = s.nextLine().split(",");

        // 구현하세요.
        try {
            mgr.add(new Book(info[0], info[1], info[2], Integer.parseInt(info[3])));
        } catch (NumberFormatException e) {
        } catch (DuplicateException e) {
        }
    }

    public void search() {
        System.out.println(">>>>>>>>  도서 목록 보기 ");

        // 구현하세요.
        for (Book b : mgr.search()) {
            System.out.println(b.toString());
        }

    }

    public void searchIsbn() {
        System.out.println(">>>>>>>>  도서  검색 (ISBN으로 검색) ");
        System.out.println("검색하고자하는 ISBN을 입력하세요.");
        String isbn = s.nextLine();

        // 구현하세요.
        try {
            System.out.println(mgr.search(isbn).toString());
        } catch (RecordNotFoundException e) {
        }
    }

    public void searchTitle() {
        System.out.println(">>>>>>>>  도서  검색 (이름으로 검색) ");
        System.out.println("검색하고자하는 이름을 입력하세요.");
        String title = s.nextLine();

        // 구현하세요.
        for (Book b : mgr.searchTitle(title)) {
            System.out.println(b.toString());
        }

    }

    public void update() {
        System.out.println(">>>>>>>>  도서  수정 ");
        System.out.println("수정하고자하는 ISBN,금액을 입력하세요.");
        String[] info = s.nextLine().split(",");

        // 구현하세요.
        try {
            mgr.update(info[0], Integer.parseInt(info[1]));
        } catch (NumberFormatException e) {
        } catch (RecordNotFoundException e) {
        }
    }

    public void delete() {
        System.out.println(">>>>>>>>  도서  삭제 ");
        System.out.println("삭제하고자하는 ISBN을 입력하세요.");
        String isbn = s.nextLine();

        // 구현하세요.
        try {
            mgr.delete(isbn);
        } catch (RecordNotFoundException e) {
        }

    }

    public void save() {
        System.out.println(">>>>>>>>  도서  정보 저장 ");

        // 구현하세요.
        mgr.save();
        // TODO:
        System.out.println("도서 정보를 저장하였습니다.");
    }

    public void load() {
        System.out.println(">>>>>>>>  도서  정보 읽어오기 ");

        // 구현하세요.
        mgr.load();
    }

    public void sortIsbn() {
        System.out.println(">>>>>>>>  도서ISBN로 정렬하기 ");

        // 구현하세요.
        for (Book b : mgr.sortIsbn()) {
            System.out.println(b.toString());
        }

    }

    public void countWord() {
        System.out.println(">>>>>>>>  빈도수 높은 단어 구하기 ");

        // 구현하세요.

        System.out.println("가장 많이 나온 단어는 : \"" + mgr.countWord() + "\"입니다.");
    }
    /*
     * public void sortTitle() { System.out.println(">>>>>>>>  도서이름로 정렬하기 ");
     * List<Book> bs=mgr.sortTitle(); for(Book e: bs) { System.out.println(e); } }
     */
}
