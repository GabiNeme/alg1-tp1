#include "swap.h"

Swap::Swap(int aluno1, int aluno2){
    this->aluno1 = aluno1;
    this->aluno2 = aluno2;
}
    
void Swap::executaInstrucao(Equipe &equipe){
    if(equipe.podeTrocarArestas(aluno1, aluno2)){
        //std::cout << "S T" << std::endl;
    }else{
        //std::cout << "S N" << std::endl;
        
    }
}

void Swap::imprimeInstrucao(){
    std::cout << "S " << aluno1 + 1 << " " << aluno2 + 1 << std::endl;
}