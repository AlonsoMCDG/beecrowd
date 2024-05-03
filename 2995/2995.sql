-- 2995 - A Mensagem do Sensor
-- Alonso Martins
-- 02/05/2024
SELECT temperature, COUNT(*)
FROM (
    SELECT 
        id, temperature,
        ROW_NUMBER() OVER (ORDER BY id) - ROW_NUMBER() OVER (PARTITION BY temperature ORDER BY id) AS grp
    FROM records
) AS sq
GROUP BY temperature, grp
ORDER BY MIN(id);
