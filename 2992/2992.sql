-- bee 2992 - Divisoes Com Maiores Medias Salariais
-- Alonso Martins
-- 06/05/2024
WITH desconto_empregado AS (
	SELECT e.matr, SUM(COALESCE(ds.valor, 0)) AS total_desconto_empregado
    FROM empregado e
    LEFT JOIN emp_desc ed USING (matr)
    LEFT JOIN desconto ds USING (cod_desc)
    GROUP BY e.matr
), salario_bruto_empregado AS (
	SELECT e.matr, SUM(COALESCE(v.valor, 0)) AS salario_bruto
	FROM empregado e
    LEFT JOIN emp_venc ev USING (matr)
    LEFT JOIN vencimento v USING (cod_venc)
    GROUP BY e.matr
    ORDER BY salario_bruto DESC
), salario_liquido_empregado AS (
	SELECT e.matr, e.nome,
			sb.salario_bruto - de.total_desconto_empregado AS salario_liquido
    FROM empregado e
    LEFT JOIN desconto_empregado de USING (matr)
    LEFT JOIN salario_bruto_empregado sb USING (matr)
    ORDER BY salario_liquido DESC
), salario_divisao AS (
	SELECT
		dp.nome AS departamento, 
		dv.nome AS divisao, 
        ROUND(AVG(sl.salario_liquido), 2) AS media
    FROM empregado e
    LEFT JOIN salario_liquido_empregado sl USING (matr)
    LEFT JOIN departamento dp ON dp.cod_dep = e.lotacao
    LEFT JOIN divisao dv ON dv.cod_divisao = e.lotacao_div
    GROUP BY departamento, divisao
    ORDER BY media DESC
), max_salario_departamento AS (
	SELECT 
		departamento, 
        divisao, 
        media,
        ROW_NUMBER() OVER (PARTITION BY departamento ORDER BY media DESC) as ranking 
	FROM salario_divisao
)
SELECT departamento, divisao, media 
FROM max_salario_departamento
WHERE ranking = 1
ORDER BY media DESC;
;
