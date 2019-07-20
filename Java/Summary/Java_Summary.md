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
