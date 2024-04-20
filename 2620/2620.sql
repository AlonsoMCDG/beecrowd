-- bee 2620 - Pedidos no Primeiro Semestre
-- Alonso Martins
-- 19/04/2024
SELECT
	c.name, o.id
FROM
	customers c
		INNER JOIN
	orders o ON c.id = o.id_customers
WHERE
	EXTRACT(MONTH FROM o.orders_date) <= 6 AND  EXTRACT(YEAR FROM orders_date) = 2016;
