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

```java
String str = new String("Hello");
System.out.println(10+'a'+str); // 결과 : 107Hello
// char는 숫자이므로 10 + 97 (a의 아스키코드 값) + Hello가 되어
//107Hello가 된다
```

- String의 `==` 연산자는 주소값을 비교한다. 내용을 비교하고 싶다면 equals를 이용하여 비교한다

```java
//    str과 str2는 주소값이 다르다
String str = new String("Hello");   // 새로운 String 객체를 생성(새로운 주소 할당; 힙에 생김)
String str2 = new String("Hello");  // 새로운 String 객체를 생성(새로운 주소 할당; 힙에 생김)

// str3과 str4는 literal Pool에 문자열이 생성된다
// literal pool에 대한 설명은 밑에 있다
String str3 = "Hello";
String str4 = "Hello";

// String의 == 는 주소를 비교한다
// 내용을 비교하고 싶다면 .equals()를 사용한다
if (str == str2) {
    System.out.println("같다1");
}
if (str2 == str3) {
    System.out.println("같다2");
}
if (str3 == str4) {
    System.out.println("같다3");
}
if (str == str4) {
    System.out.println("같다4");
}
```
> 문자열의 합할 때 arraycopy를 이용하여 합친다
String클래스는 문자열을 다룬다.

```java
// 앞의 str과 뒤의 str의 주소는 다르다
// 문자의 배열이므로, 주소값이 달라진다
str = str + str2;
```
<span>String 연산과 주소</span>
```java
String str = "Hello";
StringBuilder sb = new StringBuilder(str);
sb.append("a");

System.out.println(sb.toString());  // 1
System.out.println(str+"a");    // 2
```
> 1번보다 2번이 훨씬 더 빠르다

#### literal pool
문자열 객체가 담기는 메모리 공간
JVM은 literal pool에 문자열이 없으면 생성하고, 있으면 그것을 가져다 쓴다.
literal pool에 존재하는 문자열(객체)은 삭제되지 않는다.

### Usage modifer

- final<br>
    마지막을 의미하며, 클래스 앞에 정의하여 `더이상 상속 받을수 없음`을 메소드 앞에 정의하여 `Overriding 할 수 없음`을, 변수 앞에 정의하여 `값 변경할 수 없음`을 즉, 상수임을 의미한다.

    - class : 상속 받을 수 없음
    - method : Override 할 수 없음
    - variable : 상수로 정의

|위치|비고|
|:---:|:---:|
|class|상속 받을 수 없음
|method|Overriding 할 수 없음(메소드가 변형 될 수 업음)|
|variable(변수)|값을 변경할 수 없음(상수화; const in c), 상수는 선언과 동시에 초기화가 필요하다(초기화 하지 않으면 에러)|

> 클래스를 정의할 땐, 반대쪽을 생각하면 좋다.

### 프로그램 명세서
자신이 만든 프로그램을 만든 이유와 사용한 언어 등 을 명시하며


> 업캐스팅 시 변수는 타입을, 메소드는 객체를 따라간다(new ~ 부분)


String 선언시 문자 인코딩 타입 지정
```java
byte [] bytes = data.getBytes("utf-8"); // utf-8을 이용해 인코딩
String str = new String(bytes, "ms949");    // ms949을 이용해 디코딩

str = new String(bytes, "utf-8");   // utf-8을 이용해 디코딩
```


## 인터페이스를 이용한 다중 상속
두개의 클래스로부터 상속을 받아야 할 상황이라면, 두 조상클래스 중에서 비중이 높은 쪽을 선택하고 다른 한쪽은 클래스 내부 멤버로 포함시키는 방식으로 처리하거나, 필요한 부분만 뽑아 인터페이스로 만든다음 구현하도록 한다

## 인터페이스간의 상속
- 인터페이스 내에는 상수 또는 동작부분을 구현하지 않은 추상 메서드들이 정의된다.
- 그러므로 인터페이스를 구현(Implements) 하겠다고 명시한 `일반 클래스에서 원하는 형태`로 꼭 구현해주어야 한다.
- 실제 구현하는 부분이 없는 인터페이스들 간의 상속에서는 `다중 상속`을 할 수 있다.


```java
// 인터페이스 간 상속 선언
[접근제한] interface [인터페이스 명] extends 부모인터페이스명1, 부모인터페이스명2, ..., 부모인터페이스명n{
    상수;
    추상메서드;
}
```
#### 추상메소드 구현
- 추상메소드는 해당 인터페이스가 다른 인터페이스로부터 상속을 받았지만, `Overriding 할 수 없다` ==> 인터페이스는 body({})를 가지는 일반 메서드를 포함할 수 없기 때문
- 그러므로 상속을 받은 자식 인터페이스를 구현(implements)하는 `일반 클래스에서 부모 인터페이스와 자식인터페이스의 추상 메서드들을 모두 Overriding(재정의)`해야 합니다

