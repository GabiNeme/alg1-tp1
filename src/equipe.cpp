#include "equipe.h"

Equipe::Equipe(){

}


void Equipe::setNumMembros(int numMembros){
    this->numMembros = numMembros;
    hierarquia.resize(numMembros);
    idade.resize(numMembros);
}


void Equipe::setIdade (int numIntegrante, int idade){
    this->idade[numIntegrante] = idade;
}


bool Equipe::adicionaRelacao(int quemComanda, int quemEComandado){
    if (quemComanda < numMembros && quemEComandado < numMembros){
        hierarquia[quemEComandado].push_back(quemComanda);
        return true;
    }
    return false;
}


void Equipe::printHierarquia(){
    for(int i = 0 ; i < numMembros; i++){
        std::cout << i << " -> ";
        
        for (auto v : hierarquia[i]){
            std::cout << v << " ";
        }
        
        std::cout << std::endl;
    }
}