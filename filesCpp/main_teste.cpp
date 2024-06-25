using namespace std;
#include <iostream>
#include "..\Header\Funcao.h"

void PercorrerArvore(No *no,double *vetor);
//comando para gerar o executável e testar
//g++ main_teste.cpp Funcao.cpp Elemento.cpp Arvore_bin.cpp Lista.cpp No.cpp -o teste.exe


int main(){
    string expr("(((x+y)^(1/2))+((5*x)+y))");
    char expressao[] = "(((x+y)^(1/2))+((5*x)+y))";
    char *i = expressao;//(char*)malloc(2*sizeof(char));
    cout<<"expressao = "<<expressao<<"\n";

    cout<<"ordem = (x=4,y=1)"<<"\n";
    lista variaveis_ordem;
    variaveis_ordem.Add('x');
    variaveis_ordem.Add('y');

    
    Funcao func(i,&variaveis_ordem);

    
    double v[] = {4,1};
    //x=4,y=1
    func.Interpretar();
    PercorrerArvore(func.Get_raiz(),v);
    //cout<<"operacao do filho esq = "<<func.Get_raiz()->prox_esq->operacao[0];
    cout<<" = "<<func.Get_valor(v)<<"\n";
    
    cout<<"mudando a ordem das variaveis \n";

    cout<<"ordem = (x=1,y=4)"<<"\n";

    lista variaveis_ordem2;//Agora o y vai ser considerado o primeiro elemento do vetor
    variaveis_ordem2.Add('y');
    variaveis_ordem2.Add('x');

    Funcao func2(i,&variaveis_ordem2);
    //x=1,y=4
    func2.Interpretar();
    PercorrerArvore(func2.Get_raiz(),v);
    //cout<<"operacao do filho esq = "<<func.Get_raiz()->prox_esq->operacao[0];
    cout<<" = "<<func2.Get_valor(v)<<"\n";

    system("pause");
    return 0;
};


void PercorrerArvore(No *no, double *vetor){
    if(no->prox_esq){
        cout<<'(';
        PercorrerArvore(no->prox_esq,vetor);
        cout<<no->operacao[0];
        PercorrerArvore(no->prox_dir,vetor);
        cout<<')';
        return ;
    }else{
        if(no->operacao[0] == '$'){
            cout<<vetor[std::stoi(&(no->operacao[1]))];
        }else{
            cout<<no->operacao[0];
        }
        return ;
    };
};