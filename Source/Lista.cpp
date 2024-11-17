#include "../Header/Lista.h"
using namespace std;
#include <iostream>

lista::lista(): comeco(nullptr), ultimo(nullptr) {}

lista::~lista(){
    this->RemoverTudo();
    delete this->comeco;
}

void lista::Add(char valor){
    elemento *new_elemento {new elemento()};

    new_elemento->caractere = valor;
    if(this->comeco != nullptr){
        this->ultimo->prox = new_elemento;
        this->ultimo = new_elemento;
    }else{
        this->comeco = ultimo = new_elemento;
    }
}


void lista::Percorrer(){
    elemento *aux {comeco}; 
    while(aux != nullptr){
        cout<<aux->caractere;
        aux = aux->prox;
    }
}


void lista::RemoverPrimeiro(){
    elemento* aux {this->comeco->prox};
    delete this->comeco;
    this->comeco = aux;

}



void lista::RemoverTudo(){
    while(this->comeco != nullptr){
        this->RemoverPrimeiro();
    }
}