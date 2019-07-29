# Java Summary Week 3

## java.lang API
- java.lang : java언어의 가장 기본적인 클래스들을 모아놓은 패키지이다.
- java.lang의 패키지들은 import하지 않아도 자동으로 import 해준다

- Object
    - java.lang.Object 클래스는 `최상위 클래스` : 모든 클래스에서 Object클래스를 자동으로 상속받는다.
    - 모든 클래스가 기본적으로 상속받아야 하기 때문에 **특별히 extends Object를 사용하지 않아도** 컴파일러에 의해 상속된다.
    - Object 클래스에는 모든 클래스의 공통적인 기능을 정의하고, 자주 사용되는 Method를 정의하여 필요 시 Overriding 해서 사용하도록 권장한다.

- 필요 시에 자주 Override 되는 메서드
    - toString():String - 객체를 대표하는 문자열을 return 하도록 구현한다.
    - hashCode():int - 객체를 구분하는 코드 값을 리턴하도록 구현한다.
    - equals(Object o):boolean - 객체의 내용을 비교 할 수 있도록 구현한다.

- String
    - 문자열을 간단히 저장할 수 있는 클래스로 `+` 연산이 가능하다
    - 유일하게 new를 사용하지 않고도 객체 생성이 가능
    - 어떤 type이든 String 객체에 +를 하게 되면 문자열로 변환되어 결과값이 모두 String으로 변환
    - String 값은 어떤 값으로든 벼녕되고, + 연산도 되어지지만 메모리 내부에서 String 객체의 값이 변경되지 않고, StringBuilder를 이용하여 변경처리하고, String으로 변환하여 출력한다.
    - 위 항목의 이유로 인해, 성능저하가 생길 수 있어서, 문자열 편집이 많이 필요한 경우는 StringBuilder를 생성하여 문자열을 편집하는 것이 좋다.

|Member|retur type|sbsc|etc.|
|:---|:---:|:---:|:---:|
|concat(String s)|String|s와 연결된 문자열을 리턴|'+'와 같다|
|repalce(char old, char new)|String|문자열에 있는 특정 문자(old)를 다른 문자(new)로 치환||
|substring(int start, int num)|String|문자열 중 일부를 추출|추출한 문자열을 리턴한다|
|charAt(int index)|char|특정위치(index)의 문자||
|length()|int|문자열의 길이를 리턴||
|toLowerCase()||모든 문자를 소문자로 변경|
|toUpperCase()||모든 문자를 대문자로 변경|
|trim()||문자열의 앞뒤 여백을 제거|문자열 중간의 공백을 제거하지는 않는다. 중간 공백을 제거하려면 repalceAll을 사용하는것이 좋다|
|endsWith(String s)||특정문자열로 끝나는지 여부를 리턴||
|startsWith(String s)||특정문자열로 시작하는지의 여부를 리턴||
|indexOf(String s)||특정문자가 처음 나타나는 위치|
|indexOf(char a)|||
|indexOf(String s, int offset)|||
|equals(String a)||문자열 비교||||
|equalsIgnoreCase(String s)||대소문자 구별 없이 비교||
|compareTo(String s)||알파벳의 순서 비교||
|insert(int offset, String s)||offset에 s를 삽입||
|reverse()||문자열 순서를 뒤집는다||
|setCharAt(int index, char ch)||index의 문자를 ch로 변경||
|setLength(int newLength)||문자열 길이를 새로 설정||

#### StringBuilder
문자열을 편집하여 사용하고자 할 경우에 사용하는 클래스이다

```java
StringBuilder str = new StringBuilder(initial value);
str.append("aaa");  // 문자열을 뒤에 추가
System.out.println(str);    // StringBuilder 출력

str.insert(int index, String newString);    // index에 newString 삽입
```


### Usage modifer
#### static
//TODO : summary about the static keyword
---
#### final<br>
    마지막을 의미하며, 클래스 앞에 정의하여 `더이상 상속 받을수 없음`을 메소드 앞에 정의하여 `Overriding 할 수 없음`을, 변수 앞에 정의하여 `값 변경할 수 없음`을 즉, 상수임을 의미한다.

    - class : 상속 받을 수 없음
    - method : Override 할 수 없음
    - variable : 상수로 정의

|위치|비고|
|:---:|:---:|
|class|상속 받을 수 없음
|method|Overriding 할 수 없음(메소드가 변형 될 수 업음)|
|variable(변수)|값을 변경할 수 없음(상수화; const in c), 상수는 선언과 동시에 초기화가 필요하다(초기화 하지 않으면 에러)|
---

#### abstract
일부 `구현되지 않은 메서드를 포함할 수 있는 클래스 정의`시 사용, `구현되지 않은 메서드 정의시에 사용`한다<br>
- abstract class 는 완전히 구현되지 않았기 때문에 객체를 생성하지 못한다.
- 상속을 통해 `상속 받은 클래스가 abstract 메서드를 모두 구현해야` 객체 생성이 가능하다.

```java
// 추상 메소드가 존재하는 클래스는 abstract키워드를 통해 추상클래스로 만들어주어야 한다.
// 추상 메소드는 추상메소드 뿐만 아니라 일반 메소드도 갖고 있을 수 있다.
public abstract class AbstracTest{
    public void play(){}
    public abstract void show();    // 구현부가 없는 메소드, 구현부가 없는 메소드는 abstract 키워드를 이용하여 추상 메소드를 만들어야함
    // 추상 메소드 : body가 없는 메소드
}
```
-  abstract클래스를 상속 받을 때는, `추상클래스의 메소드를 오버라이딩` 하거나, 똑같이 `서브클래스도 abstract키워드를 이용해 추상클래스로 변경`해주어야 한다.
추상 메소드가 필요한 이유

- abstract 클래스가 abstract클래스를 상속받을 수 있다.
- abstract 키워드를 통해 클래스를 선언하면, `abstract 메소드가 없어도 객체화 시 에러`가 발생한다
- 추상클래스의 일반 메소드(추상 메소드가 아닌)를 자식클래스에서 오버라이딩 하지 않아도 에러가 발생하지 않는다. 하지만, 객체에서 이를 호출하면, 추상 클래스의 메소드가 호출이 된다.

##### 추상클래스를 사용하는 이유
객체화는 못하지만 `상위타입으로 사용`한다.(generalization)
구현이 필요한 `메소드드의 구현을 강제`한다.<br>
공통된 필드와 메서드를 통일할 목적

---

#### Interface(인터페이스)
쉽게 말해 껍데기, 설계도 또는 명세<br>

모든 메소드가 추상 메소드이고, `일반 변수를 가질 수 없다`.
즉, interface를 구현(implements)한 클래스는 `모든 메소드를 강제적으로 구현`해야 한다.

`interface` 키워드를 사용한다

- 상수(final)와 추상메소드 만으로 구현한다
- 모든 메소드가 `추상 메소드`
- 변수를 갖지 못하고, `상수`만 가질 수 있다. ( 변수는 모두 `final` 키워드를 붙여야 함; 자동으로 컴파일러가 final을 붙인다)
- access modifier는 `public`만 가능함, 안쓰면 자동으로 작성되며, private, protected를 쓰면 에러가 발생
- 모든 메소드가 추상메소드 이므로, `abstract` 키워드를 작성하지 않아도, 자동으로 `abstract` 키워드가 붙는다.
- `new`키워드를 통한 객체화가 불가능하다

> interface를 implements를 해도 상속(extends)를 받을 수 있다. 이렇게 여러개를 상속받을 수 있는것이 인터페이스의 가장 큰 장점이다

---

#### 추상클래스(abstarct class)와 인터페이스(interface)
|\\|추상클래스|인터페이스|
|:---:|:---:|:---:|
|일반 변수|가능|불가능 (상수만 가능)|
|일반 메소드|가능|불가능|
|추상 메소드|0개 이상의 추상메소드 필요|필수|
|상속을 위한 키워드|extends|implements|
|상속 받을 때|상속받은 경우 추상메소드만 구현|상속받은경우 모든 메소드 구현(모든 메소드가 추상클래스)|
|인스턴스화|불가능|불가능|
|상속|다중상속 불가|다중상속 가능|
|객체화|불가능|불가능|
|자식클래스에서 업캐스팅|가능|가능|

---

#### Math
수학과 관련된 기본적인 함수들을 구현한 클래스
- 수학과 관련된 함수(메서드)를 제공
- final class ( final이 선언되어 있다. )
    - 클래스에 final 키워드를 선언해, 상속을 하지 못하게한다.
    - 클래스 상속을 막는 또하나의 방법은 모든 메서드와 변수를 private으로 선언하는 것이다.
- static 메서드를 제공<br>
    variation on max, min, abs<br>
    tringonometry : sin, cos, tan, asin, acos<br>
    trucation : cell, floor, round<br>
```java
inf i = Math.round(3.4f)    // 첫째자리에서 반올림
```


#### Wrapper class
Java의 기본형 데이터 타입을 객체화 시키는 클래스들이다.
> 데이터를 객체화 하기 위해 쓰는 클래스다. wrapper클래스는 primitive 데이터를 객체로 포장해준다.

- Java는 객체지향 언어이다.
- 객체가 아닌 것 : primitive data type(계산을 위한 type)
    - byte, short, int, long, foat, double, char, boolean
    - primitive type을 객체화 시켜주는 클래스
- primitive 객체화
    - Integer iobject = new Integer(300);

|기본 타입 (primitive type)|래퍼 클래스 (wrapper class)|
|:---:|:---:|
|byte|Byte|
|short|Short|
|int|Integer|
long|Long|
|float|Float|
|double|Double|
|char|Charater|
|boolean|Boolean|

Boxing(박싱) : primitive type -> wrapper class
UnBoxing(언박싱) : wrapper class -> primivite type
> 박싱/언박싱을 통해 primitive -> object / object->primitive의 변환이 편하게 바뀌었다.


