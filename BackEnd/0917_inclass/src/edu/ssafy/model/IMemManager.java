package edu.ssafy.model;

import java.util.ArrayList;

public interface IMemManager {
    boolean addMem(String name, String id, String pwd, String addr, String age, String tel);

    boolean delMem(String id);

    boolean updateMem(String name, String id, String pwd, String addr, String age, String tel);

    ArrayList<MemVO> searchAll();

    MemVO memInfo(String id);

    boolean memberChk(String id, String pw);

    ArrayList<MemVO> searchMem(String name);

    boolean isLogin(String id, String pw);

    void close();

}
