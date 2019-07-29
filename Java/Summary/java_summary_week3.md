# Java Summary Week 3

## java.lang API
- java.lang : java언어의 가장 기본적인 클래스들을 모아놓은 패키지이다.

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
|equals(String a)||문자열 비교||
|equalsIgnoreCase(String s)||대소문자 구별 없이 비교||
|compareTo(String s)||알파벳의 순서 비교||

#### StringBuilder
문자열을 편집하여 사용하고자 할 경우에 사용하는 클래스이다