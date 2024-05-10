;; bee 3348 - Jogo das Aranhas
;; Alonso Martins
;; 10/05/2024
(defn -main []
    (let [ans ["2" "7" "5" "30" "169" "441" "1872" "7632" "1740" "93313" "459901"  "1358657" "2504881" "13482720" "25779600" "68468401" "610346880" "1271932200" "327280800"]]
        (let [N (read-line)]
            (println ((comp ans dec) (Integer/parseInt N))))))

(-main)
