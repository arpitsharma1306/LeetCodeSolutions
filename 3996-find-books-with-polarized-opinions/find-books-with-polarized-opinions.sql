# Write your MySQL query statement below
select 
    b.book_id,
    b.title,
    b.author,
    b.genre,
    b.pages,
    (max(s.session_rating)-min(s.session_rating)) as rating_spread,
    round(sum(case when s.session_rating<=2 or s.session_rating>=4 then 1 else 0 end)/count(s.session_id),2)
    as polarization_score
    from books b join reading_sessions s
    on b.book_id = s.book_id
    group by b.book_id
    having 
    count(s.session_id) >= 5 and
    sum(case when s.session_rating<=2 then 1 else 0 end)>0 and
    sum(case when s.session_rating>=4 then 1 else 0 end)>0 and
    round(sum(case when s.session_rating<=2 or s.session_rating>=4 then 1 else 0 end)/count(s.session_id),2)>=0.6
    order by polarization_score desc, b.title desc;
