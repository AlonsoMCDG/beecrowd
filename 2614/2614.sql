-- bee 2614 - Locacoes de Setembro
-- Alonso Martins
-- 19/04/2024
SELECT 
	c.name, r.rentals_date
FROM
	customers c
		INNER JOIN
	rentals r ON c.id = r.id_customers
WHERE
	EXTRACT(MONTH FROM r.rentals_date) = 9 AND EXTRACT(YEAR FROM r.rentals_date) = 2016;
