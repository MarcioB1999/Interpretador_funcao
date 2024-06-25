# Interpretador_funcao

Tem como objetivo interpretar e calcular valores de uma expressão, como, $\left(x+y\right)$ ou mesmo $\left(\left(x+y\right)*y\right)^2$. A interpretação fica por meio da criação de uma árvore binária, enquanto a expressão é lida.

<img height="250em" src="https://github.com/MarcioB1999/Interpretador_funcao/blob/main/Imgs/Algoritmo.png"/>

A pra instanciar uma classe, o construtor recebe uma expressão e um ponteiro da estrutura No_lista, que tem como atributos um ponteiro para outro objeto da mesma classe, e um objeto char para representar a variável. Esse ponteiro terá como objetivo informar ao programa a ordem de prioridade das variáveis, em suma, qual a posição da variável no vetor. O único método disponível para se usar pelo usuário e o Get_valor, no qual para valores específicos de variáveis calcula o valor da expressão.

<img height="250em" src="https://github.com/MarcioB1999/Interpretador_funcao/blob/main/Imgs/ReconhecerVariaveis.png"/>

## Get_valor(double *vetor = NULL)
>Argumentos:
>> vetor: Vetor de valores para se calcular a expressão
>Retorno: Valor da expressão para os valores de v


## Obs: 

Toda expressão deve abrir e fechar parênteses

👎Forma Errada: (x+y)^2+x\
👍Forma Correta: ((x+y)^2)+x

Pois como é uma árvore binária, e ainda não se tem nada para se verificar prioridade de operações

Ele tambem não reconhece funções complexas como ln(x), sen(x), tg(x), ...

Algumas imagens podem não condizer totalmente com a atual condição do código, pois eram versões iniciais, mas a ideia geral sim.

## Próxima atualização proposta: 




<ol>
  
<li>
  Quero retirar a comparação com aqueles números todos, que limita também o algoritmo para 23 variáveis. Basta ver que não é uma das operações e ai ver até onde vai os caracteres de letra, ou seja, ver quando se tem o caractere de operação e obtemos tamanho do caractere que representa uma variável, podemos portanto representar uma variável com quantas letras possíveis.
</li>

<li>
  As estruturas auxiliares continuam simples porém com os métodos no qual a estrutura principal precisa. 
</li>
</ol>





