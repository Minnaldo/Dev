#1
desc emp;

#2
SELECT 
    empno, ename, hiredate, sal
FROM
    emp
WHERE
    ename LIKE 'k%';
    
#3
select * 
from emp
where year(hiredate)=2000;

#4
select *
from emp
where comm is not null;

#5
select ename, job, sal
from emp
where deptno=30 and sal >= 1500;

#6
SELECT 
    empno
FROM
    emp
WHERE
    DEPTNO = 30
ORDER BY deptno;

#7
SELECT 
    *
FROM
    emp
ORDER BY sal DESC;

#8
SELECT 
    *
FROM
    emp
ORDER BY DEPTNO , sal DESC;

#9
SELECT 
    *
FROM
    emp
ORDER BY deptno DESC , ENAME , sal DESC;

#10	
SELECT 
    ename,
    sal,
    sal * IFNULL(comm, 0) / 100 AS comm,
    sal + IFNULL(comm, 0) AS total
FROM
    emp
where comm is not null
ORDER BY total DESC;

#11
SELECT 
    ename, sal, sal * 1.13, deptno
FROM
    emp
WHERE
    DEPTNO = 10;
    
#12
select ename, sal, round(sal/(12*5)) as 'sal/h'
from emp
where DEPTNO = 20;

#13
select ename, sal, round(sal*0.15, 2) as 회비
from emp
where sal between 1500 and 3000;

# 14
SELECT 
    ename, sal, (sal - (sal * 0.1)) AS 실수령액
FROM
    emp
ORDER BY sal DESC;

# 15
select substr(ename,1,3)
from emp
where length(ename) >= 6;

# 16
select sum(sal)/count(deptno), max(sal), min(sal), count(deptno)
from emp
where deptno=10;

# 19
select ename, HIREDATE, to_days(now())-to_days(HIREDATE) as days
from emp;

# 20
select ename, date_add(hiredate, interval now() year)
from emp;