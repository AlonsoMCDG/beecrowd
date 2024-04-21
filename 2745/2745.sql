-- bee 2745 - Taxas
-- Alonso Martins
-- 19/04/2024
SELECT
	name, ROUND(salary * 0.1, 2)
FROM
	people
WHERE
	salary > 3000;
