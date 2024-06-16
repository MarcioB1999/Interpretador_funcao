#include <iostream>
#include <stdexcept>

bool busca(char vetor[],char elemento, int tam){

    //26
    for(int i = 0; i<tam; i++){
   
        if(vetor[i] == elemento){
            return true;
        }
    }

    return false;
}

//structs

struct No{
    char *operacao;
    No *prox_dir;
    No *prox_esq;

    No(){
        operacao = nullptr;
        prox_dir = nullptr;
        prox_esq = nullptr;
    }
};

struct elemento{
    char caractere;
    elemento *prox;

    elemento(){
        caractere='a';
        prox = nullptr;
    }
};

struct lista{

    elemento *comeco;
    elemento *ultimo;

    lista(){
        comeco = nullptr;
        ultimo = nullptr;
    }

    void Add(char valor){
        elemento *new_elemento = (elemento*)malloc(sizeof(elemento));
        elemento instanciado;
        *new_elemento = instanciado;
        new_elemento->caractere = valor;
        if(comeco){
            ultimo->prox = new_elemento;
            ultimo = new_elemento;
        }else{
            comeco = ultimo = new_elemento;
        }

    }
};

struct Arvore_bin{
    No *raiz;

    Arvore_bin(){
        raiz = nullptr;
    }
    
    public:
    No* Get_raiz(){
        return raiz;
    }

    No* Add_raiz(){
        if(raiz == NULL){
            No instanciado;
            raiz = (No*)malloc(sizeof(No));
            *raiz = instanciado;
        }
        return raiz;
    }

    No* Add_esq(No *pai, No no){
        //alocando dinamicamente o PONTEIRO
        pai->prox_esq = (No*) malloc(sizeof(No));

        //Fazendo que o valor no qual meu ponteiro aponta receba um no
        pai->prox_esq[0] = no;
        return pai->prox_esq;
    }

    No* Add_dir(No *pai, No no){
        pai->prox_dir = (No*) malloc(sizeof(No));
        pai->prox_dir[0] = no;
        return pai->prox_dir;
    }
};
