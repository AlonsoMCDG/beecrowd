-- bee 2616 - Nenhuma Locacao
-- Alonso Martins
-- 19/04/2024
SELECT 
    c.id, c.name
FROM
    customers c
        LEFT JOIN
    locations l ON c.id = l.id_customers
WHERE
    l.id_customers IS NULL;
