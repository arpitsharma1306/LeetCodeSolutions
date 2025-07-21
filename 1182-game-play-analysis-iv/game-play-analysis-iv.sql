SELECT 
    ROUND(
        SUM(
            CASE 
                WHEN DATEDIFF(a1.event_date, a2.event_date) = 1 THEN 1 
                ELSE 0 
            END
        )/count(distinct a1.player_id), 
        2
    ) AS fraction
FROM Activity a1
JOIN Activity a2 
    ON a1.player_id = a2.player_id
WHERE (a2.player_id,a2.event_date) in (
    SELECT player_id, MIN(event_date)
    FROM Activity
    group by player_id
);
