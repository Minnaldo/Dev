package chap02;

import java.sql.SQLException;

public class CustomerMain {


    public static void main(String[] args) {
        DBManager man = null;
        try {
            man = new DBManager();
//            man.insertCustomer("홍길동", 21, "광산구");
//            man.insertCustomer("박길동", 41, "광산구");
//            man.insertCustomer("고길동", 31, "광산구");

//            man.updateCustomer(2, "둘리", 21, "쌍문동");
//            man.deleteCostumer(2);

            CustomerVO vo = man.queryCustomer(1);
            System.out.println(vo.toString());

//            for (CustomerVO vo : man.queryCustomer()) {
//                System.out.println(vo.toString());
//            }
        } finally {
            if (man != null) {
                man.close();
            }
        }
    }
}
