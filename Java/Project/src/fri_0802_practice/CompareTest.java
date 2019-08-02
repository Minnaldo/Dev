package fri_0802_practice;

import java.util.ArrayList;
import java.util.Collections;

public class CompareTest {
    public static void main(String[] args) {

        ArrayList<Contact> arr = new ArrayList<>();

        arr.add(new Contact("123", "aa", "com"));
        arr.add(new Contact("456", "cc", "com"));
        arr.add(new Contact("234", "bb", "com"));
        arr.add(new Contact("987", "dd", "com"));
        arr.add(new Contact("123456", "qq", "com"));

        for (Contact aa : arr) {
            System.out.println(aa.toString());
        }

        System.out.println("__________________");
        Collections.sort(arr);
        for (Contact aa : arr) {
            System.out.println(aa.toString());
        }

        System.out.println("========================================");

        Collections.sort(arr, (o1, o2) -> {
            if (o1.getNumber().compareTo(o2.getNumber()) < 0) {
                return -1;
            } else if (o1.getNumber().compareTo(o2.getNumber()) > 0) {
                return 1;
            } else { return 0;
            }
        });

        for (Contact aa : arr) {
            System.out.println(aa.toString());
        }

    }
}
