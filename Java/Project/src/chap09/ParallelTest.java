package chap09;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

// 자바의 병렬 처리
// parallelStream을 이용해 병럴처리를 한다.
// Stream<type> parallelStream = listi.parallelStream();
// parallelStream.forEach(ParallelTest::print);

public class ParallelTest {
    public static void main(String[] args) {
        List<String> list = Arrays.asList("일길동", "이길동", "삼길동", "사길동", "오길동", "육길동", "칠길동", "팔길동", "구길동", "십길동", "십일길동", "십이길동", "십삼길동", "십사길동", "십오길동");
        // 일반 스트림은 메인 스레드가 처리한다
        Stream<String> stream = list.stream();
        stream.forEach(ParallelTest::print);

        // parallelStream은 다중 스레드가 처리한다.
        // 스레드 풀에서 스레드를 가져다 쓴다.
        // 병렬처리
        Stream<String> parallel = list.parallelStream();
        parallel.forEach(ParallelTest::print);

        List<Integer> listi = Arrays.asList(100, 200, 300, 400, 500, 600, 700, 800, 900);
        // stream이 훨씬 빠르다고 함
//        Stream<Integer> stream2 = listi.parallelStream();
//        stream2.forEach(ParallelTest::print); // static 메소드를 이용한다

        // Consumer Interface 안의 accept메소드를 람다식으로 사용
        stream.forEach(s ->
                System.out.println(s));
        parallel.forEach(name -> System.out.println(name + " : " + Thread.currentThread().getName()));
    }

    public static void print(int str) {
        System.out.println(str);
    }

    public static void print(String str) {
        System.out.println(str + " : " + Thread.currentThread().getName());
    }
}
