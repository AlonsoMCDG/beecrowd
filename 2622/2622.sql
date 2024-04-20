-- bee 2622 - Pessoas Juridicas
-- Alonso Martins
-- 19/04/2024
SELECT
	c.name
FROM
	customers c
		LEFT JOIN
	legal_person lp ON c.id = lp.id_customers
WHERE
	lp.cnpj IS NOT NULL;
