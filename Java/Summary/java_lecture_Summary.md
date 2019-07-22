## 어노테이션
*어노테이션은 JAVA5에 추가된 기능이다*
- 어노테이션은 클래스나 메소드위에 붙습니다. @(at)기호로 이름이 시작합니다.
- 어노테이션을 클래스나 메타코드에 붙인 후, 클래스가 컴파일되거나 실행될 때 어노테이션의 유무나 어노테이션에 설정된 값을 통하여 클래스가 좀 더 다르게 실행되게 할 수 있다.<br>이런 이유로 어노테이션을 일종의 설정파일처럼 설명하는 경우도 있다.
- 어노테이션은 자바가 기본으로 제공해주는 것도 있고, 사용자가 직접 만들 수도 있다.
    - 사용자가 직접 작성하는 어노테이션을 Custom 어노테이션이라고 말한다.
- 커스텀 어노테이션을 이용하는 방법
    1. 어노테이션을 정의한다.
    1. 어노테이션을 클래스에서 사용한다. ( 타겟에 적용 )
    1. 어노테이션을 이용하여 실행
- 패키지 익스플로러에서 [new - Annotation]을 이용하여 Count100이라는 어노테이션 생성
     - Count100 어노테이션을 JVM실행시에 감지할 수 있도록 하려면 @Retention(RetentionPolicy.RUNTIME)를 붙여줘야 한다.

```java
import java.lang.annoation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retetion(RetentionPolicy.RUNTIME)
public @interface Count100{

}
```

- "hello"를 출력하는 hello()메소드를 가지는 MyHello라는 클래스를 작성
    - hello메소드 위에 @Count100 어노테이션을 붙힌다.

```java
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
public @interface Count100{

}
```

- MyHello클래스를 이용하는 MyHelloExam 클래스를 작성
    - MyHello의 hello 메소드가 @Count100어노테이션이 설정되어 있을 경우, hello()메소드를 100번 호출하도록 한다.

```java
import java.lang.reflect.Method;

public class MyHelloExam{
    public static void main(String[] args){
        Myhello hello = new MyHello();

        try{
            Method method = hello.getClass().getDeclaredMethod("hello");

            if(method.isAnnotationPresent(Count100.class)){
                for(int i =0; i<100; i++){
                    hello.hello();
                }
            }else{
                hello.hello();
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}