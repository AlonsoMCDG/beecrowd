-- bee 2625 - Mascara de CPF
-- Alonso Martins
-- 19/04/2024
SELECT 
    CONCAT(SUBSTR(np.cpf, 1, 3),
            '.',
            SUBSTR(np.cpf, 4, 3),
            '.',
            SUBSTR(np.cpf, 7, 3),
            '-',
            SUBSTR(np.cpf, 10, 2))
FROM
    natural_person np;
