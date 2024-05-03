-- bee 2994 - Quanto Ganha um Medico?
-- Alonso Martins
-- 02/05/2024
SELECT 
    d.name, ROUND(SUM((150 * a.hours) * (100 + w.bonus) / 100.0), 1)
FROM
    doctors d
        INNER JOIN
    attendances a ON d.id = a.id_doctor
        INNER JOIN
    work_shifts w ON w.id = a.id_work_shift
    GROUP BY d.name
    ORDER BY ROUND(SUM((150 * a.hours) * (100 + w.bonus) / 100.0), 1) DESC;
