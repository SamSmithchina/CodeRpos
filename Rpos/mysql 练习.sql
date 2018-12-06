/*
information data: 
	1	bingzong	wang	jiangxi	123000123	NUAA
	2	zheng	liu	sichuang	128971990	BUAA
	3	shan	zhang	hunan	123010000	PINGKING
	4	hui	zhu	hubei	123000000	NJU
	5	bao	zhao	anhui	123890092	BJU
	
.library  data:
'1', '1', '3', '2018-12-05 16:58:15', '4.3', 'helo1'
'2', '2', '6', '2018-12-05 16:52:02', '4.3', 'helo10'
'3', '5', '7', '2018-12-05 16:52:02', '4.3', 'helo11'
'1', '1', '5', '2018-12-05 16:52:02', '4.3', 'helo12'
'2', '1', '4', '2018-12-05 16:52:02', '4.3', 'helo13'
'4', '4', '3', '2018-12-05 16:52:02', '4.3', 'helo14'
'5', '3', '7', '2018-12-05 16:52:02', '4.3', 'helo15'
'2', '3', '8', '2018-12-05 16:52:02', '4.3', 'helo16'
'2', '3', '2', '2018-12-05 16:52:02', '4.3', 'helo2'
'3', '2', '2', '2018-12-05 16:52:02', '4.3', 'helo3'
'4', '4', '1', '2018-12-05 16:52:02', '4.3', 'helo4'
'5', '5', '3', '2018-12-05 16:52:02', '4.3', 'helo5'
'3', '2', '4', '2018-12-05 16:52:02', '4.3', 'helo6'
'4', '1', '1', '2018-12-05 16:52:02', '4.3', 'helo7'
'4', '1', '3', '2018-12-05 16:52:02', '4.3', 'helo8'
'5', '4', '4', '2018-12-05 16:52:02', '4.3', 'helo9'

*/

CREATE database wbz_test;
USE wbz_test;

CREATE table information
(
	Student_id int(20) not null,
	first_name char(20),
    last_name  char(30),
    address char(50),
    phone_number int(13) not null,
    department char(30)
    -- primary key(student_id, phone_number);
);


--   加一个栏位: ADD "栏位 1" "栏位 1 资料种类"
--   删去一个栏位: DROP "栏位 1"
--   改变栏位名称: CHANGE "原本栏位名" "新栏位名" "新栏位名资料种类"
--   改变栏位的资料种类: MODIFY "栏位 1" "新资料种类" 
alter table information change Student_id student_id char(20);
alter table information add score char ;
alter table information modify score double;
alter table information drop score;
 
alter table information add primary key( student_id , phone_number );

/*
CREATE INDEX "INDEX_NAME" ON "TABLE_NAME" (COLUMN_NAME);
*/
insert into information(student_id,first_name, last_name,address,phone_number,department)
values("1", "bingzong", "wang","shenzhen",123000123,"NUAA");

/*
UPDATE "表格名"
SET "栏位1" = [新值]
WHERE "条件";
*/
update information 
set address = "jiangxi"
where phone_number= 123000123 
and
student_id = "1";


create table library
(
	 book_id int(32) not null,
     borrower char(20) not null,
     borrowed_timws int(10),
     borrowed_date timestamp,
     price float,
     primary key(book_id)
     -- foreign key(borrower_id) references information(student_id)
);

alter table library drop primary key;
alter table library add book_name char (30);
alter table library modify column book_name char(30) not null;
alter table library add primary key(book_name);
alter table library add foreign key(borrower) references information(student_id);
alter table library change borrowed_timws borrowed_times int(10);
insert into library(book_id, borrower, borrowed_times,borrowed_date,price )
values
(1,1,3,"2018-12-5 16:39:30",4.30);

-- sql的left join 、right join 、inner join之间的区别
select sum(borrowed_times) ,information.last_name, information.first_name , student_id
from library left join  information on libary.borrower = information.student_id
group by student_id
having sum(borrowed_times);
 
select sum(borrowed_times), book_id, book_name
	from library ,information
where
	library.borrower = information.student_id
	group by book_id
    having sum(borrowed_times)
    order by sum(borrowed_times) asc;

select * ,sum(borrowed_times)
from library 
where borrower 
in 
    (
    select borrower from library where borrower >= "0" and borrower <= "5"
    )
	and borrowed_times > 5
   group by borrower
   having sum(borrowed_times)
    order by sum(borrowed_times) asc;

select *,sum(borrowed_times)
from library 
where borrower 
	in 
    (
    select borrower from library where borrower   between  "0" and  "5"
    )
	and borrowed_times > 5
   group by borrower
   having sum(borrowed_times)
    order by borrowed_times desc;

select count(book_id) from library ;
select distinct book_id from library ;
select distinct book_id,count(distinct book_id) from library ;
