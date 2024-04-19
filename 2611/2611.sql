-- bee 2611 - Filmes de Acao
-- Alonso Martins
-- 19/04/2024
SELECT 
	m.id, m.name
FROM
	movies m
		INNER JOIN
	genres g ON m.id_genres = g.id
WHERE 
	g.description = 'Action';
