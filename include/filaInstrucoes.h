#ifndef VARIABLE
#define VARIABLE

#include "commander.h"
#include "swap.h"
#include "meeting.h"

/*
 * Armazena as intruções solicitadas pelo usuário e as executa após o fim da leitura
 */
class FilaInstrucoes{
    
private:
    std::list<Instrucao *> listaInstrucoes;
    
public:
    FilaInstrucoes();
    ~FilaInstrucoes();
    void adicionaInstrucao(std::string tipo, int aluno1, int aluno2);
    void processaInstrucoes(Equipe &equipe);
    void imprimeInstrucoes();
    
    
};

#endif