-- bee 2744 - Senhas
-- Alonso Martins
-- 19/04/2024
SELECT
	id, password, MD5(password)
FROM
	account;
