// JS Closure(클로저)

/** JS Closure(클로저)
 *  함수, 함수가 선언될 때의 enviroment로 구성
 *  함수가 정의 될 때의 enviroment가 함께 closure로 결합되면서, 다양한 활용이 가능
 */

 //closure Example
 function makeConuterFunction(initVal){
     var count = initVal;
     function Increase(){
         count++;   // 2줄 위에 선언된 count
         console.log(count);
     }
     return Increase;
 }

 var counter1 = makeConuterFunction(0); // counter1의 클로저 : 함수 - function Increase(){}, 환경 var count = 0;
 var counter2 = makeConuterFunction(10); // counter1의 클로저 : 함수 - function Increase(){}, 환경 var count = 10;


 // 배열 내 원소들의 평균값을 구하는 함수
 function average(array){
    var tmp = 0;  // 변수 선언시 초기화를 하지 않으면 자료형을 못찾아 NaN이 발생
    for(var i=0; i<array.length; i++)
        {
            tmp += parseFloat(array[i]);
        }
    var len = parseFloat(array.length);

  //   console.log(len);
    console.log(tmp/len);
}

console.log(average([1,2,3]));