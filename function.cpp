#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "s_planejamento.h"
#include "s_produto.h";
#include "s_recurso.h"
#include "function.h"

void leitura_produtos(vector<PRODUTO> &produtos, int n_produtos, char arquivo[]){
    int in_cod_produto, in_cod_recurso;
    float in_utilizacao, in_custo_estoque;

    ifstream file_produtos(arquivo);

    for(int contador = 0; contador < n_produtos; contador++){
        file_produtos >> in_cod_produto >> in_cod_recurso >> in_utilizacao >> in_custo_estoque;
        produtos.push_back(PRODUTO(in_cod_produto, in_cod_recurso, in_utilizacao, in_custo_estoque));
    }

    file_produtos.close();
}

void leitura_recursos(vector<RECURSO> &recursos, int n_recursos, int n_periodos, char arquivo[]){
    int in_cod_recurso;
    float in_cap_maxima;

    ifstream file_recursos(arquivo);

    for(int contador = 0; contador < n_recursos; contador++){
        file_recursos >> in_cod_recurso;
        recursos.push_back(RECURSO(in_cod_recurso, n_periodos));
        for(int periodo = 0; periodo < n_periodos; periodo++){
            file_recursos >> in_cap_maxima;
            recursos[contador].SET_cap_maxima(in_cap_maxima, periodo + 1);
        }
    }

    file_recursos.close();
}

void leitura_demanda(PLANEJAMENTO &plano_producao, int n_produtos, int n_periodos, char arquivo[]){
    int in_cod_produto, in_dem_periodo;

    ifstream file_demandas(arquivo);

    plano_producao.aloca_memoria(n_produtos);

    for(int produto = 0; produto < n_produtos; produto++){
        file_demandas >> in_cod_produto;
        for(int periodo = 0; periodo < n_periodos; periodo++){
            file_demandas >> in_dem_periodo;
            plano_producao.SET_dem_periodo(in_dem_periodo, in_cod_produto, periodo);
        }
    }

    file_demandas.close();
}

void leitura_complexidade(int &n_produtos, int &n_recursos, int &n_periodos, char arquivo[]){
    ifstream file_complexidade(arquivo);

    file_complexidade >> n_produtos >> n_recursos >> n_periodos;

    file_complexidade.close();
}
