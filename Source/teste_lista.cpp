#include "../Header/Lista.h"
using namespace std;
#include <iostream>
//g++ teste_lista.cpp Elemento.cpp Lista.cpp -o teste_lista.exe

int main(){
    lista a;
    a.Add('a');
    a.Add('b');
    a.Add('c');
    a.Add('d');
    a.Percorrer();
    cout<<"tamanho = "<<a.size<<'\n';
    cout<<"irei remover o 1 \n";
    a.RemoverPrimeiro();
    a.Percorrer();
    cout<<"tamanho = "<<a.size<<'\n';
    cout<<"irei remover o 2 \n";
    a.RemoverPrimeiro();
    a.Percorrer();
    cout<<"tamanho = "<<a.size<<'\n';
    cout<<"irei remover o 3 \n";
    a.RemoverPrimeiro();
    a.Percorrer();
    cout<<"tamanho = "<<a.size<<'\n';
    cout<<"irei remover o 4 \n";
    a.RemoverPrimeiro();
    a.Percorrer();
    cout<<"tamanho = "<<a.size<<'\n';
    if(a.comeco == nullptr){
        cout<<"deu certo \n";
    }
    cout<<"colocar tudo de novo \n";
    a.Add('a');
    a.Add('b');
    a.Add('c');
    a.Add('d');
    a.Percorrer();
    cout<<"tamanho = "<<a.size<<'\n';
    cout<<"remover tudo de uma vez so \n";
    a.RemoverTudo();
    if(a.comeco == nullptr){
        cout<<"deu certo \n";
    }
    cout<<"tamanho = "<<a.size<<'\n';
    system("pause");
    return 0;
}