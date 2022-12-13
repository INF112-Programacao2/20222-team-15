# 20222-team-15
20222-team-15
Trabalho final da disciplina de inf112 - programação 2

    -> Jogo de tabuleiro inspirado em 100% orange juice
        
        Você controla os movimentos pelo Terminal (cmd)

        Ande pelo tabuleiro, caso pise em
            Casas Vermelhas: Um inimigo menor te atacará, mate-o e ganhará Abacaxis
            Casas Laranjas: Deixará cair 4 Abacaxis
            Casas Amarelas: Encontrará 4 Abacaxis, que sorte
            Casas Rosas: Será teleportado para o outro canto do mapa
            Casas de Cura: Terá sua vida restaurada por completo e, caso tenha no mínimo 5 Abacaxis poderá depositálos no pote
            Casas Cinzas: Não fazem nada
            Um de seus companheiros caídos: Ele ressucitará com metade da vida máxima
        
        Fuja do inimigo
            Caso Cuadrado e você se encontrem quem estava andando iniciará uma batalha com o outro, mate-o e você ganha o jogo
        
        Em batalhas
            Seus pontos de ataque, defesa e esquiva serão somados ao número do dado (D6)
            Para defender um ataque sua defesa precisa ser menor ou igual ao ataque do adversário, o dano recebido será ataque - defesa
            Para esquivar de um ataque sua esquiva precisa ser maior que o ataque do adversário, assim nenhum dano será recebido
            Caso tente e não consiga defender ou esquivar, todo o dano será recebido

        Guarde seus Abacaxis
            Outra forma de ganhar o jogo é acumulando pelo menos 30 Abacaxis no pote


    -> Para compilar e rodar o programa (no windows) digite no Terminal:
        make
        main

