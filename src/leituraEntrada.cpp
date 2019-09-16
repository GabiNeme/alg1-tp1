#include "leituraEntrada.h"

void leEntrada(Equipe &equipe, std::string nomArquivo){
    
    std::ifstream arqEquipe (nomArquivo); //abre arquivo

    if (arqEquipe.is_open()){
        std::string word;
        
        arqEquipe >> word;
        int N = std::stoi(word); //Número de pessoas no time
        equipe.setNumMembros(N);
        arqEquipe >> word;
        int M = std::stoi(word); //Número de relações diretas
        arqEquipe >> word;
        int I = std::stoi(word); //Número de instruções
        
        //Lê idades
        for(int i = 0; i < N; i++){
            arqEquipe >> word;
            equipe.setIdade(i, std::stoi(word));
        }
        
        //Lê relações
        for(int i = 0; i < M; i++){
            arqEquipe >> word;
            int comanda = std::stoi(word); //Pessoa que comanda
            arqEquipe >> word;
            int eComandado = std::stoi(word); //Pessoa que é comandada
            
            equipe.adicionaRelacao(comanda, eComandado);
        }
        
        //while (arqEquipe >> word){ //obtém cada palavra do arquivo
             
        //}
        arqEquipe.close(); //fecha arquivo
    }else{ //erro caso o arquivo não esteja no local certo
        std::cout << "Arquivo " << nomArquivo << " não encontrado." << std::endl;
        exit(0);
    }
    return;
}


