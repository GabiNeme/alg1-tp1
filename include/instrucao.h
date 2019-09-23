#ifndef INSTRUCOES_H
#define INSTRUCOES_H
#include "equipe.h"

//Interface Instrução

class Instrucao{

public:

    virtual ~Instrucao() = default;
    virtual void executaInstrucao(Equipe &equipe) =0;
    virtual void imprimeInstrucao() = 0;
    
};


#endif