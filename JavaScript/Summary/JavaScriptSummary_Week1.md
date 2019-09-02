# Java Script Summary Week 1

자바스크립트는 변수에 값을 할당할때 변수의 타입이 결정된다

세미콜론의 생략이 가능

js : function base lang

global or function

var는 영역체크를 위해
var를 안쓰면 전역으로 선언됨

```javascript
a();
function a(){
    console.log("a()");
}

var b = function(){
    console.log("b()");
}

a.c = function(){
    console.log("c()");
}

b();
a.c();
console.log(b);

// 출력
// a()
// b()
// c()
// function(){ console.log("b()"); }
```