# Write your MySQL query statement below
select s.price, s.year ,p.product_name 
from sales s
left join product p
on p.product_id=s.product_id