CREATE DATABASE IF NOT EXISTS qtMysql
    CHARSET utf8mb4;


create table if not exists test(
    id int not null
);

show tables from `qtMysql`;

insert into  qtMysql.test (id) 
values (1),(2);

select * from `qtMysql`.test;

show DATABASES;