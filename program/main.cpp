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
    
    //equipe.printHierarquia();
    //std::cout << std::endl;
    //instrucoes.imprimeInstrucoes();
    
    
    return 0;
    
}