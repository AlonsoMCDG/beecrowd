-- bee 2990 - CPF Dos Empregados
-- Alonso Martins
-- 21/04/2024
SELECT 
    e.cpf, e.enome, d.dnome
FROM
    empregados e
        LEFT JOIN
    trabalha t ON e.cpf = t.cpf_emp
        INNER JOIN
    departamentos d ON d.dnumero = e.dnumero
WHERE
    t.cpf_emp IS NULL
ORDER BY e.cpf;
