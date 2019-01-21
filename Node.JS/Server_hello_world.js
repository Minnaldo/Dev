/**
 *  * Node.JS 서버 만들기
 *  * 127.0.0.1:8000 에 접속하면 'Hello World'를 볼 수 있음
 */


 // require는 모듈을 로드하는 함수, http모듈을 로드해 http변수에 저장
var http = require('http'); // 'http'는 node.js 기본 내장 모듈

// http.createServer(app) 로 app과 http객체를 연결한다
var server = http.createServer(function (req/* 요청(request) 객체 */, res/* 응답(response) 객체 */){
    res.writeHead(200, {'Content-Type' : 'text/plain'});
    res.end('Hello World');
});

server.listen(8000);    // 서버가 8000포트를 listen, 서버를 실행하여 8000포트를 듣는다