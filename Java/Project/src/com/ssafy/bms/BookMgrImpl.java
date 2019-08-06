package com.ssafy.bms;

import java.io.*;
import java.util.*;

public class BookMgrImpl implements IBookMgr {
    private int saveCount = 0;
    private String rmTitle;
    List<Book> list = new ArrayList<>();
    Map<String, Integer> map = new HashMap<>();
    // Singleton pattern
    private static BookMgrImpl instance = new BookMgrImpl();

    private BookMgrImpl() {
        load();
    }

    // Singleton pattern
    public static BookMgrImpl getInstance() {
        return instance;
    }

    @Override
    public void load() {
        ObjectInputStream ois = null;
        try {
            // TODO need file name
            ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("books.dat")));
            list = (List<Book>) ois.readObject();
        } catch (FileNotFoundException e) {
//            e.getMessage();
        } catch (IOException e) {
        } catch (ClassNotFoundException e) {
        } finally {
            if (!list.isEmpty()) {
                try {
                    System.out.println("읽기 완료");
                    ois.close();
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        }
    }

    @Override
    public void save() {
        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("books.dat")));
            oos.writeObject(list);
            oos.flush();
            saveCount = list.size();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                oos.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public void add(Book b) throws DuplicateException {
        // 중복 체크후 중복이 있다면 에러 throw 아니면 집어넣기
        // 도서번호로 중복체크를 한다.
        for (Book bb : list) {
            if (bb.getIsbn().equals(b.getIsbn())) {
                throw new DuplicateException();
            }
        }

        list.add(b);
    }

    @Override
    public List<Book> search() {
        // 저장된 모든 도서 정보를 리턴
        return list;
    }

    @Override
    public Book search(String isbn) throws RecordNotFoundException {
        for (Book b : list) {
            if (b.getIsbn().equals(isbn)) {
                return b;
            }
        }
        // 같은 정보를 못찾았을 때
        throw new RecordNotFoundException();
    }

    @Override
    public void update(String isbn, int price) throws RecordNotFoundException {
        // 전달된 도서번호로 도서를 찾아 금액을 수정
        boolean flag = false;
        for (Book b : list) {
            if (b.getIsbn().equals(isbn)) {
                b.setPrice(price);
                flag = true;
                break;
            }
        }
        if (!flag) throw new RecordNotFoundException();
    }

    @Override
    public void delete(String isbn) throws RecordNotFoundException {
        // 안정성을 증가시킨 방법
        int removeIdx = -1;
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getIsbn().equals(isbn)) {
                removeIdx = i;
                break;
            }
        }

        if (removeIdx != -1) {
            rmTitle = list.get(removeIdx).getTitle();
            list.remove(removeIdx);
        } else {
            throw new RecordNotFoundException();
        }
    }

    @Override
    public List<Book> searchTitle(String title) {
        // 파라미터 title을 포함한 도서들을 리턴
        List<Book> tmp = new ArrayList<>();
        for (Book b : list) {
            if (b.getTitle().contains(title)) {
                tmp.add(b);
            }
        }
        return tmp;
    }


    @Override
    public List<Book> sortIsbn() {
        List<Book> tmp = list;
        list.sort(new Comparator<Book>() {
            @Override
            public int compare(Book o1, Book o2) {

                if (o1.getIsbn().compareTo(o2.getIsbn()) < 0) {
                    return -1;
                } else if (o1.getIsbn().compareTo(o2.getIsbn()) > 0) {
                    return 1;
                }
                return 0;
            }
        });
        return tmp;
    }

    @Override
    public String countWord() {
        // 각 단어를 공백으로 나눠 해시맵 자료구조에 저장
        // 단어를 key로 빈도수를 value로 저장
        for (Book b : list) {
            String[] titArr = b.getTitle().split(" ");
            for (int i = 0; i < titArr.length; i++) {
                System.out.println(titArr[i]);
                if (map.get(titArr[i]) != null) {
                    map.put(titArr[i], map.get(titArr[i]) + 1);
                } else {
                    map.put(titArr[i], 1);
                }
            }
        }

        ArrayList<pair> tmpArr = new ArrayList<>();
        for (String keys : map.keySet()) {
            tmpArr.add(new pair(keys, map.get(keys)));
        }

        Collections.sort(tmpArr, (o1, o2) -> {
            if (o1.freq >= o2.freq) {
                return -1;
            } else {
                return 1;
            }
        });

        int frequant = tmpArr.get(0).freq;

        ArrayList<String> ans = new ArrayList<>();
        for (pair p : tmpArr) {
            if (p.freq == frequant) {
                ans.add(p.name);
            }
        }

        return ans.toString();
    }

    @Override
    public int getSaveCount() {
        return saveCount;
    }

    @Override
    public String getRmTitle() {
        return rmTitle;
    }

    private class pair {
        String name;
        int freq;

        pair(String name, int freq) {
            this.name = name;
            this.freq = freq;
        }
    }

}
