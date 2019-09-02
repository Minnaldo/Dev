# Java Script Summary Week 1

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