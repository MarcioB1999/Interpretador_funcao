#include <math.h>
#include <stdlib.h>
#include <string>
#include"funcoes_aux.cpp";
using namespace std;

class Funcao{
    private:
    Arvore_bin arvore;
    lista variaveis;
    char *expressao;

    public:
    Funcao(char *expr,lista *var = nullptr){
        if(var){
            variaveis = *var;
        }else{
            lista *teste = (lista*)calloc(1,sizeof(lista));
            variaveis = *teste;
            
        }

        expressao = expr;
        //cout<<variaveis.comeco;
    };


    double Get_valor(double *vetor){
        No *raiz;
        
        raiz = arvore.Get_raiz();
        if(!raiz){
            
            raiz = arvore.Add_raiz();
            interpretador(expressao,raiz);
        }
        
        return func(raiz, vetor);
    };

    private:
    double func(No *no, double *vetor){

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
            return vetor[stoi(&(no->operacao[1]))];
        }

        return stoi(&(no->operacao[0]));
    };


/*
""=========================================================================================================================""
"" Vai criar a árvore binária responsável por representar a expressão matemática                                           ""
""=========================================================================================================================""
*/                         


    char* interpretador(char *expr, No *no_anterior){
 
        char *string_back_esq;
        No no;
        No *filho_esq,*filho_dir;


        if(expr[0] == '('){
            //verificando se o caractere de agora associado ao no_anterior
            //é o começo de uma expressão ou apenas uma base,
            //caso seja, necessita dois filhos

            filho_esq = arvore.Add_esq(no_anterior, no);
            

            string_back_esq = interpretador(&expr[1],filho_esq);
            no_anterior->operacao = string_back_esq;
            /*
            indo pro lado direito da expressão
            */

            filho_dir = arvore.Add_dir(no_anterior, no);

            /*
            voltou assim +b)+z) contudo pego apenas b)+z)
            pois estou tirando a operação da propria recursao
            */

            return &interpretador(&string_back_esq[1],filho_dir)[1];

        }else{//caso base
            
            return Caso_base(expr,no_anterior);//retorna a expressão restante

        }
        
    };


/*
""=========================================================================================================================""
""                         Metodo de Caso Base                                                                             ""
""=========================================================================================================================""
*/
    char* Caso_base(char *expr, No *no_anterior){
        char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                         'n','o','p','q','r','s','v','u','t','w','x','y','z'};

        if(busca(letras,expr[0],26)){//quer dizer que o elemento representa uma variavel
            

            elemento *elemento_atual = variaveis.comeco;
            

            int qtd = 0;
            while(elemento_atual){//vejo se a variavel ja esta na lista

                if(elemento_atual->caractere == expr[0]){

                    string string_return = "$"+to_string(qtd);
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

            variaveis.Add(expr[0]);
                
            //retornar o qtd+1 do caractere com $
            string string_return = "$"+to_string(qtd);
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
    };

};


