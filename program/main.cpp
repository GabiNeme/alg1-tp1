#include <iostream>
#include "hierarquia.h"

int main(int argc, char *argv[]){
    
    //Verifica entrada
    if (argc >= 2){
        std::cout << argv[1] << std::endl;
    }else{
        std::cout << "Deve ser informado um arquivo *.txt como parâmetro do programa" << std::endl;
    }
    
    Hierarquia a(10);
    a.adicionaRelacao(9,1);
    
    return 0;
    
}