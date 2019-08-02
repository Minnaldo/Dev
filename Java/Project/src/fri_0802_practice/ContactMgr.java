package fri_0802_practice;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class ContactMgr implements IContactMgr {

    private ArrayList<Contact> arr;
    private static ContactMgr instance = new ContactMgr();

    public static ContactMgr getInstance() {
        return instance;
    }

    private ContactMgr() {
        arr = new ArrayList<>();
        fileOpen();
    }

    @Override
    public boolean isDuplicate(Contact c) {
        for (Contact cc : arr) {

        }
        return false;
    }


    public void fileOpen() {
        ObjectInputStream ois = null;

        try {
            ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("contact.dat")));
            arr = (ArrayList<Contact>) ois.readObject();
        } catch (FileNotFoundException e) {
            e.printStackTrace();

        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            if (ois != null) {
                try {
                    ois.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public void fileClose() {
        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("contact.dat")));
            oos.writeObject(arr);
            oos.flush();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                oos.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }


    public void sort() {
        Collections.sort(arr);
    }

    @Override
    public void add(Contact c) throws DuplicateContactException {
        if (search(c.getNumber()) == null)
            arr.add(c);
        else {
            throw new DuplicateContactException();
        }
    }

    @Override
    public Contact search(Contact c) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).compareTo(c) == 0) {
                return arr.get(i);
            }
        }
        return null;
    }

    @Override
    public void update(Contact c) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).getName().equals(c.getName())) {
                arr.get(i).setCompany(c.getCompany());
            }
        }
    }

    // name을 포함하는 모든 연락처를 리턴해준다
    @Override
    public ArrayList<Contact> search(String name) {
        ArrayList<Contact> tmp = new ArrayList<>();
        for (Contact c : arr) {
            if (c.getName().contains(name)) {
                tmp.add(c);
            }
        }
        return tmp;
    }

    @Override
    public void delete(String num) throws ContactNotFoundException {
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).getNumber().equals(num)) {
                arr.remove(i);
                break;
            }
        }

        throw new ContactNotFoundException();
    }
}
