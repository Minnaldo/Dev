
function solution(arr) {
    var answer = 0;
    var count = 0;
    for (var aa in arr) {
        answer = answer + arr[aa];
        count++;
        console.log(aa);
    }

    console.log(answer + "   " + count);
    answer = answer / count;

    return answer;
}

var arr = new Array(1, 2, 3, 4);

console.log(solution(arr));