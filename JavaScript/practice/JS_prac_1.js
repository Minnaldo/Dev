console.log("Hello Console");   // 콘솔로그 창에 메시지를 출력한다. 콘솔로그 창은 웹브라우저에서 개발자 도구를 열면 된다(f12와 같은), 콤마로 구분하여 활용 가능

// var name = prompt("프롬프트 명령어 테스트"); // 괄호안에 들어있는 메시지를 사용자에게 보여주고, 문자열을 입력받는 명령, 입력받아 변수에 저장 가능 ==> name변수에 사용자의 입력을 받는다

console.log(name);

// alert("Hello world");

console.log(name, typeof (name)); // 명령어, 괄호안 변수의 타입을 알려주는 명령어

var str = "123456 string number : ";    // "string number : 123456" <= NaN 에러
var integer = parseInt(str);    // 괄호안의 int형이 아닌 변수를 int형으로 변경, 문자열의 앞에서부터 Number를 인식함
console.log(integer);

console.log(parseFloat(integer + 0.1234));   // parseFloat <= 실수형으로 변환

// 문자열은 따옴표, 큰따옴표로 둘러싸면 된다. 섞어도 가능, 내부에서 따옴표를 나타내려면 \를 이용
// 문자열의 병합은 '+' 기호를 이용

var empty_obj = {};     // 명시적 object 생성
var man = { name: "홍길동", age: 20, height: 180 };    // 암시적 object 생성, 속성 : 속성 값

man.age = 30; // 오브젝트 속성 접근 후 수정
man[name] = "가나다"; // 오브젝트 속성 접근 후 수정

/*  undefined와 null
    undefined : 시스템에서 어떤 변수나 속성이 정의되지 않은 경우를 표현하기 위해 사용
                선언만 하고 초기화가 되지 않는 변수의 타입이나 값.
                객체의 정의되지 않은 속성의 타입이나 값
    null : 개발자가 명시적으로 아무것도 없는 비어있는 상태를 나타낼 때 사용
*/

var a;  // undefined
console.log(a++);   // a를 먼저 출력후, a값을 1증가
console.log(a);

a=1;
console.log(++a);   // a값을 1 증가후, a를 출력
console.log(a);

// Math관련 명령어
Math.pow(A,b); // A의 b승
Math.sqrt(A); // A의 제곱근
Math.random(); // 0~1 사이의 임의의 난수 발생