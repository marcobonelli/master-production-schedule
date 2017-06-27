#ifndef S_PRODUTO_H
#define S_PRODUTO_H

#include <vector>
#include <algorithm>

#include <stdio.h>
#include <string.h>

using namespace std;

class PRODUTO{
    int cod_produto;
    int cod_recurso;
    float utilizacao;
    float custo_estoque;

public:

    PRODUTO(int in_cod_produto, int in_cod_recurso, float in_utilizacao, float in_custo_estoque) :
        cod_produto(in_cod_produto),
        cod_recurso(in_cod_recurso),
        utilizacao(in_utilizacao),
        custo_estoque(in_custo_estoque)
    {}

    int GET_cod_produto(){
        return cod_produto;
    }

    int GET_cod_recurso(){
        return cod_recurso;
    }

    float GET_utilizacao(){
        return utilizacao;
    }

    float GET_custo_estoque(){
        return custo_estoque;
    }

    void imprime_dados(){
        cout << "produto: " << this->cod_produto << endl;
        cout << "\trecurso utilizado: " << this->cod_recurso << endl;
        cout << "\tutilizacao do recurso: " << this->utilizacao << endl;
        cout << "\tcusto de estoque: " << this->custo_estoque << endl;
        cout << endl;
    }
};

#endif // S_PRODUTO_H
