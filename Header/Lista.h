#include "Elemento.h"

class lista{
    public:
        elemento *comeco;
        elemento *ultimo;

        lista();

        virtual ~lista();

        void Add(char valor);

        void Percorrer();

        void RemoverPrimeiro();

        void RemoverTudo();


};