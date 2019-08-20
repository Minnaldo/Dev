use ws0820;

create table Book(
	isbn char(8) primary key, 
	title varchar(50) not null, 
	publisher varchar(15) not null, 
	price int not null, 
	description varchar(200), 
	authorno int(2)    
);

CREATE TABLE aa (
    isbn CHAR(8) PRIMARY KEY,
    title VARCHAR(50) NOT NULL,
    publisher VARCHAR(15) NOT NULL,
    price INT NOT NULL,
    description VARCHAR(200),
    authorno INT(2),
    PRIMARY KEY (isbn),	-- 이 방식으로 특성을 지정할 수 있음
    FOREIGN KEY (authorno)
        REFERENCES author (authorno)
);


#1 ==================================================================================
CREATE TABLE author (
    authorno INT(2) PRIMARY KEY,
    name VARCHAR(50),
    phone VARCHAR(30)
);

insert into author(authorno, name, phone) values(10, '김태희','01000001000');
insert into author(authorno, name, phone) values(20, '이태희','01000003100');
insert into author(authorno, name, phone) values(30, '박태희','01009000000');
insert into author(authorno, name, phone) values(40, '최태희','01000004400');

insert into book(isbn, title, publisher, price, description, authorno)
values('100-1001', 'title1','publisher1',50000,'desc1',10);
insert into book(isbn, title, publisher, price, description, authorno)
values('100-0101', 'title2','publisher12',40000,'desc1',10);
insert into book(isbn, title, publisher, price, description, authorno)
values('100-0111', 'title3','publish1',4000,'desc1',30);
insert into book(isbn, title, publisher, price, description, authorno)
values('100-0301', 'title4','publer1',2000,'desc1',20);
insert into book(isbn, title, publisher, price, description, authorno)
values('100-0201', 'title5','publ1sher1',60000,'desc1',30);


#2 ==================================================================================
alter table book
add foreign key (authorno) references author(authorno);



#3 ==================================================================================
SELECT 
    a.title, a.price, b.name
FROM
    book a,       
    author b
where a.authorno = b.authorno;


#4 ==================================================================================
-- sub query로 해결한 방법
-- 인덱스가 걸려있어야 한다(?)
SELECT 
    a.title, a.isbn, a.publisher
FROM
    book a
WHERE
    a.authorno = (select authorno from author where name='김태희' limit 1);	-- limit 1 : 한건의 데이터만 찾고 그만 둔다

-- sub query방식에 인덱스가 없다면 join방식이 빠르다
-- join을 이용한 방법
SELECT 
    a.title, a.isbn, a.publisher
FROM
    book a,
    author b
WHERE
    a.authorno = b.authorno
        AND b.name = '김태희';
    
    
# 5 ==================================================================================
SELECT 
    a.title, a.publisher, a.price, name
FROM
    book a
        INNER JOIN
    author b ON (a.authorno = b.authorno)
ORDER BY name;




#6 ==================================================================================
SELECT 
    CONCAT(title,
            '은 ',
            publisher,
            '에서 출판했다') AS result
FROM
    book;