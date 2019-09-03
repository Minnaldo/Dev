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
// $ 는 jQuery를 줄인 것
$(init);
```

jQuery Selector
```javascript
```

## AJAX (Asynchronous Javascript and XML)

HTML 페이지는 부분만 바꿀 수 없다 ==> jsp에서 새로운 페이지를 만들어 보내주어야 한다
==> 페이지가 refresh되어야 한다 (자원 소모 증가)

자바스크립트를 이용한 개선 가능, 자바스크립트가 직접 서버와 통신을 한다
자바스크립트가 갖고있는 통신모듈을 이용해 통신을 한다

최근엔, XML대신 JSon을 통해 통신을 한다

### XMLHttpRequest
- 자바스크립트가 Ajax를 사용할 때 사용하는 객체
- XHR

> 화면은 그대로 두고, javascript가 `XML` 을 이용해 통신을 한다

동기, 비동기 모두 사용 가능
대부분 비동기로 사용

```javascript
// XMLHttpRequest객체 생성
var request = new XMLHttpRequest();

request.open('GET',"url",false);    // false : 동기 / true : 비동기

// Ajax 수행
request.send();

// 출력
document.body.innerHTML = request.responseText;
```

|readyState 속성|설명|
|:---:|---|
|0|Request 객체를 만들었지만 open() 메서드를 사용해 초기화 하지 않았음|
|1|Request 객체를 만들고 초기화 했지만 send() 메서드가 사용되지 않음|
|2|send() 메서드를 사용했지만 아직 데이터를 받지 못함|
|3|데이터의 일부만을 받음|
|4|모든 데이터를 받음|

```js
xhr = new XMLHttpRequest();
			// xhr 객체의 상태가 바뀌면 (callback) 함수 실행
			xhr.onreadystatechange = function () {
				// 데이터를 모두 받았고, 서버 상태가 200번 (ok 상태)일 때
				if (xhr.readyState == 4 && xhr.status == 200) {
					var resDoc = xhr.responseXML;	// xml을 받아온다
					var res = resDoc.getElementsByTagName('result')[0].getAttribute('value');
					document.getElementById('result').value = res;
				}
			}
```

### JSon
Json의 데이터 표현 방식
|객체|배열|
|---|---|
|{}|[]|