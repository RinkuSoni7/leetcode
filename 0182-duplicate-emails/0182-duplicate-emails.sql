# Write your MySQL query statement below
-- select p1.email  from Person p1 inner join Person  p2
-- on p1.email=p2.email AND p1.id<p2.id;

SELECT email
FROM Person
GROUP BY email
HAVING COUNT(email) > 1;
