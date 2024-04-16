-- bee 2604 - Menores que 10 ou Maiores que 100
-- Alonso Martins
-- 16/04/2024
SELECT
	id, name
FROM
	products
WHERE
	price < 10 OR price > 100;
