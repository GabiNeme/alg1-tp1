## UFMG - DCC - Algoritmos I - 2019/2
# Trabalho Prático 1: Hierarquia em equipes
Gabriela Peres Neme, 2018054745

## Objetivo
O presente trabalho teve como objetivo aplicar uma série de instruções a um grafo dirigido não ponderado acíclico, que representa a hierarquia de uma equipe de alunos. Os vértices representam alunos, e uma aresta de A para B representa que A é comandado por B.

As instruções consistem em: Swap, que inverte a hierarquia de dois alunos; Commander, que retorna a idade da pessoa mais jovem que comanda determinado aluno; e Meeting, que identifica uma ordem de fala todos os alunos, de forma que se um aluno A comanda um aluno B, A deve falar antes de B.
Para mais detalhes, favor consultar a documentação.

## Como usar

Para compilar o programa, digite na linha de comando:
```{bash}  
make
```  
Para rodar o programa, digite na linha de comando:
``` {bash}
./tp1 <nome do arquivo de entrada>.txt
```  

Exemplos:
```  
./tp1 novo_arquivo.txt
./tp1 dataset/equipe3.txt
```  

## Entrada de dados 
O arquivo de entrada deve conter, na primeira linha, três inteiros separados por espaço, N, M e I, indicando respectivamente o número de pessoas no time, o número de relações de hierarquia direta entre os membros e o número de instruções. Os N alunos são representados através de números de 1 a N.

Na segunda linha do arquivo devem existir N números, separados por espaço, que indicam a idade dos N membros da equipe, em ordem. Nas próximas M linhas existirão dois números inteiros X e Y que indicam membros da equipe. Se X aparece antes de Y, significa que X comanda diretamente Y.

As próximas I linhas contêm, cada uma, uma instrução. As instruções do tipo Swap iniciam com um S seguido de dois inteiros, A e B, que representam os alunos que se deseja inverter a hierarquia. As instruções do tipo Commander são seguidas de um inteiro, indicando um aluno. Por fim, as instruções do tipo Meeting consistem em uma linha contendo apenas a letra M.

## Saída de dados
Os resultados das instruções são impressos na saída padrão, na mesma ordem que elas foram especificadas no arquivo de entrada.

Para cada instrução Swap o programa imprime S T caso a troca tenha sido um sucesso e S N caso contrário. Para cada instrução Commander o programa imprime C X, em que X é um inteiro correspondente à idade da pessoa mais jovem que comanda o aluno especificado na entrada da instrução. Caso o aluno não seja comandado por ninguém, será impresso C *. 	Por fim, para a instrução Meeting será impressa a letra M seguida de uma ordem de fala dessa equipe.

## Exemplos
Disponíveis na pasta "dataset" deste repósitorio, e as respectivas saídas estão na pasta "resultados" desse repositório.