# Write your MySQL query statement below
select e2.employee_id, e2.name, count(distinct e1.employee_id) as reports_count, round(avg(e1.age),0) as average_age
from Employees e1 inner join Employees e2
where e1.reports_to = e2.employee_id
group by employee_id