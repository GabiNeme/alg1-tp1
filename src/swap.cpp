#include "swap.h"

Swap::Swap(int aluno1, int aluno2){
    this->aluno1 = aluno1;
    this->aluno2 = aluno2;
}

/*
 * Imprime se foi possível ou não executar a troca
 */
void Swap::executaInstrucao(Equipe &equipe){
    if(equipe.podeTrocarArestas(aluno1, aluno2)){
        std::cout << "S T" << std::endl;
    }else{
        std::cout << "S N" << std::endl;
        
    }
}

/* 
 * Imprime a instrução swap (original, como na entrada de dados)
 */
void Swap::imprimeInstrucao(){
    std::cout << "S " << aluno1 + 1 << " " << aluno2 + 1 << std::endl;
}