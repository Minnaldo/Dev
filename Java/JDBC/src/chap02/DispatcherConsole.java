package chap02;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Scanner;

public class DispatcherConsole {

    int menu;
    Scanner sc;
    DBManager man;

    public DispatcherConsole() throws SQLException {
        sc = new Scanner(System.in);
        man = new DBManager();
    }

    private void go() {
        createGUI();
    }

    private void createGUI() {
        JFrame f = new JFrame();
        JPanel pUp = new JPanel();
        JPanel pDown = new JPanel();
        JButton bIn = new JButton();
        bIn.setText("Insert");
        JButton bUp = new JButton();
        bUp.setText("Update");
        JButton bDe = new JButton();
        bDe.setText("Delete");
        JTextField tfName = new JTextField();
        tfName.setColumns(10);
        JTextField tfAge = new JTextField();
        tfAge.setColumns(10);
        JTextField tfAddr = new JTextField();
        tfAddr.setColumns(10);
        JTextArea taList = new JTextArea();

        pUp.add(tfName);
        pUp.add(tfAge);
        pUp.add(tfAddr);

        pDown.add(bIn);
        pDown.add(bUp);
        pDown.add(bDe);

        f.add(pUp, BorderLayout.NORTH);
        f.add(pDown, BorderLayout.SOUTH);
        f.add(taList);
        f.setSize(500, 500);
        f.setLocation(300, 200);
        f.setVisible(true);

        ArrayList<CustomerVO> list = man.queryCustomer();
        for (CustomerVO vo : list) {
            taList.append(vo.toString() + "\n");
        }

        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                System.exit(0);
            }
        });
        bIn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                man.insertCustomer(tfName.getText(), Integer.parseInt(tfAge.getText()), tfAddr.getText());
                ArrayList<CustomerVO> list = man.queryCustomer();
                // 화면을 지운다
                taList.setText("");
                for (CustomerVO vo : list) {
                    taList.append(vo.toString() + "\n");
                }
            }
        });
        bUp.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                man.updateCustomer();
            }
        });
        bDe.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                man.deleteCostumer();
            }
        });
    }

//    private void search() {
//        System.out.println("검색할 번호를 입력하세요.");
//        int num = sc.nextInt();
//        CustomerVO vo = man.queryCustomer(num);
//        System.out.println(vo);
//    }
//
//    private void list() {
//        for (CustomerVO vo : man.queryCustomer()) {
//            System.out.println(vo);
//        }
//    }
//
//    private void delete() throws SQLException {
//        System.out.println("삭제할 번호를 입력하세요.");
//        man.deleteCostumer(sc.nextInt());
//        list();
//    }
//
//    private void update() throws SQLException {
//        System.out.println("업데이트할 번호를 입력하세요");
//        int num = sc.nextInt();
//        System.out.println("업데이트할 이름을 입력하세요");
//        String name = sc.next();
//        System.out.println("업데이트할 나이를 입력하세요");
//        int age = sc.nextInt();
//        System.out.println("업데이트할 주소를 입력하세요");
//        String addr = sc.next();
//        man.updateCustomer(num, name, age, addr);
//        list();
//    }
//
//    private void insert() {
//        System.out.println("이름을 입력하세요");
//        String name = sc.next();
//        System.out.println("나이를 입력하세요");
//        int age = sc.nextInt();
//        System.out.println("주소를 입력하세요");
//        String addr = sc.next();
//
//        man.insertCustomer(name, age, addr);
//        list();
//    }


    public static void main(String[] args) {
        try {
            new DispatcherConsole().go();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
