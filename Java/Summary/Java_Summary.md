# Java Basic Summary

## Java의 자료형
-  자바의 자료형은 기본 자료형(Primitive Datatype)과 사용자정의 자료형(User Defined Datatype)이 있다.

### 기본 자료형

|구분|자료형|크기 (처리범위)|
|:----:|:----:|:----:|
|논리형|`boolean`|1 bit(true or false)|
|문자형|`char`|2 Byte (\u0000 ~ \uFFFF)|
||`byte`| 1 Byte (-2^7 ~ 2^7 - 1)|
|정수형|`short`|2 Byte (-2^15 ~ 2^15 -1)|
||`int`|4 Byte (-2^31 ~ 2^31 -1)|
||`long`|8 Byte (-2^63 ~ 2^63 -1)|
|실수형|`float`| 4 Byte |
||`double`|8 Byte|

- 기본 자료형으로 선언된 변수에는 실제 값이 저장된다.
- pass by value / call by value (자바에서는 기본형은 모두 값으로만 불러온다)

### 사용자 정의 자료형 (Reference DataType; 참조 자료형)
- 클래스, 인터페이스, 배열이 있다.
- 참조 자료형으로 선언된 변수에는 객체(Instance)에 대한 **주소값**이 저장된다
- pass by reference / call by reference (참조 자료형은 모두 주소값을 전달하고, 주소값으로 요청한다)
- 클래스
    * 클래스로부터 생성된 객체(인스턴스)의 시작 주소값을 가진다.
- 배열
    * 자바에서는 배열을 클래스로 취급, 생성된 배열의 시작 주소값을 가진다
- 인터페이스
    * 인터페이스를 구현한 클래스의 인스턴스 시작 주소값을 가진다.

### 메모리가 부족할 때
- stack 영역이 부족하면 -> Stack Over Flow
- heap 영역이 부족하면 -> Out of Memory

### 클래스에서
클래스의 ```.```은 접근지정자

> java.lang 패키지는 자동적으로 import가 되어 있다.

String을 +를 사용하여 문자열을 편집하게 되면 성능에 문제가 될 수 있다. 문자열의 편집이 많이 필요할 경우는 처음부터 StringBuilder를 생성하여 문자열을 편집하는 것이 좋다.

- StringBuilder

문자열을 편집하여 사용하고자 할 경우에 사용하는 클래스다.
    - String의 수정을 편리하게 한다.
    - StringBuffer 클래스를 개선하여 성능을 향상한 클래스이다.
    - StringBuffer 클래스와 메서드가 비슷하다.

- StringBuilder 클래스의 제공 메서드


## 클래스
> 관련있는 변수와 함수를 묶어만든 사용자 자료형
부모가 기본생성자가 있다면? 묵시적으로 기본 생성자를 호출함
부모가 기본생성자가 없다면( 부모 생성자에 변수가 들어있는 것 ) `꼭` 명시적으로 호출해줘야 함

메소드 내에서 변수 오버라이딩도 가능함
```java
class Child{
    int data = 20;
    public void print(){
        int data = 30;  // 변수 오버라이딩, 클래스의 변수(20) 과는 다름
    }
}
```

- getter & setter의 사용 이유
    - 데이터 무결성 보장 (data integrity)
    - 기능의 추가가 가능
    - 세분화된 접근 권한 제어


####생성자
- 리턴값이 없다. 문법적으로 반환유형이 없다.
- 생성자의 이름이 클래스의 이름과 같다.
- 생성자도 메소드이므로 오버로딩이 가능하다
    - 오버로딩? 이름은 같으나 리턴값 또는 매개변수 혹은 둘 모두가 다른 메소드


### 클래스 다이어그램
포함관계
사용관계

ObjectAid : UML 프로그램

### 싱글턴(Singleton) 패턴
- 디자인 패턴중 하나로 특정 클래스 객체를 단 하나만 만들 수 있도록 하는 구조
    - 클래스 private으로 선언하고, 클래스내에서 private static 클래스객체를 생성한다.
    - 앞서 생성한 변수에 getInstacne() ( a.k.a. Getter ) 메소드를 작성하여, 이를 통해 접근하도록 한다.
    - `new` 키워드 사용을 제한하는 형태, 생성자는 타클래스에 접근 불가능으로 만드는 방법이다.
```java
// Thread-safe한 방법의 싱글턴 패턴
// 프로그램 시작시 메모리에 적재되어 프로그램 종료시까지 하나의 객체만 이용한다.
class Class{
    // @param instance : the instance of Class
    private static Class instance = new Class();
    private Class(){}

    // getter
    public static Class getInstance(){
        return instance;
    }
}

// Thread-safe 하지 않은 방법
// 해결하기 위해 synchronized 키워드를 사용 한다
// synchronized : 스레드 동기화를 하는 키워드, 메소드 또는 변수에 lock을 걸어 스레드가 사용중에는 다른 스레드가 접근하지 못하게 하는 키워드
class Class_2{
    private static Class_2 instance; // 클래스의 인스턴스 변수
    private Class_2(){}

    // getter
    public static Class_2 getInstance(){
        if(instance == null)
            instance = new Class_2();
        return instance;
    }
}


// 타 클래스에서 사용시
class OtherClass{
    // 타 클래스에서 getInstance로 불러도, 초기에 생성된 하나의 객체만 반환됨
    // 메모리 효율성이 증대되고, 데이터의 일관성이 높아진다
    Class cls = Class.getInstance();
}
```

```java
public synchronized void method(Thread t){
    System.out.println(t.number+"번 스레드 입니다.");
}
```

자동 업캐스팅 됐을 때
변수는 선언자 (지시자; 변수/데이터 타입) 메소드는 객체(heap영역의 객체 타입을 쫓아감) (new ~~())를 따라간다

boolean 타입은 형변환이 되지 않는다.
객체변수는 자동초기화기 일어난다.

자식클래스가 생성될 때, 부모의 기본생성자(default constructor)가 호출되어진다. ( `super();`를 부른다)
default constructor의 존재
객체를 넣으면 - println에 객체를 설명하는 문자열이 출력( 오버라이딩 된, toString() ). 단, toString()이 오버라이딩이 되어있지 않다면, 객체의 해시값(주소값)이 출력되게 된다

#### Java iterator
자바의 컬렉션 프레임워크에서 컬렉션에 저장되어 있는 요소들을 읽어오는 방법을 표준화 하였는데, 그 중 하나가 Iterator이다.

Iterator 인터페이스의 구성
```java
public interface Iterator{
    boolean hasNext();  // 읽어올 요소가 남아있는지 확인하는 메소드 (return type : true/false)
    Object next();  //  메소드는 읽어올 요소가 남아있는지 확인하는 메소드 (return type : true/false)
    void remove();  // next로 읽어 온 요소를 삭제한다. next()를 호출한 다음에 remove()를 호출해야 한다.
}
```
Iterator는 인터페이스이다. 이는, 이를 구현하는 클래스에서 세부사항이 구현되는 것이다.

##### Iterator의 사용법
아래는 iterator를 이용해 리스트에 있는 모든값을 가져오는 예제이다.
```java
ArrayList<Integer> list = new ArrayList<Integer>();

for(Iterator<Integer> itr = list.iterator(); itr.hasNext();){
    list.get(itr.next());
}
```
---
```java
ArrayList<Integer> list = new ArrayList<Integer>();

Iterator<Integer> itr = list.iterator();
while(itr.hasNext()){
    list.get(itr.next());
}
```
iterator는 객체를 만들어 사용하기 때문에 느릴 수 밖에 없다. 그러므로 list의 size를 받아와서 사용하는 것이 좋다.
