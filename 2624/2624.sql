-- bee 2624 - Quantidades de Cidades por Clientes
-- Alonso Martins
-- 19/04/2024
SELECT 
    COUNT(DISTINCT c.city)
FROM
    customers c;
