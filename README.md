# Sistema de gestão de uma base de dados de jogos de futebol amigáveis
O objectivo deste projeto é o desenvolvimento, em linguagem C, de um sistema de
gestão de uma base de dados de jogos de futebol amigáveis.
A interacção com o programa deverá ocorrer através de um
conjunto de linhas compostas por uma letra (comando) e um número de argumentos
dependente do comando a executar. Os possíveis comandos são listados na tabela
seguinte e indicam as operações a executar.

| Comando | Acção |
|:---:|:---|
| __a__ | Adiciona um novo jogo. |
| __A__ | Adiciona uma nova equipa. |
| __l__ | Lista todos os jogos pela ordem em que foram introduzidos. |
| __p__ | Procura um jogo. |
| __P__ | Procura uma equipa. |
| __r__ | Apaga um jogo. |
| __s__ | Altera a pontuação (_score_) de um jogo. |
| __g__ | Encontra as equipas que venceram mais jogos.
| __x__ | Termina o programa. |

* __a__ - Adiciona um novo jogo.
  * Formato de entrada: `a nome:equipa1:equipa2:score1:score2`
  * Formato de saída: NADA (excepto erro).
  * Erros:
    * `NL Jogo existente.` no caso de já existir um jogo com esse nome no sistema.
    * `NL Equipa inexistente.` no caso de uma das equipas ou ambas não existirem no sistema.
* __l__ - Lista todos os jogos introduzidos.
  * Formato de entrada: `l`
  * Formato de saída: Uma linha por jogo no formato abaixo

        NL nome-jogo nome-equipa1 nome-equipa2 score1 score2

    Os jogos deverão ser listados pela ordem em que foram introduzidos.
    Caso não exista nenhum jogo no sistema, o comando não imprime nada.
  * Erros: Não aplicável.
* __p__ - Procura um jogo com o nome dado.
  * Formato de entrada: `p nome`
  * Formato de saída: Igual ao formato de saída do comando `l` mas apenas com o jogo `nome`.
  * Erros:
    * `NL Jogo inexistente.` no caso de não existir nenhum jogo com esse nome no sistema.
* __r__ - Apaga um jogo dado um nome.
  * Formato de entrada: `r nome`
  * Formato de saída: NADA (excepto erro).
  * Erros:
    * `NL Jogo inexistente.` no caso de não existir nenhum jogo com esse nome no sistema.
* __s__ - Altera o score de um jogo dado o nome.
  * Formato de entrada: `s nome:score1:score2`
  * Formato de saída: NADA (excepto erro).
  * Erros:
    * `NL Jogo inexistente.` no caso de não existir nenhum jogo com esse nome no sistema.
* __A__ - Adiciona uma nova equipa.
  * Formato de entrada: `A nome`
  * Formato de saída: NADA (excepto erro).
  * Erros:
    * `NL Equipa existente.` no caso de já existir uma equipa com esse nome no sistema.
* __P__ - Procura uma equipa dado um nome.
  * Formato de entrada: `P nome`
  * Formato de saída: `NL nome numero-de-jogos-ganhos`.
  * Erros:
    * `NL Equipa inexistente.` no caso de não existir nenhuma equipa com esse nome no sistema.
* __g__ - Encontra as equipas que ganharam mais jogos e lista por ordem lexicográfica (do nome da equipa).
  * Formato de entrada: `g`
  * Formato de saída:
  
        NL Melhores número-de-jogos-ganhos
        NL * nome-equipa1
        NL * nome-equipa2
        NL * nome-equipa3
        ...
    Caso não exista nenhuma equipa, o comando não imprime nada (nem a palavra `Melhores`).
  * Erros: Não aplicável.
