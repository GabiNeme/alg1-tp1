#include "equipe.h"

Equipe::Equipe(){
    this->numMembros = 0;
}


void Equipe::setNumMembros(int numMembros){
    this->numMembros = numMembros;
    hierarquia.resize(numMembros);
    idade.resize(numMembros);
}

int Equipe::getNumMembros(){
    return this->numMembros;
}

void Equipe::setIdade (int numIntegrante, int idade){
    this->idade[numIntegrante] = idade;
}


bool Equipe::adicionaRelacao(int quemComanda, int quemEComandado){
    //aresta vai de quem é comandado para quem comanda
    if (quemComanda < numMembros && quemEComandado < numMembros){
        hierarquia[quemEComandado].push_back(quemComanda);
        return true;
    }
    return false;
}

/* Verifica se pode trocar arestas
 * Condição 1: existe aresta entre esses vértices
 * Condição 2: a troca não gera um ciclo
 */
bool Equipe::podeTrocarArestas(int aluno1, int aluno2){
    //verifica se existe aresta entre esses dois alunos
    //se existe, troca
    if(!trocaAresta(aluno1, aluno2))
        return false;
        
    //verifica se gerou grafo com ciclo
    if(possuiCiclo()){
        //se tem ciclo, reverte arestas
        trocaAresta(aluno1, aluno2);
        return false;
    }
    
    //se não gerou, retorna verdadeiro
    return true;
    
}

/*
 * Inverte a aresta de A -> B para B -> A ou vice versa, caso exista aresta
 * de A para B ou de B para A
 * 
 */
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


/*
 * Verifica se o grafo possui ciclo
 */
bool Equipe::possuiCiclo(){
    
    std::string estadoVisitacao[numMembros];
    
    //inicialmente nenhum nó foi visitado
    for(int i = 0; i < numMembros; i++){
        estadoVisitacao[i] = "Não visitado";
    }
    
    //percorre todos os nós procurando ciclo
    for(int i = 0; i < numMembros; i++){
        if (estadoVisitacao[i] == "Não visitado"){            
            estadoVisitacao[i] = "Visitando"; //
            if (procuraCiclo(i, estadoVisitacao) == true)
                return true;
        }
    }
    return false;
}


bool  Equipe::procuraCiclo(int i, std::string * estadoVisitacao){
    //percorre lista de comandantes desse aluno
    for(auto comandante: hierarquia[i]){
        //Se encontrou um nó no estado "visitando" significa que um ciclo foi encontrado
        if (estadoVisitacao[comandante] == "Visitando"){
            return true;
        }else if (estadoVisitacao[comandante] == "Não visitado"){ //se nó não foi visitado, visita
            estadoVisitacao[comandante] = "Visitando";
            if (procuraCiclo(comandante, estadoVisitacao) == true)
                return true;
        }
    }
    estadoVisitacao[i] = "Visitado";
    return false;
}


/*
 * Dado um aluno comandado, verifica se um aluno x é seu comandante
 */
bool Equipe::eComandante(int alunoComandado, int alunoComandante){
    for (auto chefe : hierarquia[alunoComandado]){
        if (chefe == alunoComandante)
            return true;
    }
    return false;
}


/*
 * Identifica o chefe mais novo do aluno passado como parâmetro
 */
int Equipe::chefeMaisNovo(int comandado){
    
    //inicialmente nenhum vértice foi visitado
    bool visitado[numMembros];
    
    for(int i = 0; i < numMembros; i++){
        visitado[i] = false;
    }
    
    return menorIdade(comandado, visitado, true);
}


int Equipe::menorIdade(int aluno, bool * visitado, bool ignorarIdade){
    //vértice foi atingido
    visitado[aluno] = true;
    
    int idadeMin = std::numeric_limits<int>::max(); //idade mínima é, inicialmente, o máximo possível
    
    /*
     * não se pode considerar a idade do aluno para o qual a função "chefe mais novo" foi chamada
     * pois ele não é chefe dele mesmo
     */
    if (!ignorarIdade){ 
        idadeMin = idade[aluno];
    }
    
    int idadeMinHierarquiaSuperior;
    //para cada chefe do aluno atual
    for(auto i : hierarquia[aluno]){
        if(!visitado[i]){ //se ele não foi visitado
            //apura a idade mínima
            idadeMinHierarquiaSuperior = menorIdade(i, visitado, false);
            //se for menor que a idade mínima atual, atualiza
            if (idadeMinHierarquiaSuperior < idadeMin )
                idadeMin = idadeMinHierarquiaSuperior;
        }
    }
    //retorna idade mínima encontrada
    return idadeMin;    
}


/*
 * Retorna no vetorOrdemFala a ordem de fala respeitando o fato que 
 * chefes devem falar antes de seus subordinados
 */
void Equipe::ordemDeFala(int *vetorOrdemFala){
    bool visitado[numMembros];
    int posVetOrdem = 0;
    
    //inicialmente nenhum vértice foi visitado
    for(int i = 0; i < numMembros; i++){
        visitado[i] = false;
    }

    //para cada vértice do gráfico
    for(int i = 0; i < numMembros; i++){
        if (visitado[i] == false){
            momentoFinalizacao(i, posVetOrdem, vetorOrdemFala, visitado);
        }
    }   
}

/*
 * Cria uma ordem topológica reversa que adiciona o vértice "aluno" à posição posVetOrdem do vetorOrdemFala,
 * em ordem crescente de tempo de finalização, já que o presente grafo vai de comandados -> comandantes
 */
void Equipe::momentoFinalizacao(int aluno, int &posVetOrdem, int *vetorOrdemFala, bool *visitado){
    visitado[aluno] = true;

    for(auto i : hierarquia[aluno]){
        if(visitado[i] == false){
            momentoFinalizacao(i, posVetOrdem, vetorOrdemFala, visitado);
        }
    }
    vetorOrdemFala[posVetOrdem] = aluno + 1;
    posVetOrdem +=  1;

}

/*
 * Função que imprime a hierarquia dessa equipe
 */
void Equipe::printHierarquia(){
    for(int i = 0 ; i < numMembros; i++){
        std::cout << i  << " -> ";
        
        for (auto v : hierarquia[i]){
            std::cout << v  << " ";
        }
        
        std::cout << std::endl;
    }
}