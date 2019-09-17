#include "filaInstrucoes.h"

FilaInstrucoes::FilaInstrucoes(){

}

FilaInstrucoes::~FilaInstrucoes(){
    for(auto inst: listaInstrucoes){
        delete inst;
    }
}

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

void FilaInstrucoes::processaInstrucoes(Equipe &equipe){
    
}

void FilaInstrucoes::imprimeInstrucoes(){
    for(auto inst: listaInstrucoes){
        inst->imprimeInstrucao();
    }
}
    