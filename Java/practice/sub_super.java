/**
 *  * 월말 평가 7월
 */


public class sub_super {

    static class Super {
    }

    static class Sub extends Super {
    }

    public static void main(String[] args) {
        Super s = new Super();
        Sub sub = new Sub();

        if (s instanceof Super) {
            System.out.println("true1");
        }
        if (s instanceof Sub) {
            System.out.println("true2");
        }
        if (sub instanceof Super) {
            System.out.println("true3");
        }
        if (sub instanceof Sub)
            System.out.println("true4");
    }
}