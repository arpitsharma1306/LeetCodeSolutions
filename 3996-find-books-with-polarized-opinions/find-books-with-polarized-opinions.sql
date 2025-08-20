SELECT 
    b.book_id,
    b.title,
    b.author,
    b.genre,
    b.pages,
    (MAX(s.session_rating) - MIN(s.session_rating)) AS rating_spread,
    ROUND(
        SUM(CASE WHEN s.session_rating <= 2 OR s.session_rating >= 4 THEN 1 ELSE 0 END) / COUNT(s.session_id),
        2
    ) AS polarization_score
FROM books b
JOIN reading_sessions s 
    ON b.book_id = s.book_id
GROUP BY b.book_id
HAVING 
    COUNT(s.session_id) >= 5
    AND SUM(CASE WHEN s.session_rating <= 2 THEN 1 ELSE 0 END) > 0
    AND SUM(CASE WHEN s.session_rating >= 4 THEN 1 ELSE 0 END) > 0
    AND ROUND(
        SUM(CASE WHEN s.session_rating <= 2 OR s.session_rating >= 4 THEN 1 ELSE 0 END) / COUNT(s.session_id),
        2
    ) >= 0.6
ORDER BY polarization_score DESC, b.title DESC;
