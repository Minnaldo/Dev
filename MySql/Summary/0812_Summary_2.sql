desc emp;

alter table emp add(hobby char(5));

select * from emp;

-- 문자형 함수
-- 대/소문자 변겅 함수
select *from emp;
select ename, lower(ename), upper(ename), reverse(ename), lcase(ename), ucase(ename)
from emp
where lower(ename) = 'smith';

select concat('SQL', concat(' plus'+'!!')), concat('SQL',' plus','!!')
from dual;

-- 3번째부터 4개를 자른다
select substr('i llove you',3,4);

select substr(ename,1,3)
from emp
where substr(ename,1,1)='s';	-- s로 시작하는 문자만 찾는다

-- dual은 가상의 테이블 하나의 결과만 출력할 수 있게 해준다.
select instr('i love you','you') from dual;	-- you가 몇번째 자리에 들어가는지를 반환, 앞 문자열에서 뒷 문자열이 시작되는(중복되어도 첫번째, 없으면 0) 인덱스를 반환한다

-- admin@naver.com
select substr('admin@naver.com',1,instr('admin@naver.com', '@')-1) from dual;

-- 함수 안에 함수 사용이 가능함
select substr('admin@naver.com', instr('admin@navercom','@')+1) from dual;

-- 자릿수 채우기
select lpad('홍길동','10','*'), rpad('홍길동','10','*') from dual;

select length(ltrim(' i love you ')), length(rtrim(' i love you ')), length(trim(' i love you ')) from dual;

-- 결과 : 6, 한글은 3자리로 한다 --> 캐릭터셋을 바꾸기 전까지는 한글은 한글자당 3byte
select length('공유'), length('abc') from dual;

-- 문자 교체
select replace('i love you','you','us');


-- 숫자 함수
-- 절댓값
select abs(2), abs(-2) from dual;

-- 음수/양수 확인	==> 양수 1, 음수 -1, 0 은 0
select sign(2), sign(-2), sign(0);

-- 반올림, 기본 첫번째 자리에서, ',(comma)를 이용해 몇번째 자리에서 반올림을 할껀지 설정 가능
select round(123.12346546, 3) from dual;

-- 버림
select truncate(123.12341) from dual;

-- 올림 (ceil), 버림 (floor) truncate는 자릿수를 인자로 전달 가능
select ceil(123.1234567), floor(123.1231241) from dual;

-- 나머지 연산, MySql에서는 0으로 나누면 null을 반환
select mod(5,3), mod(60,0) from dual;

-- 지수 승
select power(3,2);


-- 날짜 함수
-- 현재 날짜
select now(), sysdate(), curdate(), current_time(), curtime() from dual;

-- 문자열에서 년도만 , 날짜만 뽑기
select year('20190812'), month('20190812');

select hiredate, year(hiredate) from emp;

-- 오늘부터 100일 후의 날짜를 출력
select date_add(now(), interval 100 day);

-- 오늘이 몇번째 주인지 출력
select week(now());

select (to_days(now())) - to_days('19880812');

select extract(year from now()),extract(month from now()),extract(day from now());

select date_format(now(),'%Y:%M:%p');

-- 변환함수
select format(123456781212319.123,'#,###,###.###');

-- 타입 캐스팅
select cast(now() as char);

-- 일반 함수
case 표현식 when 비교1 then 결과1 
		when 비교2 then 결과2
        else 기본값
        end;
    
-- case when의 경우 동등비교만 한다
SELECT 
    CASE job
        WHEN 'manager' THEN '매니저 시군요'
        WHEN 'clerk' THEN 'cleck 이군요'
        ELSE '?????????'
    END as AAA
FROM
    emp;

SELECT 
    sal,
    CASE
        WHEN 3000 > sal THEN '많이 버네요'
        WHEN 2000 > sal THEN '보통이네요'
        ELSE '조금버네요'
    END AS chk
FROM
    emp;
    
# '20100812-3235423'

SELECT 
    CASE SUBSTR('100812-3235423', 8, 1)
        WHEN 1 THEN '남자'
        WHEN 3 THEN '남자'
        ELSE '여자'
    END AS gender;
