#include "../Header/Lista.h"
#include <iostream>

lista::lista(){
    comeco = nullptr;
    ultimo = nullptr;
}

void lista::Add(char valor){
    elemento *new_elemento = new elemento();

    new_elemento->caractere = valor;
    if(comeco){
        this->ultimo->prox = new_elemento;
        this->ultimo = new_elemento;
    }else{
        this->comeco = ultimo = new_elemento;
    }
}