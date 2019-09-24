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