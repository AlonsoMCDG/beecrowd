-- bee 2996 - Entrega de Pacotes
-- Alonso Martins
-- 02/05/2024
SELECT 
    p.year, sender.name, receiver.name
FROM
    users sender
        INNER JOIN
    packages p ON sender.id = p.id_user_sender
        INNER JOIN
    users receiver ON receiver.id = p.id_user_receiver
WHERE
    (p.color = 'blue' OR p.year = 2015)
        AND (sender.address != 'Taiwan'
        AND receiver.address != 'Taiwan')
ORDER BY p.year DESC;
