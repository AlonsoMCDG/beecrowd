-- bee 2998 - The Payback
-- Alonso Martins
-- 06/05/2024
WITH sum_profit AS (
	SELECT
		o.id,
        SUM(o.profit) OVER (PARTITION BY c.id ORDER BY o.month) AS acumulado
	FROM clients c
    INNER JOIN operations o ON o.client_id = c.id
), payback AS (
SELECT 
	c.id, c.name, 
    o.month, o.profit,
	sp.acumulado, investment,
    ROW_NUMBER() OVER (PARTITION BY c.id ORDER BY month ASC) AS ranking
FROM 
	clients c
    INNER JOIN operations o ON o.client_id = c.id
    LEFT JOIN sum_profit sp ON sp.id = o.id
    WHERE acumulado >= investment
)
SELECT name, investment, month, acumulado - investment AS retorno
FROM payback 
WHERE ranking = 1
ORDER BY retorno DESC
;
