#include "equipe.h"

Equipe::Equipe(){
    this->numMembros = 0;
    
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

bool Equipe::podeTrocarArestas(int aluno1, int aluno2){
    //verifica se existe aresta entre esses dois alunos
    //se existe, troca
    if(!trocaAresta(aluno1, aluno2))
        return false;
        
    //verifica se gerou grafo com ciclo
    if(possuiCiclo()){
        //se gerou, reverte arestas
        trocaAresta(aluno1, aluno2);
        return false;
    }
    
    //se não gerou, retorna verdadeiro
    return true;
    
}

bool Equipe::trocaAresta(int aluno1, int aluno2){
    int comandado;
    int comandante;
    
    if(eComandante(aluno1, aluno2)){
        comandado = aluno1;
        comandante = aluno2;
    }else if(eComandante(aluno2, aluno1)){
        comandado = aluno2;
        comandante = aluno1;
    }else{//nenhum comanda nenhum
        return false;
    }
    
    //remove comandante da lista do comandado
    hierarquia[comandado].remove(comandante);
    
    //adiciona ex-comandado na lista do ex-comandante
    hierarquia[comandante].push_back(comandado);
    return true;
}


bool Equipe::possuiCiclo(){
    
    std::string estadoVisitacao[numMembros];
    
    //inicialmente todos os nós não foram visitados 
    for(int i = 0; i < numMembros; i++){
        estadoVisitacao[i] = "Não visitado";
    }
    
    //percorre todos os nós procurando ciclo
    for(int i = 0; i < numMembros; i++){
        if (estadoVisitacao[i] == "Não visitado"){            
            estadoVisitacao[i] = "Visitando";
            if (procuraCiclo(i, estadoVisitacao) == true)
                return true;
        }
    }
    return false;
}


bool  Equipe::procuraCiclo(int i, std::string * estadoVisitacao){
    //percorre lista de comandantes desse aluno
    for(auto comandante: hierarquia[i]){
        if (estadoVisitacao[comandante] == "Visitando"){
            return true;
        }else if (estadoVisitacao[comandante] == "Não visitado"){
            estadoVisitacao[comandante] = "Visitando";
            if (procuraCiclo(comandante, estadoVisitacao) == true)
                return true;
        }
    }
    estadoVisitacao[i] = "Visitado";
    return false;
}



bool Equipe::eComandante(int alunoComandado, int alunoComandante){
    for (auto chefe : hierarquia[alunoComandado]){
        if (chefe == alunoComandante)
            return true;
    }
    return false;
}



int Equipe::chefeMaisNovo(int comandado){
    bool visitado[numMembros];
    
    for(int i = 0; i < numMembros; i++){
        visitado[i] = false;
    }
    
    return menorIdade(comandado, visitado, true);
}


int Equipe::menorIdade(int aluno, bool * visitado, bool ignorarIdade){
    visitado[aluno] = true;
    
    int idadeMin = std::numeric_limits<int>::max();
    if (!ignorarIdade){
        idadeMin = idade[aluno];
    }
    
    int idadeMinHierarquiaSuperior;
    for(auto i : hierarquia[aluno]){
        if(!visitado[i]){
            idadeMinHierarquiaSuperior = menorIdade(i, visitado, false);
            if (idadeMinHierarquiaSuperior < idadeMin )
                idadeMin = idadeMinHierarquiaSuperior;
        }
    }
    return idadeMin;    
}

void Equipe::printHierarquia(){
    for(int i = 0 ; i < numMembros; i++){
        std::cout << i + 1 << " -> ";
        
        for (auto v : hierarquia[i]){
            std::cout << v + 1 << " ";
        }
        
        std::cout << std::endl;
    }
}