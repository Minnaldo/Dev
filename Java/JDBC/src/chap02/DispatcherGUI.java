package chap02;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Scanner;

public class DispatcherGUI {
    int menu;
    Scanner s;
    DBManager man;

    public DispatcherGUI() throws SQLException {
        s = new Scanner(System.in);
        man = new DBManager();
    }

    private void go() {
        createGUI();
    }

    JFrame f = new JFrame();
    JPanel pUp = new JPanel();
    JPanel pDown = new JPanel();
    JButton bI = new JButton();
    JButton bU = new JButton();
    JButton bD = new JButton();
    JTextField tfName = new JTextField();
    JTextField tfAge = new JTextField();
    JTextField tfAddr = new JTextField();
    // JTextArea taList = new JTextArea();
    JList jlist = new JList();
    DefaultListModel<CustomerVO> model = new DefaultListModel<>();
    CustomerVO selected = new CustomerVO();

    private void createGUI() {
        // TODO Auto-generated method stub
        bI.setText("Insert");
        bU.setText("Update");
        bD.setText("Delete");
        tfName.setColumns(10);
        tfAge.setColumns(10);
        tfAddr.setColumns(10);

        jlist.setModel(model);

        pUp.add(tfName);
        pUp.add(tfAge);
        pUp.add(tfAddr);
        pDown.add(bI);
        pDown.add(bU);
        pDown.add(bD);
        f.add(pUp, BorderLayout.NORTH);
        f.add(pDown, BorderLayout.SOUTH);
        f.add(jlist);

        f.setSize(400, 500);
        f.setLocation(3000, 300);
        f.setVisible(true);

        ArrayList<CustomerVO> list = man.queryCustomer();
        for (CustomerVO c : list) {
            // taList.append(c.toString() + "\n");
            model.addElement(c);

        }

        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                // TODO Auto-generated method stub
                super.windowClosing(e);
                System.exit(0);
            }
        });

        bI.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                String name = tfName.getText();
                int age = Integer.parseInt(tfAge.getText());
                String addr = tfAddr.getText();
                man.insertCustomer(name, age, addr);
                ArrayList<CustomerVO> list = man.queryCustomer();
                // taList.setText(null);
                model.clear();
                for (CustomerVO c : list) {
                    // taList.append(c.toString() + "\n");
                    model.addElement(c);
                    ;
                }
            }
        });
        bU.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO Auto-generated method stub
                if (selected != null) {
                    try {
                        man.updateCustomer(selected.getNum(), tfName.getText()
                                , Integer.parseInt(tfAge.getText()), tfAddr.getText());
                    } catch (SQLException ex) {
                        ex.printStackTrace();
                    }

                    model.clear();
                    ArrayList<CustomerVO> list = man.queryCustomer();
                    for (CustomerVO c : list) {
                        // taList.append(c.toString() + "\n");
                        model.addElement(c);

                    }
                }
            }
        });
        bD.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO Auto-generated method stub
                if (selected != null) {
                    try {
                        man.deleteCustomer(selected.getNum());
                    } catch (SQLException ex) {
                        ex.printStackTrace();
                    }

                    model.clear();
                    ArrayList<CustomerVO> list = man.queryCustomer();
                    for (CustomerVO c : list) {
                        // taList.append(c.toString() + "\n");
                        model.addElement(c);

                    }
                }
            }
        });


        jlist.addListSelectionListener(new ListSelectionListener() {

            @Override
            public void valueChanged(ListSelectionEvent e) {
                // TODO Auto-generated method stub
                if (jlist.getValueIsAdjusting()) {
                    selected = (CustomerVO) jlist.getSelectedValue();
                    tfName.setText(selected.getName());
                    tfAge.setText(selected.getAge() + "");
                    tfAddr.setText(selected.getAddr());
                }
            }
        });
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        try {
            new DispatcherGUI().go();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
