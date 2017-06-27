#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "s_planejamento.h"
#include "s_produto.h";
#include "s_recurso.h"
#include "function.h"

using namespace std;

int main(){
    int n_produtos, n_recursos, n_periodos;

    leitura_complexidade(n_produtos, n_recursos, n_periodos, "complexidade.txt");

    PLANEJAMENTO plano_producao = PLANEJAMENTO(n_periodos);
    vector<RECURSO> recursos;
    vector<PRODUTO> produtos;

/* realiza leitura dos produtos //*/

    leitura_produtos(produtos, n_produtos, "produto.txt");

/* realiza leitura dos recursos //*/

    leitura_recursos(recursos, n_recursos, n_periodos, "recurso.txt");

/* aloca espaço em memoria e realiza leitura das demandas //*/

    leitura_demanda(plano_producao, n_produtos, n_periodos, "demanda.txt");

/* clona os valores de demanda para os valores de produção //*/

    plano_producao.copia_demanda(n_produtos);

/* imprime classe [demanda, recursos, produtos] para conferencia //*/

    plano_producao.imprime_dados(n_produtos);

    for(int recurso = 0; recurso < n_recursos; recurso++)
        recursos[recurso].imprime_dados(n_periodos);

    for(int produto = 0; produto < n_produtos; produto++)
        produtos[produto].imprime_dados();

/* calcula utilização dos recursos baseado na demanda //*/

    for(int periodo = n_periodos; periodo > 0; periodo--)
        for(int recurso = 0; recurso < n_recursos; recurso++)
            recursos[recurso].SET_cap_utilizada(produtos, plano_producao.captura_prod_periodo(periodo, n_produtos), periodo, n_produtos);

/* imprime classe [recursos] para conferencia //*/

    for(int recurso = 0; recurso < n_recursos; recurso++)
        recursos[recurso].imprime_dados(n_periodos);

/* retorna o primeiro mes encontrado que extrapola a capacidade de produção //*/

    for(int recurso = 0; recurso < n_recursos; recurso++){
        cout << "recurso: " << recursos[recurso].GET_cod_recurso() << " -> " << recursos[recurso].extra_capacidade(n_periodos) << endl;
    }

    return 0;
}
