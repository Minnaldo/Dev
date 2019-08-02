package fri_0802_practice;

import java.util.ArrayList;

public interface IContactMgr {
    void add(Contact c) throws DuplicateContactException;

    void update(Contact c);

    boolean isDuplicate(Contact c);

    Contact search(Contact c) throws ContactNotFoundException;

    ArrayList<Contact> search(String name);

    void delete(String num) throws ContactNotFoundException;

}
