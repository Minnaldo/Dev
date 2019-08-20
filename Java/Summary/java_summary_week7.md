# Java Summary Week 7
## DataBase
cross product join : 데이터의 수는 n*n이 된다

### 두개의 테이블을 연결하는 법
- join을 사용한다
```sql
-- Inner Join
select
    num, name, student.dno, dname
from
    student, department
where
    student.dno = department.dno;
```