# JAVA Chapter 2 Summary

## 1. 객체 지향이란?
SW의 모든 구성원이 객체(Object)로 구성되며, 객체들의 관계성으로 프로그램이 작동되는 것이다. 그렇기 때문에 객체를 만들기 위해 클래스를 만들기 위해 클래스를 이용하여 객체가 가져야할 구성요소를 설계하게 된다.

### 1-1. OOP (Obejct Orientation Programming)
|요소|Design|Object|
|:---|:---:|:---:|
|Abstraction (추상화)|class (Blueprint of the object)|object|
|Encapsulation (캡슐화)|
|Inheritance (상속)|
|Polymorphism (다형성)|

> 클래스는 시간이 지나도 변하지 않지만, 객체는 시간이 지나면 변할 수 있다.

## 2. class 구성과 object의 사용법
- 클래스의 구조
```java
[modifiers] class class_identifier;

[modifier] class_identifier(...){...}

[modifiers] return_type method_identifier ([arguments]){
            method_code_block
            ...
    }
```

```java
public class Member{    // 클래스 선언부
    String name;    // 데이터를 저장하기 위해 변수선언
    int age;
    String email;

    public void memberInfo(){   // 필요한 기능 정의
        String info = name + "\t|"+age+"\t|"+email;
        System.out.println(info);
    }
}
```
---

1. 객체 변수 선언
```java
ClassName ver;
```

2. 객체의 생성
```java
ver = new ClassName();
```

3. 객체의 사용
- 객체에는 멤버변수만 있다.
```java
ver.variable = value;
ver.method();
```

객체 변수의 선언과 객체 생성을 동시에
```java
ClassName ver = new ClassName();
```

**자바에서 package와 import외에 메소드 클래스 밖에 작성되는 것은 없다**

<br>

**하나의 ```.java```파일에는 하나의 public class 만 작성 가능하며, public 접근지정자는 자바파일의 파일명과 같아야 한다**

```java
// 클래스와 .java 파일명의 관계
// ExName.java 이어야 컴파일이 됨
public class ExName{

}

class Hello{

}
```
- 자바 파일명이 ExName.java가 아니면 컴파일이 되지 않으며, 컴파일이 완료되면 각 클래스 이름의 .class파일이 생성된다.
<p><img src="img/outer_class.png"></p>

```java
// 클래스와 이너클래스 예
// 이너클래스 작성시
public class ExName{
    class Hello{}
}
```
- 위 예제를 컴파일 하면 ExName.class와 ExName$Hello.class 파일이 생성된다.

<p><img src="img/inner_class.png"></p>
---
#### 자바의 import
- 컴파일이 완료되면 import 구문은 없어진다.
- ```java.util.*``` 패키지의 ArrayList사용시, 컴파일이 완료되면 ArrayList는 java.util.ArrayList로 변하게 된다
---

**static 키워드가 붙는 메소드에서는 일반 메소드를 호출 할 수 없다.**