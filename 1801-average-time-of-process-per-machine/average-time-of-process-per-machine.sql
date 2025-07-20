# Write your MySQL query statement below
select now.machine_id, ROUND(AVG(now.timestamp - start.timestamp),3) as processing_time
from Activity now inner join Activity start
on now.machine_id = start.machine_id and now.process_id = start.process_id and now.activity_type = 'end' and start.activity_type = 'start'
group by now.machine_id;