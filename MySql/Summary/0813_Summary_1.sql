use scott;

SELECT 
    ename, empno, sal
FROM
    emp;

-- 각 데이터(select에서 요구하는 항목)에 대해서 where절 조건을 비교한다
-- and가 or보다 연산순위가 높다
SELECT 
    ename, empno, sal, sal * 12, comm, IFNULL(comm, 0)
FROM
    emp
WHERE
    sal > 2000 AND comm IS NULL
        AND empno > 7700
        OR deptno = 30;

-- 데이터베이스안의 테이블이름의 구조를 본다.	
desc emp;

-- date는 날짜만 datetime은 시간까지 들어가 있다.

-- 데이터 건 수 만큼 실행되는 함수 ==> 단일 행 함수
-- ======================================================


-- 단일 행 함수 ==> 나오는 row의 숫자를 변환하지 않음

-- 다중 행 함수 (집계함수)	==> 결과 row의 숫자가 바뀜, 집계함수를 쓰면 출력 데이터가 한건으로 바뀜
-- 집계함수를 쓰면 단일 행 함수를 쓰지 않는 것이 좋으며, 항상 검증작업이 필요하다
-- sum, avg, count, max, min 등이 존재
SELECT 
    sal,SUM(sal), COUNT(sal), MAX(sal), MIN(sal)	-- 매트릭스가 깨짐, 그러나 MySql은 에러를 띄우지 않음
FROM
    emp;


SELECT 
    comm, MAX(comm), MIN(comm), COUNT(comm),	-- null 은 카운팅하지 않는다
    avg(ifnull(comm,0)), sum(somm),sum(comm)/count(comm)	-- 집계함수 안에 단일행 함수를 쓸 수 있다, 반대도 가능하다
												-- 집계함수 안에 집계함수는 불가능 하다
FROM
    emp;
    
    
-- Group by =============================================================alter
-- 10번 부서 사람들의 금액 합
select sum(sal)
from emp
where deptno = 10;

-- 레코드 조회
select distinct deptno
from emp;

select sum(sal)
from emp
where deptno=10;

select sum(sal)
from emp
where deptno=20;

select sum(sal)
from emp
where deptno=30;

-- 위 세개의 쿼리를 합치고 싶다면?
-- 소그룹으로 묶는다. 소그룹 만큼의 결과값이 나온다
-- group by (그룹화 기준점)
-- 부서별 급여 합, 평균, 최대, 최소
SELECT 
    deptno, SUM(sal), AVG(sal), MAX(sal), MIN(sal)
FROM
    emp
GROUP BY deptno;-- deptno로 소그룹화 -- 어떤 기준으로 소그룹을 만들꺼냐

-- 업무별 급여 합, 평균, 최대, 최소
-- as는 생략도 가능하나, 생략하지 않는 것이 좋다 : 에러 발생 가능성이 높다
select job, sum(sal) as sum,avg(sal),max(sal),min(sal)
from emp
where sal >= 1500
group by job
order by sum desc;	-- 순서대로 읽히므로 위의 별명을 정렬 기준으로 적어도 된다


-- 동일 입사월 사원의 평균 급여
select month (hiredate) as 'year', avg(sal)
from emp
group by month (hiredate) # group by extract(month from hiredate)
order by month(hiredate);

-- 부서별 급여합,평균 급여합이 3천 이상인부서만
SELECT 
    deptno, SUM(sal) AS 합, AVG(sal)
FROM
    emp
WHERE
    1
GROUP BY deptno
HAVING SUM(sal) >= 10000
ORDER BY deptno;

-- 업무별 급여 평균이 3000 이상인 업무만 출력
select job, sum(sal), avg(sal)
from emp
group by job
having avg(sal) >= 3000
order by avg(sal) desc;

SELECT 
    job, deptno, SUM(sal), AVG(sal)
FROM
    emp
WHERE
    1
GROUP BY job , deptno	-- job으로 grouping 이후 depno로 grouping
ORDER BY JOB;


SELECT 
    job, SUM(sal), AVG(sal)
FROM
    emp
WHERE
    1
    group by job with rollup;	-- with rollup을 할 경우 전체의 합과 평균을 한줄 더 추가해줌
    
-- 부서별 업무별 급여합 구하기
select deptno, job, sum(sal)
from emp
group by job, deptno;

-- 1열 부서, 1행 업무가 나오고 급여합을 구하기
select ifnull(deptno, '합계')
	,sum(case when job='president'then sal end) ifnull(president,0) as president
    ,sum(case when job='clerk'then sal end) as clerk
    ,sum(case when job='manager'then sal end) as manager
    ,sum(case when job='analyst'then sal end) as analyst
    ,sum(case when job='salesman'then sal end) as salesman    
from emp
group by deptno with rollup;
