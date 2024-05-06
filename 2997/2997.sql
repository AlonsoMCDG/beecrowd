-- bee 2997 - Pagamento dos Empregados
-- Alonso Martins
-- 05/05/2024
SELECT
	dp.nome AS departamento, 
    e.nome AS empregado,
    salario_empregado.salario_bruto, 
    desconto_empregado.desconto,
    salario_empregado.salario_bruto - desconto_empregado.desconto AS salario_liquido
FROM
	empregado e
    LEFT JOIN (SELECT e.matr, SUM(COALESCE(ds.valor, 0)) AS desconto
				FROM empregado e
					LEFT JOIN emp_desc ed ON ed.matr = e.matr
					LEFT JOIN desconto ds ON ds.cod_desc = ed.cod_desc
				GROUP BY e.matr
				) AS desconto_empregado ON desconto_empregado.matr = e.matr
	LEFT JOIN (SELECT e.matr, SUM(COALESCE(v.valor, 0)) AS salario_bruto
				FROM empregado e
					LEFT JOIN emp_venc ev ON ev.matr = e.matr
                    LEFT JOIN vencimento v ON v.cod_venc = ev.cod_venc
				GROUP BY e.matr
				) AS salario_empregado ON salario_empregado.matr = e.matr
    LEFT JOIN departamento dp ON dp.cod_dep = e.lotacao
    LEFT JOIN divisao dv ON dv.cod_divisao = e.lotacao_div
    GROUP BY dp.nome, dv.nome, e.nome, salario_empregado.salario_bruto, desconto_empregado.desconto
    ORDER BY salario_liquido DESC, empregado DESC;
