SELECT AI.NAME AS NAME, AI.DATETIME 
FROM ANIMAL_INS AI LEFT OUTER JOIN ANIMAL_OUTS AO ON (AI.ANIMAL_ID = AO.ANIMAL_ID)
WHERE AO.DATETIME IS NULL
ORDER BY AI.DATETIME
fetch first 3 rows only;