#include "meeting.h"

Meeting::Meeting(){
}
    
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

void Meeting::imprimeInstrucao(){
    std::cout << "M"  << std::endl;
}