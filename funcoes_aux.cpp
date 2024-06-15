#include <iostream>

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

struct No_lista{
    char caractere;
    No_lista *prox;

    No_lista(char carac='0'){
        prox = nullptr;
        caractere = carac;
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
            raiz = (No*)malloc(sizeof(No));
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

bool busca(char vetor[],char elemento, int tam);

bool busca(char vetor[],char elemento, int tam){

    //26
    for(int i = 0; i<tam; i++){
   
        if(vetor[i] == elemento){
            return true;
        }
    }

    return false;
}
