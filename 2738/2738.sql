-- bee 2738 - Concurso
-- Alonso Martins
-- 19/04/2024
SELECT 
    c.name,
    ROUND(((s.math * 2) + (s.specific * 3) + (s.project_plan * 5)) / 10, 2)
FROM
    candidate c
        INNER JOIN
    score s ON c.id = s.candidate_id
ORDER BY ROUND(((s.math * 2) + (s.specific * 3) + (s.project_plan * 5)) / 10, 2) DESC;
