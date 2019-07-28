public class overloading {

    public static class father {
        String str = "Father";

        public void print() {
            System.out.println("Father");
        }
    }

    public static class child extends father {
        String str = "Child";

        public int getInch(){
            retrun 1;
        }

        child() {

        }

        public void print() {
            System.out.println("Child");
        }
    }


    public static void main(String[] args) {
        father c = new child();

        c.print();
        System.out.println(c.str);

//        System.out.println(c);

//        if (c instanceof child) {
//            System.out.println("C의 타입은 Father 가 아닙니다");
//        } else {
//            System.out.println("C의 타입은 Father입니다");
//        }
    }
}
