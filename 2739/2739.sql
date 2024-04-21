-- bee 2739 - Dia de Pagamento
-- Alonso Martins
-- 19/04/2024
SELECT 
    name, EXTRACT(DAY FROM payday)::INT
FROM
    loan;
