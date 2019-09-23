#include "meeting.h"

Meeting::Meeting(){
}

/*
 * Imprime o vetor ordem de fala, preenchido pela classe Equipe
 */
void Meeting::executaInstrucao(Equipe &equipe){
    int n = equipe.getNumMembros();
    int vetOrdemFala[n];
    equipe.ordemDeFala(vetOrdemFala);
    std::cout << "M ";
    for (int i = 0; i < n ; i++){
        std::cout << vetOrdemFala[i] << " ";
    }
    std::cout << std::endl;
}

/* 
 * Imprime a instrução meeting (original, como na entrada de dados)
 */
void Meeting::imprimeInstrucao(){
    std::cout << "M"  << std::endl;
}