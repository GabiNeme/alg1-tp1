#include "leituraEntrada.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){

    for(int i = 0; i < 100; i++){

    //Medição de tempo de execução
    clock_t tempoInicial;
    clock_t tempoFinal;
    tempoInicial = clock();


    Equipe equipe;
    
    FilaInstrucoes instrucoes;
    
    //Verifica entrada
    if (argc >= 2){
        leEntrada(equipe, instrucoes, argv[1]);
    }else{
        std::cout << "Deve ser informado um arquivo *.txt como parâmetro do programa" << std::endl;
    }
    
    
    instrucoes.processaInstrucoes(equipe);

    tempoFinal = clock();
 
    std::cout << (tempoFinal- tempoInicial) * 1000.0 / CLOCKS_PER_SEC << std::endl;


    }
    return 0;
    
}