#include "hierarquia.h"

Hierarquia::Hierarquia(int numMembros){
    this->numMembros = numMembros;
    relacao.resize(numMembros);
}

void Hierarquia::adicionaRelacao(int quemComanda, int quemEComandado){
    relacao[quemEComandado].push_back(quemComanda);
}