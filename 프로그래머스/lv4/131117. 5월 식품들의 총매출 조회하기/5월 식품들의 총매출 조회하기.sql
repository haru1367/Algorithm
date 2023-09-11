SELECT PRODUCT_ID, A.PRODUCT_NAME, SUM(B.AMOUNT * A.PRICE) AS TOTAL_SALES
FROM FOOD_PRODUCT A JOIN FOOD_ORDER B USING (PRODUCT_ID)
WHERE to_char(B.PRODUCE_DATE,'YYYY-MM') LIKE '2022-05%'
GROUP BY PRODUCT_ID, A.PRODUCT_NAME
ORDER BY TOTAL_SALES DESC, PRODUCT_ID;