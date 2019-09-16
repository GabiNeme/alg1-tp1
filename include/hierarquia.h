#ifndef HIERARQUIA_H
#define HIERARQUIA_H
#include <iostream>
#include <vector>
#include <list>

class Hierarquia{
    
private:
    int numMembros;
    //Aresta vai de quem é comandado para quem comanda
    std::vector<std::list<int>> relacao;

public:
    Hierarquia(int numMembros);
    void adicionaRelacao(int quemComanda, int quemEComandado);
    
};

#endif