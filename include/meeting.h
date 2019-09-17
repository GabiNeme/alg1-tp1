#ifndef MEETING_H
#define MEETING_H
#include "instrucao.h"

class Meeting : public Instrucao{
    
public:
    Meeting();
    virtual void executaInstrucao(Equipe &equipe);
    virtual void imprimeInstrucao();
};

#endif