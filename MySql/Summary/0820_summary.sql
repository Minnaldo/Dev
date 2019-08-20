# INNER JOIN

-- join
-- 2개 이상의 테이블을 연결하여 하나의 집합셋으로 추출하는 방법
-- 종류
-- inner join : 연결되는 데이터만을 이용하여 추출하는 방법
-- outer join (left outer join, right outer join, full outer join) : 
-- self join
-- cross join
-- natural join ( 잘 안쓰고, 쓰지 말아야 한다)


-- foreing key(references) : 참조 키, 외래 키 - 참조하는 테이블에 없는 데이터를 입력하는 것을 방지해준다

use testdb;

-- 식별자이므로 primary key로 만들 수 있다.
CREATE TABLE student (
    num VARCHAR(8) PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    age INT DEFAULT 1,
    addr VARCHAR(500),
    gender CHAR(3) CHECK (gender IN ('남' , '여')),
    dno VARCHAR(2),
    foreign key(dno) references department(dno)	-- dno가 department 테이블의 dno를 참조하여 쿼리의 실행 여부를 판단한다
);

CREATE TABLE department (
    dno VARCHAR(2) PRIMARY KEY,
    dname VARCHAR(100) NOT NULL,
    loc VARCHAR(1000)
);

insert into student (num, name, age, addr, gender, dno) values ('20190101','홍길동',21,'광산구','남', 10);
insert into student (num, name, addr, gender, dno) values ('20190102','일지매','광산구','여',20);
insert into student (num, name, addr, gender, dno) values ('20190103','송골매','광산구','남', 30);

insert into department (dno, dname, loc) values ('10','java','303');
insert into department (dno, dname, loc) values ('20','database','302');
insert into department (dno, dname, loc) values ('30','python','301');
insert into department (dno, dname, loc) values('40','c++','300');

select * from student;
select * from department;

-- 참조 무결성
insert into student(num, name,addr, gender, dno)
values ('20190913','골뱅이','광산구','남', null);

-- null값은 들어가지만(null은 비교할수 없기때문에 foreign key에 영향을 받지 않는다), department.dno에 없는 데이터는 데이터가 삽입되지 않는다.
insert into student(num, name,addr, gender, dno)
values ('20190919','강냉이','광산구','남', 30);

select * from student a, department b
where a.dno = b.dno;

-- 학번, 이름, 학과 번호, 학과 이름
SELECT 
    num, name, student.dno, dname
FROM
    student,
    department
WHERE
    student.dno = department.dno;	-- 두개의 테이블을 join하였음
    
-- 'java' 학과의 학생수를 구하라
SELECT 
    COUNT(num)
FROM
    student a
        INNER JOIN
    department b ON (a.dno = b.dno)
WHERE
    1 AND a.dno = b.dno AND dname = 'java';
    

use scott;
desc emp;
desc dept;

-- 이름, 급여, 부서 번호
SELECT 
    ename, sal, dname
FROM
    emp a
        INNER JOIN
    dept b ON (a.deptno = b.deptno)
ORDER BY ENAME;

-- 이름, 급여, 부서 번호
SELECT 
    ename, sal, dname
FROM
    emp a,
    dept b
WHERE
    a.deptno = b.deptno
ORDER BY ename;

-- end of inner join

-- outer join
select * from emp;

-- 이너조인에서는 데이터 참조 무결성이 깨지지 않았다는 전제 하에, 자식테이블에 있는 갯수만큼 나오게 된다
select a.num, a.name, a.age, a.gender, b.dname, b.loc
from student a, department b
where a.dno = b.dno;


select * from department;

-- 학과 위치가 301인 학과의 학생 정보를 구하세요
select dno from department where loc='301';
select * from student where dno = '30';

-- 위의 두 쿼리를 합친다
select *
from student
where dno = (select dno from department where loc='301');