-- bee 2613 - Filmes em Promocao
-- Alonso Martins
-- 19/04/2024
SELECT 
	m.id, m.name
FROM
	movies m
		INNER JOIN
	prices p ON m.id_prices = p.id
WHERE
	p.value < 2;
