#include "leituraEntrada.h"

int main(int argc, char *argv[]){
    
    Equipe equipe;
    
    FilaInstrucoes instrucoes;
    
    //Verifica entrada
    if (argc >= 2){
        leEntrada(equipe, instrucoes, argv[1]);
    }else{
        std::cout << "Deve ser informado um arquivo *.txt como parâmetro do programa" << std::endl;
    }
    
    
    instrucoes.processaInstrucoes(equipe);
    /*
    equipe.printHierarquia();
    std::cout << "Possui ciclo " << equipe.possuiCiclo() << std::endl;
    equipe.trocaAresta(3,6);
    std::cout << std::endl;
    equipe.printHierarquia();
    std::cout << "Possui ciclo " << equipe.possuiCiclo() << std::endl;
    */
    //std::cout << std::endl;
    //instrucoes.imprimeInstrucoes();
    
    //std::cout << equipe.possuiCiclo() << std::endl;
    
    return 0;
    
}