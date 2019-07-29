package chap06;

public class MyMain {
    public static void main(String[] args) {
        MySub m = new MySub();
        m.show();

        MyInter mi = new MySub();
        MyInter2 mi2 = new MySub();

        if(mi instanceof MyInter){
            System.out.println("mi is MyInter");
        }else{
            System.out.println("mi is not MyInter");
        }

        if(mi instanceof MyInter2){
            System.out.println("mi is MyInter2");
        }else
        {
            System.out.println("mi is not MyInter2");
        }

        if(mi instanceof Object){
            System.out.println("mi is Object");
        }else
        {
            System.out.println("mi is not Object");
        }

        if(mi2 instanceof MyInter){
            System.out.println("mi is MyInter");
        }else
        {
            System.out.println("mi is not MyInter");
        }
    }
}
