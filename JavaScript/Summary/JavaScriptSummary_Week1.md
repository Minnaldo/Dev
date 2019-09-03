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

### 일급함수
```javascript
// 일급함수 실행 1
test(function(){console.log('this is fist function')});
// 일급함수 실행 2
function
```


### queryselector
```javascript
// 클래스 abc의 색상을 빨간색으로 바꾼다
document.querySelector('.abc').style.color = 'red';
```

## jQuery

```javascript
var init=function(){
    alert("1111");
}
// 아래는 모두 init을 window.onload 시점에 실행하는 코드이다.
jQuery(document).ready(init);
jQuery(init);
$(init);
```