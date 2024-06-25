#include "No.h"

class Arvore_bin{
    private:
        No *raiz;

    
    public:
        Arvore_bin();

        No* Get_raiz();

        No* Add_raiz();

        No* Add_esq(No *pai, No no);

        No* Add_dir(No *pai, No no);
};
