-- bee 2741 - Notas dos Alunos
-- Alonso Martins
-- 19/04/2024
SELECT 
    CONCAT('Approved: ', name), grade
FROM
    students
WHERE
    grade >= 7
ORDER BY grade DESC;
