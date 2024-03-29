#ifndef EQUIPE_H
#define HIERARQUIA_H
#include <iostream>
#include <vector>
#include <list>
#include <limits>

class Equipe{
    
private:
    int numMembros;
    //Aresta vai de quem é comandado para quem comanda
    //Exemplo, se A comanda B, existe uma aresta de B para A
    std::vector<std::list<int>> hierarquia;
    
    std::vector<int> idade;
    
    //Funções para instrução SWAP
    bool possuiCiclo();
    bool procuraCiclo(int i, std::string * estadoVisitacao);
    bool eComandante(int alunoComandado, int alunoComandante);
    bool trocaAresta(int aluno1, int aluno2);
    
    //Funções para instrução COMMANDER
    int getIdade(int numIntegrante);
    int menorIdade(int aluno, bool * visitado, bool ignorarIdade);

    //Funções para instrução MEETING
    void momentoFinalizacao(int aluno, int &posVetOrdem, int *vetorOrdemFala, bool *visitado);


public:
    Equipe();
    void setNumMembros(int numMembros);
    int getNumMembros();
    void setIdade(int numIntegrante, int idade);
    bool adicionaRelacao(int quemComanda, int quemEComandado);
    
    
    bool podeTrocarArestas(int aluno1, int aluno2);
    int chefeMaisNovo(int comandado);
    void ordemDeFala(int *vetorOrdemFala);
    
    void printHierarquia();
    
};

#endif