#include "leituraEntrada.h"

int main(int argc, char *argv[]){
    
    Equipe equipe;
    
    
    //Verifica entrada
    if (argc >= 2){
        leEntrada(equipe, argv[1]);
    }else{
        std::cout << "Deve ser informado um arquivo *.txt como parâmetro do programa" << std::endl;
    }
    
    equipe.printHierarquia();

    
    return 0;
    
}