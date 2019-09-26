package model;

import java.util.ArrayList;

public interface isafeFoodMgr {
    boolean addMember(String id, String pw, String name, String addr, String tel, String allergy);

    boolean loginMemeber(String id, String pw);

    ArrayList<MemberVO> search(String id);

    void deleteMember(String id);

    MemberVO searchMember(String id);

    boolean modifyMember(String id, String pw, String name, String addr, String tel, String allergy);

    ArrayList<AnnounceVO> announceList();

    AnnounceVO announce(int number);

    void close();
}
