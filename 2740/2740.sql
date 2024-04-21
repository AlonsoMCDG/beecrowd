-- bee 2740 - Liga
-- Alonso Martins
-- 19/04/2024
(SELECT CONCAT('Podium: ', team) AS resultado
FROM league
ORDER BY position
LIMIT 3)

UNION ALL

SELECT
	CONCAT('Demoted: ', team)
FROM
	(SELECT * FROM league
    WHERE position > (SELECT COUNT(*) - 2 FROM league)
    ) as sq
;
