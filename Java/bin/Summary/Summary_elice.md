### JAVA 정리 - 실수형
- flaot형 변수에 실수 저장 시 끝에 'F'를 붙여준다.
```java
    float fNum = 3.14F;
```

### JAVA 정리 - 논리형
- 선언
```java
    boolean isBool = true;
```

### JAVA 정리 - 자료형 추론
- var 변수를 사용 할 수 있는데, 컴파일러가 컴파일시 자동으로 자료형을 추론한다.
```java
    var i = 5;  // int type
    var j = "abcd";  // string type
```
**단 JAVA 10 부터 적용된다**

### 상수 사용하기
final 키워드를 통해 상수를 선언 할 수 있다.
```java
    final int max = 100;

    final int min;
    min = 0;

    // 위의 두가지 형태로 사용 가능
```

### JAVA 명시적/묵시적 형 변환
#### 명시적
```java
    float f = 3.14F;
    int i = (int)f; // i = 3
```
#### 묵시적
```java
    float f = 2.0F;
    int i = f;  // i = 2
```

### JAVA bit shift
```java
    int num = 0B00000101;   // 2진수 5

    System.out.println(num << 2);   // 왼쪽 으로 2비트 이동 00010100 (20)
    System.out.println(num >> 2);   // 오른쪽으로 2비트 이동 00000001 (1)
```