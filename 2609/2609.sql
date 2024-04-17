-- bee 2609 - Produtos por Categorias
-- Alonso Martins
-- 16/04/2024
SELECT 
    c.name, SUM(p.amount)
FROM
    products p
        INNER JOIN
    categories c ON p.id_categories = c.id
GROUP BY c.name;
