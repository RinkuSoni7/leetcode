# Write your MySQL query statement below
-- select a.id,a.email from Person a join Person b on a.email=b.email where a.id,a.email in (select id,distinct(email) from Person );

Delete p1 from Person p1
join Person p2
on p1.email=p2.email
AND p1.id >p2.id;