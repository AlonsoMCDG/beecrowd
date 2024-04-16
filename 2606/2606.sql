-- bee 2606 - Categorias
-- Alonso Martins
-- 16/04/2024
SELECT 
    p.id, p.name
FROM
    products p
        INNER JOIN
    categories c ON p.id_categories = c.id
WHERE
    c.name LIKE 'super%';
