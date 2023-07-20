using namespace std;
#include "funcao.cpp";

int main(){
    
    
    Funcao func("((x-y)^2)");

    double v[] = {4,1};
    cout<<func.Get_valor(v)<<"\n";

    cout<<"mudando a prioridade das variaveis \n";

    No_lista elemento1('y');//Agora o y vai ser considerado o primeiro elemento do vetor
    No_lista elemento2('x');
    elemento1.prox = &elemento2;

    Funcao func2("(x-y)",&elemento1);

    cout<<func2.Get_valor(v)<<"\n";  


    return 0;
}