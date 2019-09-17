#ifndef COMMANDER_H
#define COMMANDER_H
#include "instrucao.h"

class Commander: public Instrucao{
private:
    int aluno;
    
public:
    Commander(int aluno);
    virtual void executaInstrucao(Equipe &equipe);
    virtual void imprimeInstrucao();
};

#endif