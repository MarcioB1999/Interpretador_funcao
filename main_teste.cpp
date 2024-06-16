using namespace std;
#include "funcao.cpp";

int main(){

    
    lista variaveis_ordem;
    variaveis_ordem.Add('x');
    variaveis_ordem.Add('y');

    
    Funcao func("((x-y)+3)");

    
    double v[] = {4,1};
    //x=4,y=1
    cout<<func.Get_valor(v)<<"\n";

    cout<<"mudando a prioridade das variaveis \n";

    lista variaveis_ordem2;//Agora o y vai ser considerado o primeiro elemento do vetor
    variaveis_ordem2.Add('y');
    variaveis_ordem2.Add('x');

    Funcao func2("((x-y)+3)",&variaveis_ordem2);
    //x=1,y=4
    cout<<"((1-4)+3)"<<func2.Get_valor(v)<<"\n";  

    return 0;
}