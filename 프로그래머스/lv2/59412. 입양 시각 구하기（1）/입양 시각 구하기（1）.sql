SELECT to_number(to_char(DATETIME,'hh24')) AS HOUR,COUNT(to_char(DATETIME,'hh24')) AS COUNT 
FROM ANIMAL_OUTS
WHERE to_char(DATETIME,'hh24') >= 9 AND to_char(DATETIME,'hh24') <20
GROUP BY to_char(DATETIME,'hh24')
ORDER BY to_char(DATETIME,'hh24');