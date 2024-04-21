-- bee 2742 - O Multiverso de Richard
-- Alonso Martins
-- 19/04/2024
SELECT 
    lf.name, ROUND(omega * 1.618, 3)
FROM
    dimensions d
        INNER JOIN
    life_registry lf ON d.id = lf.dimensions_id
WHERE
    lf.name LIKE 'Richard%'
        AND d.name IN ('C875' , 'C774')
ORDER BY omega;
