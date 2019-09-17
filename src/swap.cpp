#include "swap.h"

Swap::Swap(int aluno1, int aluno2){
    this->aluno1 = aluno1;
    this->aluno2 = aluno2;
}
    
void Swap::executaInstrucao(Equipe &equipe){
    
}

void Swap::imprimeInstrucao(){
    std::cout << "S " << aluno1 + 1 << " " << aluno2 + 1 << std::endl;
}