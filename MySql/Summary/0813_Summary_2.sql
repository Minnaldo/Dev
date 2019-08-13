# DDL (Data Definition Languate)
Create database testdb;	-- testdb 이름으로 database를 생성한다.
drop database testdb;	-- testdb를 제거한다
use testdb;		-- testdb 데이터베이스를 사용한다

-- 현재 사용중인 database에 testTB이름으로 table 생성
create table testTB(id int primary key, title varchar(100), content varchar(2000), regdate datetime);

-- 테이블에 column을 추가한다
alter table testTB add(cnt int);
-- 테이블에 있는 column을 삭제한다
alter table testTB drop cnt;
-- 테이블 내의 데이터만 없어진다
truncate table testTB;
-- 테이블의 이름 변겅
rename table testTB to ssafyTB;


-- 테이블 제거
drop table testTB;

# DML (Data Manipulation Language)

-- 데이터 삽입
-- values의 값들로 tableTB의 colum에 맞게 삽입한다
-- 여러번 사용하면 여러번 들어간다
-- insert를 사용할 때 column의 순서를 바꿔도 되나, values의 값도 이에 맞게 위치를 바꾸어줘야 한다
-- column의 생략도 가능하다

-- 명시적 insert 문
insert into testTB(id, title, content, regdate) values (1,'title1','content1','20190813');	-- 날짜는 그냥 넣으면 된다
insert into testTB(id,content) values (4,'content4');
insert into testTB(title,content,id) values ('title2','content2',2);


-- 암시적 insert 문
-- table column을 쓰지 않고 values에 값만 집어넣는다.
-- 단, 초기 테이블에 설정된 column과 위치와 데이터형이 맞아야 한다.
-- 데이터를 넣기 싫다면 'null' 이라도 넣어주어야 한다
insert into testTB values(6, 'title6', 'content6'); 
insert into testTB values(7, null, 'content7');



#
-- query
-- testTB 테이블에 있는 모든 정보를 조회
select * from testTB;

-- 수정
-- title column의 값을 바꾼다.
update testTb set title='aaa'
where id = 2;	-- => id가 2인 row의 title column데이터를 aaa로 바꾼다.

-- 삭제
delete from testTB;

commit;

# view ( 가상의 객체 )
-- 생성	as 밑의 조건절의 결과를 값으로 갖는 뷰를 생성
create view vEmp
as
select id, title, content, regdate as reg1, regdate as reg2
from testTB;

select * from vEmp;

select * from testTB;

