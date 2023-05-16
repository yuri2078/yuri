/* 简单存储过程 */
drop PROCEDURE hello;
CREATE PROCEDURE hello ()
BEGIN
    select "hello world";
END;
call hello();

/* 传入参数存储过程 */
drop procedure test;
create procedure test(in x int, in y int, out sum int) 
begin
    set sum := x + y;
    select sum;
end;

set @s = 5;
call test(1,2,@s);
SELECT @s;

/* if 语句测试 */
drop procedure test;
create procedure test(in x int) 
begin
    if x > 10 then
        select 'x > 10';
    elseif x > 5 then
        select 'x > 5';
    else
        select 'x < 5';
    end if;
end;
call test(3);

/* case 语句测试 */
drop procedure test;
create procedure test(in x int) 
begin
    case x
        when 2 then select '2';
        when 3 then select '3';
        else select 'no';
    end case;
end;
call test(1);


/* 循环 语句测试 */
drop procedure test;
create procedure test(in x int) 
begin
    DECLARE i int default 5;
    declare sum int default 0;

    while x > 0 do
        set sum = sum + 1;
        set x = x - 1;
    end while;
    repeat 
        set sum = sum + 1;
        set i = i - 1;
    until i < 0 end repeat;

    select sum ;
end;
call test(3);






