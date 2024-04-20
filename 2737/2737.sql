-- bee 2737 - Advogados
-- Alonso Martins
-- 19/04/2024
(SELECT 
    name, customers_number
FROM
    lawyers
ORDER BY customers_number DESC
LIMIT 1) 
UNION ALL 
(SELECT 
    name, customers_number
FROM
    lawyers
ORDER BY customers_number
LIMIT 1) 
UNION ALL 
(SELECT 
    'Average' AS name,
    ROUND(AVG(customers_number)) AS customers_number
FROM
    lawyers);
