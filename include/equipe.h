#ifndef EQUIPE_H
#define HIERARQUIA_H
#include <iostream>
#include <vector>
#include <list>

class Equipe{
    
private:
    int numMembros;
    //Aresta vai de quem é comandado para quem comanda
    std::vector<std::list<int>> hierarquia;
    
    std::vector<int> idade;

public:
    Equipe();
    void setNumMembros(int numMembros);
    void setIdade(int numIntegrante, int idade);
    bool adicionaRelacao(int quemComanda, int quemEComandado);
    
    void printHierarquia();
    
};

#endif