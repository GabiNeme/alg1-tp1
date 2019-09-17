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
    
    //Funções para instrução SWAP
    bool possuiCiclo();
    bool procuraCiclo(int i, std::string * estadoVisitacao);
    bool eComandante(int alunoComandado, int alunoComandante);
    bool trocaAresta(int aluno1, int aluno2);


public:
    Equipe();
    void setNumMembros(int numMembros);
    void setIdade(int numIntegrante, int idade);
    bool adicionaRelacao(int quemComanda, int quemEComandado);
    
    
    bool podeTrocarArestas(int aluno1, int aluno2);
    void printHierarquia();
    
};

#endif