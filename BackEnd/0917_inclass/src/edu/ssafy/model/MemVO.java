package edu.ssafy.model;

public class MemVO {
    private String id;
    private String name;
    private String pwd;
    private String addr;
    private String age;
    private String tel;

    public MemVO() {
    }

    public MemVO(String id, String name, String pwd, String addr, String age, String tel) {
        this.id = id;
        this.name = name;
        this.pwd = pwd;
        this.addr = addr;
        this.age = age;
        this.tel = tel;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPwd() {
        return pwd;
    }

    public void setPwd(String pwd) {
        this.pwd = pwd;
    }

    public String getAddr() {
        return addr;
    }

    public void setAddr(String addr) {
        this.addr = addr;
    }

    public String getAge() {
        return age;
    }

    public void setAge(String age) {
        this.age = age;
    }

    public String getTel() {
        return tel;
    }

    public void setTel(String tel) {
        this.tel = tel;
    }

    @Override
    public String toString() {
        return "MemVO{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", pwd='" + pwd + '\'' +
                ", addr='" + addr + '\'' +
                ", age='" + age + '\'' +
                ", tel='" + tel + '\'' +
                '}';
    }
}
