#ifndef COMMANDER_H
#define COMMANDER_H
#include "instrucao.h"

/*
 * Instrução Commander.
 * Dado um aluno x, retorna o seu chefe mais novo (diretamente ou não)
 */
class Commander: public Instrucao{
private:
    int aluno;
    
public:
    Commander(int aluno);
    virtual void executaInstrucao(Equipe &equipe);
    virtual void imprimeInstrucao();
};

#endif