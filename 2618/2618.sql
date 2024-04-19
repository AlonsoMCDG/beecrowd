-- bee 2618 - Produtos Importados
-- Alonso Martins
-- 19/04/2024
SELECT
	p.name, pr.name, c.name
FROM
	products p
		INNER JOIN
	providers pr ON p.id_providers = pr.id
		INNER JOIN
	categories c ON c.id = p.id_categories
WHERE
	pr.name = 'Sansul SA' AND c.name = 'Imported';
