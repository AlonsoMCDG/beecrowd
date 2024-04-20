-- bee 2623 - Categorias com Varios Produtos
-- Alonso Martins
-- 19/04/2024
SELECT 
    p.name, c.name
FROM
    products p
        INNER JOIN
    categories c ON c.id = p.id_categories
WHERE
    p.amount > 100
        AND c.id IN (1 , 2, 3, 6, 9)
ORDER BY c.id;
