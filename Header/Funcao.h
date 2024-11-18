#include"..\Estrutura_De_Dados\Header\Lista.h"
#include"..\Estrutura_De_Dados\Header\Arvore_bin.h"

class Funcao{
    private:
    Arvore_bin arvore;
    lista variaveis;
    char *expressao;

    public:
    Funcao(char *expr, lista *var = nullptr);

    void Interpretar();

    double Get_valor(double *vetor);

    No* Get_raiz();

    int Get_dimensao();

    private:
    double func(No *no, double *vetor);                       

    char* interpretador(char *expr, No *no_anterior);

    char* Caso_base(char *expr, No *no_anterior);

    bool busca(char vetor[],char elemento, int tam);
};