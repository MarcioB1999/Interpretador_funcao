#include <math.h>
#include <stdlib.h>
#include <string>
#include "../Header/Funcao.h"

Funcao::Funcao(char *expr, lista *var = nullptr){
    
    if(var){
        this->variaveis = *var;
    }else{
        lista *teste = (lista*)calloc(1,sizeof(lista));
        this->variaveis = *teste;  
    }

    this->expressao = expr;
}


No* Funcao::Get_raiz(){
    return this->arvore.Get_raiz();
}


void Funcao::Interpretar(){
    interpretador(this->expressao,this->arvore.Add_raiz());
}


double Funcao::Get_valor(double *vetor){
    
    return func(this->arvore.Get_raiz(), vetor);
}


double Funcao::func(No *no, double *vetor){

    if(no->operacao[0] == '-'){
        return func(no->prox_esq,vetor)-func(no->prox_dir,vetor);
    }
    if(no->operacao[0] == '+'){
        return func(no->prox_esq,vetor)+func(no->prox_dir,vetor);
    }
    if(no->operacao[0] == '/'){
        return func(no->prox_esq,vetor)/func(no->prox_dir,vetor);
    }
    if(no->operacao[0] == '*'){
        return func(no->prox_esq,vetor)*func(no->prox_dir,vetor);
    }
    if(no->operacao[0] == '^'){
        return pow(func(no->prox_esq,vetor),func(no->prox_dir,vetor));
    }
    if(no->operacao[0] == '$'){
        return vetor[std::stoi(&(no->operacao[1]))];
    }

    return std::stoi(&(no->operacao[0]));
}



char* Funcao::interpretador(char *expr, No *no_anterior){

    char *string_back_esq;
    No no;
    No *filho_esq,*filho_dir;


    if(expr[0] == '('){
        //verificando se o caractere de agora associado ao no_anterior
        //é o começo de uma expressão ou apenas uma base,
        //caso seja, necessita dois filhos

        filho_esq = this->arvore.Add_esq(no_anterior, no);
        

        string_back_esq = interpretador(&expr[1],filho_esq);
        no_anterior->operacao = string_back_esq;
        /*
        indo pro lado direito da expressão
        */

        filho_dir = this->arvore.Add_dir(no_anterior, no);

        /*
        voltou assim +b)+z) contudo pego apenas b)+z)
        pois estou tirando a operação da propria recursao
        */

        return &interpretador(&string_back_esq[1],filho_dir)[1];

    }else{//caso base
        
        return Caso_base(expr,no_anterior);//retorna a expressão restante

    }
    
}



char* Funcao::Caso_base(char *expr, No *no_anterior){
    char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                        'n','o','p','q','r','s','v','u','t','w','x','y','z'};

    if(busca(letras,expr[0],26)){//quer dizer que o elemento representa uma variavel
        

        elemento *elemento_atual = this->variaveis.comeco;
        

        int qtd = 0;
        while(elemento_atual){//vejo se a variavel ja esta na lista

            if(elemento_atual->caractere == expr[0]){

                std::string string_return = "$"+std::to_string(qtd);
                char *char_op = (char*)malloc(string_return.length()*sizeof(char));
                for(int i=0;i<string_return.length();i++){
                    
                    char_op[i] = string_return[i];
                }
                no_anterior->operacao = char_op;
                    return &expr[1];//retorna a posição do caractere no vetor de variaveis com $.
                                //Pois irá facilitar na hora de acessar a posição
            }
            elemento_atual = elemento_atual->prox;
            qtd++;
        }
        //n esta na lista

        this->variaveis.Add(expr[0]);
            
        //retornar o qtd+1 do caractere com $
        std::string string_return = "$"+std::to_string(qtd);
        char *char_op = (char*)malloc(string_return.length()*sizeof(char));
        for(int i=0;i<string_return.length();i++){
            
            char_op[i] = string_return[i];
        }
        no_anterior->operacao = char_op;
        
        
        return &expr[1];
    }//se n, ele é um numero e temos que saber o tamanho dele
    char operacoes[] = {'-','+','/','*','^'};
    int qtd = -1;
    do{
        
        qtd++;
    }while(!busca(operacoes,expr[qtd],5) && expr[qtd]!=')' );
    char *num = (char*)malloc((qtd+1)*sizeof(char));
    for(int i = 0; i<=qtd; i++){
        num[i] = expr[i];
    }
    no_anterior->operacao = num;

    return &expr[qtd];
}

bool Funcao::busca(char vetor[],char elemento, int tam){

    //26
    for(int i = 0; i<tam; i++){
   
        if(vetor[i] == elemento){
            return true;
        }
    }

    return false;
}