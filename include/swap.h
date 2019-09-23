#ifndef SWAP_H
#define SWAP_H
#include "instrucao.h"
/*
 * Instrução Swap.
 * Realiza a inversão do comando entre o aluno 1 e 2, se esse comando existir,
 * e se a troca não gerar um ciclo
 */
class Swap: public Instrucao{
private:
    int aluno1;
    int aluno2;
    
public:
    Swap(int aluno1, int aluno2);
    virtual void executaInstrucao(Equipe &equipe);
    virtual void imprimeInstrucao();
};

#endif