#ifndef S_PLANEJAMENTO_H
#define S_PLANEJAMENTO_H

#include <vector>
#include <algorithm>

#include <stdio.h>
#include <string.h>

using namespace std;

class PLANEJAMENTO{
    int * dem_periodo = NULL;
    int * prod_periodo = NULL;
    int * est_periodo = NULL;
    int n_periodos;

public:

    PLANEJAMENTO(int in_n_periodos) :
        n_periodos(in_n_periodos)
    {}

    void aloca_memoria(int n_produtos){
        dem_periodo = new int[(n_produtos + 1) * (n_periodos + 1)];
        prod_periodo = new int[(n_produtos + 1) * (n_periodos + 1)];
        est_periodo = new int[(n_produtos + 1) * (n_periodos + 1)];

        memset(dem_periodo, 0, (n_produtos + 1) * (n_periodos + 1) * sizeof(int));
        memset(prod_periodo, 0, (n_produtos + 1) * (n_periodos + 1) * sizeof(int));
        memset(est_periodo, 0, (n_produtos + 1) * (n_periodos + 1) * sizeof(int));
    }

    void SET_dem_periodo(int in_dem_periodo, int in_cod_produto, int periodo){
        dem_periodo[in_cod_produto * (n_periodos + 1) + (periodo + 1)] = in_dem_periodo;
    }

    void SET_prod_periodo(int in_prod_periodo, int in_cod_produto, int periodo){
        prod_periodo[in_cod_produto * (n_periodos + 1) + (periodo + 1)] = in_prod_periodo;
    }

    int GET_dem_periodo(int produto, int periodo){
        return dem_periodo[produto * (n_periodos + 1) + (periodo)];
    }

    int GET_prod_periodo(int produto, int periodo){
        return prod_periodo[produto * (n_periodos + 1) + (periodo)];
    }

    void copia_demanda(int n_produtos){
        for(int contador = 0; contador < (n_produtos + 1) * (n_periodos + 1); contador++)
            prod_periodo[contador] = dem_periodo[contador];
    }

    vector<int> captura_prod_periodo(int periodo, int n_produtos){
        vector<int> out_prod_periodo(n_produtos + 1);
        for(int produto = 1; produto < (n_produtos + 1); produto++)
            out_prod_periodo[produto] = prod_periodo[produto * (n_periodos + 1) + (periodo)];

        return out_prod_periodo;
    }

    void imprime_dados(int n_produtos){
        for(int produto = 1; produto < n_produtos + 1; produto++){
            cout << "demanda do produto " << produto << ": ";
            for(int periodo = 1; periodo < n_periodos + 1; periodo++)
                cout << this->GET_prod_periodo(produto, periodo) << " ";
            cout << endl;
        }

        cout << endl;
    }
};

#endif // S_PLANEJAMENTO_H
