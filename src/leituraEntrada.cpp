#include "leituraEntrada.h"

void leEntrada(Equipe &equipe, FilaInstrucoes & instrucoes, std::string nomArquivo){
    
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
            int comanda = std::stoi(word) - 1; //Pessoa que comanda
            arqEquipe >> word;
            int eComandado = std::stoi(word)-1; //Pessoa que é comandada
            
            equipe.adicionaRelacao(comanda, eComandado);
        }
        
        //Lê instruções
        for(int i = 0; i < I; i++){
            arqEquipe >> word;
            std::string tipo = word; //tipo instrucao
            int aluno1 = -1;
            int aluno2 = -1;
            
            if (tipo != "M"){
                arqEquipe >> word;
                aluno1 = std::stoi(word)-1; //primeiro numero (todas as instrucoes tem)

                if (tipo == "S"){
                    arqEquipe >> word;
                    aluno2 = std::stoi(word)-1; 
                }
            }
            instrucoes.adicionaInstrucao(tipo, aluno1, aluno2);
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

