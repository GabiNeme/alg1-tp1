#include "filaInstrucoes.h"

FilaInstrucoes::FilaInstrucoes(){

}

FilaInstrucoes::~FilaInstrucoes(){
    //desaloca memória
    for(auto inst: listaInstrucoes){
        delete inst;
    }
}

/*
 * Cria instrução e adiciona à fila
 */
void FilaInstrucoes::adicionaInstrucao(std::string tipo, int aluno1, int aluno2){
    if(tipo == "S"){
        Swap * instrucao = new Swap(aluno1, aluno2);
        listaInstrucoes.push_back(instrucao);
    }else if(tipo == "C"){
        Commander * instrucao = new Commander(aluno1);
        listaInstrucoes.push_back(instrucao);
    }else if(tipo == "M"){
        Meeting * instrucao = new Meeting();
        listaInstrucoes.push_back(instrucao);
    }
}

/*
 * Para cada instrução da fila, executa para a Equipe passada como parâmetro do método
 */
void FilaInstrucoes::processaInstrucoes(Equipe &equipe){
    for(auto inst: listaInstrucoes){
        inst->executaInstrucao(equipe);
    }
}


/*
 * Imprime instruções originais (como foram inseridas na entrada de dados)
 */
void FilaInstrucoes::imprimeInstrucoes(){
    for(auto inst: listaInstrucoes){
        inst->imprimeInstrucao();
    }
}
    