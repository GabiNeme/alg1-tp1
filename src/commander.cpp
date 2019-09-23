#include "commander.h"

Commander::Commander(int aluno){
    this->aluno = aluno;
}

/*
 * Encontra o chefe mais novo do aluno x, na equipe passada como parâmetro
 */
void Commander::executaInstrucao(Equipe &equipe){
    int idade = equipe.chefeMaisNovo(aluno); 

    if (idade == std::numeric_limits<int>::max()){
        std::cout << "C *" << std::endl;
    }else{
        std::cout << "C " << equipe.chefeMaisNovo(aluno) << std::endl;
    }
}

/* 
 * Imprime a instrução commander (original, como na entrada de dados)
 */
void Commander::imprimeInstrucao(){
    std::cout << "C " << aluno + 1 << std::endl;
}