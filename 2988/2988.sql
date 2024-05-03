-- bee 2988 - Campeonato Cearense
-- Alonso Martins
-- 19/04/2024
SELECT 
    t.name,
    COUNT(DISTINCT m.id) AS matches,
    SUM(CASE
			WHEN t.id = m.team_1 AND m.team_1_goals > m.team_2_goals THEN 1
            WHEN t.id = m.team_2 AND m.team_2_goals > m.team_1_goals THEN 1
			ELSE 0
		END
	),
    SUM(CASE
			WHEN t.id = m.team_1 AND m.team_1_goals < m.team_2_goals THEN 1
            WHEN t.id = m.team_2 AND m.team_2_goals < m.team_1_goals THEN 1
			ELSE 0
		END
	),
    SUM(CASE
			WHEN m.team_1_goals = m.team_2_goals THEN 1
			ELSE 0
		END
	),
    SUM(CASE
            WHEN t.id = m.team_1 AND m.team_1_goals > m.team_2_goals THEN 3
            WHEN t.id = m.team_2 AND m.team_2_goals > m.team_1_goals THEN 3
            WHEN m.team_1_goals = m.team_2_goals THEN 1
            ELSE 0
        END
    )
FROM
    teams t
INNER JOIN
    matches m ON t.id = m.team_1 OR t.id = m.team_2
GROUP BY 
    t.id, t.name
ORDER BY 
    SUM(
        CASE
            WHEN t.id = m.team_1 AND m.team_1_goals > m.team_2_goals THEN 3
            WHEN t.id = m.team_2 AND m.team_2_goals > m.team_1_goals THEN 3
            WHEN m.team_1_goals = m.team_2_goals THEN 1
            ELSE 0
        END
    ) DESC;
