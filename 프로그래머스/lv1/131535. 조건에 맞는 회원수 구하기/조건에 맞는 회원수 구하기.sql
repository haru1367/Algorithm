SELECT COUNT(*) AS USERS 
FROM USER_INFO 
WHERE AGE >=20 AND AGE <=29 AND to_char(JOINED,'YYYY') = '2021';