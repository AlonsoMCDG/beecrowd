-- bee 2621 - Quantidades Entre 10 e 20
-- Alonso Martins
-- 19/04/2024
SELECT
	p.name
FROM
	products p
		INNER JOIN
	providers pr ON pr.id = p.id_providers
WHERE
	p.amount > 10 AND p.amount < 20 AND pr.name LIKE 'P%';
