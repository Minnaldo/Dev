// 함수의 정의
function name(param1, param2) {
    return returnValue;
}

// 논리연산자 &&, ||, !

// 문자열 길이 알아내기
var strLength = str.length; // ==> length 뒤에 괄호를 안붙있는 것 주의

// 문자열 붙이기 .concat() or '+' 사용
str1.concat(str2); // str1과 str2를 붙인다
str1 + str2;  // 윗라인과 같은 결과

// 특정 위치의 문자열 알아내기 .charAt() 함수 이용
str.charAt(0); // 첫문자, 인덱스가 0부터 시작
str[0]; // 첫문자

// 부분문자열 구하기, .substring(pos1, pos2) : pos1~pos2의 문자열 반환
//                    substr(pos,length) : pos에서 length길이 만큼 부분 문자열 반환, legnth 생략시 마지막까지
// 문자열 검색하기, indexOf(str); , lastIndexOf(str);

// 배열 만들기
var arr=[]; //빈 배열
var arr=[1,2,3,4,5]; // 초기화 된 배열
var mixed_arr = [1, true, 3.14,"string",{name:"object"}, [1,2,3]]; // 어떤 타입이든 저장 가능

//배열의 길이 .length속성 이용
// 배열의 엘리먼트 접근, c와 같다.

//배열의 엘리먼트 추가/삭제
arr.push(element); // 배열의 뒤에 엘리먼트 추가
arr.pop(); // 배열의 뒤에서 엘리먼트 삭제하고 리턴
arr.shift(); // 배열의 앞에서 엘리먼트 삭제하고 리턴
arr.unshift(element); // 배열의 앞에 엘리먼트 추가

arr1.concat(arr2); // arr1 배열과 arr2배열을 붙인다.
arr.indexOf(element); // arr에서 element의 첫 인덱스 반환
arr.lastIndexOf(element); // arr에서 element가 있는 마지막 위치 검색

//문자열 split 함수, 문자열을 구분자로 나눠서 각각을 담은 배열을 반환
var str = "1,2,3,4,5";
arr = str.split(",");   // arr = ["1","2","3","4","5"]

// for in 문 : 객체의 각 엘리먼트에 접근할 수 있는 반복문, 객체의 속성들을 출력하는 동일한 코드.
// obj객체를 돌며
for(var propertyName in obj){
    console.log("\t", propertyName, ": ", obj[propertyName]);
}

// 변수의 shadowing
/** 함수 안에서 밖에서도 선언되었던 같은 이름의 변수를 사용하는 경우
 *  - 함수 밖의 변수는 잠시 가려짐 (shadowing)
 *  - 함수 안에서는 해당 함수에서의 변수를 사용 (함수 밖 변수의 값은 변하지 않음)
 *  - 함수에서 빠져나오면 다시 해당 변수(함수 밖의 변수)에 접근할 수 있음
 *
 *  함수 안에서만 값이 유지되어야 하는 경우
 *  - 함수 안에서 var 키워드를 사용해 선언하고 사용
 *
 *  여러 함수에서 값이 유지되면서 아용되는 변수의 경우
 *  - 함수를 포괄하는 곳에서 선언하고 사용
 */