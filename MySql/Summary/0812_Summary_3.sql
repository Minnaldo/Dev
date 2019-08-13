/* 대소문자 구별하지 않는다. */

create database ssafydb;	/* ssafydb라는 이름으로 데이터베이스를 생성 */
use ssafydb;	/*만들어진 데이터베이스에 접속*/

-- standard sql 92 --
/* MYSql은 속성의 데이터 타입을 적어주어야 함 */
-- 문자 : char varchar 사용
-- 숫자 : 정수형 int or integer, 실수형 float, double, 
-- varchar는 크기를 지정해주어야 함
create table ssafytb(name varchar(10), age int, addr varchar(100),tel varchar(20));

-- 데이터 삽입
-- 문자열은 항상 single quotation으로 감싼다name
-- insert는 where절이 없다.
insert into ssafytb(name, age, addr, tel) values ('홍길동',21,'광산구','01001010101');
insert into ssafytb(name, age, addr, tel) values ('박길동',31,'북구','01001222221');
insert into ssafytb(name, age, addr, tel) values ('김길동',41,'남구','01044443333');

-- table에 저장된 데이터를 불러온다
select name,age,addr,tel from ssafytb where name = '김길동';	/* 조건절 row에 대한 filter를 수행한다 */

-- 조건은 여러개도 가능하다 ( and, or 등을 이용한다)
select name,age,addr,tel from ssafytb where age >=31 and name = '박길동';

update ssafytb set name = '김대감',age=55 where age = 31;

select name, age, addr, tel from ssafytb;

# delete from ssaftb;	/* 테이블을 삭제 */
delete from ssafytb where addr='북구';
		
-- 테이블 객체를 삭제하는 명령어
drop table ssafytb;

