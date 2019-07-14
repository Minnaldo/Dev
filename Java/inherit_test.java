import java.io.*;

/**
 *  * 상속과 업 캐스팅, 다운 캐스팅을 테스트
 */

class inherit_test{

    static class animal{
        animal(){
            System.out.println("animal class");
        }

        private void print(){
            System.out.println("Parent Class");
        }
    }

    static class dog extends animal{
        dog(){
            System.out.println("dog class");
        }

        private void print(){
            System.out.println("Child Class");
        }
    }

    public static void main(String[] args) {
        animal dog = new dog(); // * UP CASTING ( 자식 -> 부모 )
        // dog dog = new animal(); // * DOWN CASTING ( 부모 -> 자식 ), 에러 발생
        dog dog2 = new dog();
        dog2.print();
        /** * 업 캐스팅 시, 객체 타입은 부모클래스 타입이기 때문에, 부모 클래스의 메소드만 호출이 가능하다 */
        // dog.printC();
        /** 오버라이딩 된 함수를 호출 할 때, 자식 클래스의 메소드가 아닌 부모 클래스의 메소드를 호출하는 것을 보면, 부모클래스 타입으로 변경됨을 알 수 있다. */
        dog.print();
    }
}