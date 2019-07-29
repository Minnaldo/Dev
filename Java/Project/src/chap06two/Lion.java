package chap06two;

public class Lion extends Animal {
    // Animal의 whoami또한 상속을 통해 포함하고 있음
    @Override
    public void walk() {
        System.out.println("사자가 걸어요");
    }

    public void roar(){
        System.out.println("사자가 으르렁 거린다");
    }
}
