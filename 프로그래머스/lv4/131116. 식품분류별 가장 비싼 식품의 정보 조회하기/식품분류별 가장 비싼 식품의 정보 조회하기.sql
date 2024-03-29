SELECT B.CATEGORY, B.PRICE AS MAX_PRICE, B.PRODUCT_NAME
FROM (SELECT CATEGORY, MAX(PRICE) AS PRICE
      FROM FOOD_PRODUCT
     GROUP BY CATEGORY) A, FOOD_PRODUCT B
WHERE  A.CATEGORY = B.CATEGORY
AND A.PRICE = B.PRICE 
AND (B.CATEGORY = '과자' OR B.CATEGORY = '국' OR B.CATEGORY = '김치' OR B.CATEGORY = '식용유') 
ORDER BY B.PRICE DESC;