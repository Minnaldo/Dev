SELECT 
    EMPNO, ENAME, SAL, SAL * 12 AS 연봉, deptno
FROM
    emp
WHERE
    sal BETWEEN 2000 AND 3000
    and deptno in (20 ,30)
ORDER BY sal desc;

select ename, empno, sal, '재직'
from emp;

-- 이름(급여), 사번
select concat(ename,'(',sal,')')as name,empno
from emp;

-- 이름의 급여는 얼마 입니다. 형식으로 출력해보기
select concat(ename,'의 급여는 ',sal,' 입니다.') as 'name and sal' 
from emp
order by ename;

desc emp;

-- 사원의 총 연봉을 구하세요 (sal * 12 + comm)
-- not의 표현 방식, !=, <>, ^=
-- null을 체크하려면? is null 또는 is not null 을 이용해 null을 찾는다
-- null값을 같는 컬럼은 사칙연산을 할경우 null이 된다
-- ifnull(comm,0) ==> comm이 null이면 0으로 바꾼다 
select ename,sal*12 + ifnull(comm,0)
 from emp;
 -- where comm is not null;
 
 -- 중복 제거 : distinct
select distinct deptno, ename
from emp;

select ename, deptno, job
from emp
where not sal =2000;

select ename, deptno, job
from emp
where sal between 1000 and 3000;

select ename, deptno, job
from emp
where deptno in (10,20);

select ename, deptno, job
from emp
where ename in ('smith','king');

-- 다중 리스트
-- 부서번호, 업무가 10번 'manager' 이거나 20번 cleck
select ename, deptno, job
from emp
where (deptno, job) in ((10,'manager'),(20,'clerk'));

-- ename이 s로 시작하는 사람 찾기, like 키워드와 % 이용
select ename
from emp
where ename like 's%';

-- ename이 s로 끝나는 사람 찾기, like와 % 이용
select ename
from emp
where ename like '%s';

-- under_bar('_') 는 자릿수까지 따져야함

-- s로 끝나지 않는 사람 찾기 ==> not like 이용
select ename
from emp
where ename not like '%s';

-- and와 or도 연산자 우선순위가 있다. and > or


select ename, sal, deptno
from emp
order by SAL desc;

