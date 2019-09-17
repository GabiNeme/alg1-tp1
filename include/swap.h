#ifndef SWAP_H
#define SWAP_H
#include "instrucao.h"

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