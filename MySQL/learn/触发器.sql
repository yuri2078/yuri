create table yuri.yuri(
    id int PRIMARY key
);

create table yuri.log(
    log VARCHAR(30)
);

SELECT * FROM yuri.yuri;
SELECT * FROM yuri.log;

use yuri;
drop trigger yuri_log;

create trigger yuri_log
before insert 
on yuri
for each row
begin
    if new.id > 2 then
        set new.id = 4;
    end if;
    insert log values(CONCAT("新插入的数据 -> ", new.id));
end;

insert into yuri values(44);
