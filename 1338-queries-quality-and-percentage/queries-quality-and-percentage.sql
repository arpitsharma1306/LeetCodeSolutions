# Write your MySQL query statement below
select q.query_name, round(avg(rating/position),2) as quality, 
round(count(case when rating < 3 then 1 else NULL end)*100/count(*) ,2) as poor_query_percentage
from Queries q
group by query_name