-- bee 2991 - Estatisticas dos Departamentos
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
	SELECT e.matr, dp.nome as departamento,
			sb.salario_bruto - de.total_desconto_empregado AS salario_liquido
    FROM empregado e
    LEFT JOIN (SELECT * FROM desconto_empregado) AS de USING (matr)
    LEFT JOIN (SELECT * FROM salario_bruto_empregado) AS sb USING (matr)
    LEFT JOIN departamento dp ON dp.cod_dep = e.lotacao
    ORDER BY salario_liquido DESC
), salario_departamento AS (
	SELECT
		sl.departamento,
        COUNT(*) AS empregados,
        ROUND(AVG(sl.salario_liquido), 2) AS media,
        MAX(sl.salario_liquido) AS maior,
        MIN(sl.salario_liquido) AS menor
    FROM empregado e
    LEFT JOIN salario_liquido_empregado sl USING (matr)
    GROUP BY sl.departamento
    ORDER BY media DESC
)
SELECT * FROM salario_departamento;
