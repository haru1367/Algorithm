SELECT FLAVOR FROM FIRST_HALF WHERE TOTAL_ORDER >3000
INTERSECT
SELECT FLAVOR FROM ICECREAM_INFO WHERE INGREDIENT_TYPE = 'fruit_based';