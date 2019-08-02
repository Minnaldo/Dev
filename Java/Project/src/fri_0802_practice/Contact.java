package fri_0802_practice;

import java.io.Serializable;

// 전화 데이터 구현
public class Contact implements Comparable<Contact>, Serializable {
    private String name;
    private String number;
    private String company;

    public Contact() {
    }

    public Contact(String name, String number, String company) {
        this.name = name;
        this.number = number;
        this.company = company;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public String getCompany() {
        return company;
    }

    public void setCompany(String company) {
        this.company = company;
    }


    @Override
    public int compareTo(Contact o) {
        //  이름으로 오름차순 정렬
        if (name.compareTo(o.getName()) < 0) {
            return -1;
        } else if (name.compareTo(o.getName()) == 0) {
            return 0;
        } else
            return 1;
    }

    @Override
    public String toString() {
        return "Contact{" +
                "name='" + name + '\'' +
                ", number='" + number + '\'' +
                ", company='" + company + '\'' +
                '}';
    }
}
