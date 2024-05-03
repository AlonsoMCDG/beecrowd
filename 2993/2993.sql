-- bee 2993 - Mais Frequente
-- Alonso Martins
-- 02/05/2024
SELECT 
    amount
FROM
    (SELECT 
        amount, COUNT(*)
    FROM
        value_table
    GROUP BY amount
    ORDER BY COUNT(*) DESC
    LIMIT 1) AS sq;
