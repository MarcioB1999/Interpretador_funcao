#include "../Header/Arvore_bin.h"
#include <iostream>

Arvore_bin::Arvore_bin(): raiz(nullptr) {}


No* Arvore_bin::Get_raiz(){
    return this->raiz;
};

No* Arvore_bin::Add_raiz(){
    if(this->raiz == nullptr){
        this->raiz = new No();
    }
    return raiz;
};

No* Arvore_bin::Add_esq(No *pai, No no){
    //alocando dinamicamente o PONTEIRO
    pai->prox_esq = new No();
    pai->prox_esq[0] = no;
    return pai->prox_esq;
};

No* Arvore_bin::Add_dir(No *pai, No no){
    pai->prox_dir = new No();
    pai->prox_dir[0] = no;
    return pai->prox_dir;
}

