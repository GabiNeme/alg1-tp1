#include "commander.h"

Commander::Commander(int aluno){
    this->aluno = aluno;
}
    
void Commander::executaInstrucao(Equipe &equipe){
    int idade = equipe.chefeMaisNovo(aluno); 

    if (idade == std::numeric_limits<int>::max()){
        std::cout << "C *" << std::endl;
    }else{
        std::cout << "C " << equipe.chefeMaisNovo(aluno) << std::endl;
    }
}

void Commander::imprimeInstrucao(){
    std::cout << "C " << aluno + 1 << std::endl;
}