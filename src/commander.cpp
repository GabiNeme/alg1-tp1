#include "commander.h"

Commander::Commander(int aluno){
    this->aluno = aluno;
}
    
void Commander::executaInstrucao(Equipe &equipe){
    
}

void Commander::imprimeInstrucao(){
    std::cout << "C " << aluno + 1 << std::endl;
}