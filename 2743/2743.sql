-- bee 2743 - Quantidade de Caracteres
-- Alonso Martins
-- 19/04/2024
SELECT
	name, CHAR_LENGTH(name)
FROM
	people ORDER BY CHAR_LENGTH(name) DESC;
