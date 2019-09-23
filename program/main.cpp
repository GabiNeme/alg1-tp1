#include "leituraEntrada.h"

int main(int argc, char *argv[]){

    //cria equipe
    Equipe equipe;
    
    //cria fila de instruções
    FilaInstrucoes instrucoes;
    
    //Verifica entrada
    if (argc >= 2){
        leEntrada(equipe, instrucoes, argv[1]);
    }else{
        std::cout << "Deve ser informado um arquivo *.txt como parâmetro do programa" << std::endl;
    }
    
    //processa instruções
    instrucoes.processaInstrucoes(equipe);

    return 0;
    
}