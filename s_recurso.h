#ifndef S_RECURSO_H
#define S_RECURSO_H

#include <vector>
#include <algorithm>

#include <stdio.h>
#include <string.h>

using namespace std;

class RECURSO{
    int cod_recurso;
    float * cap_maxima;
    float * cap_utilizada;

public:

    RECURSO(int in_cod_recurso, int n_periodos) :
        cod_recurso(in_cod_recurso)
    {
        cap_maxima = new float[n_periodos + 1];
        cap_utilizada = new float[n_periodos + 1];

        memset(cap_maxima, 0, (n_periodos + 1) * sizeof(float));
        memset(cap_utilizada, 0, (n_periodos + 1) * sizeof(float));
    }

    int GET_cod_recurso(){
        return cod_recurso;
    }

    float GET_cap_maxima(int periodo){
        return cap_maxima[periodo];
    }

    float GET_cap_utilizada(int periodo){
        return cap_utilizada[periodo];
    }

    void SET_cap_maxima(float in_cap_maxima, int periodo){
        cap_maxima[periodo] = in_cap_maxima;
    }

    void SET_cap_utilizada(vector<PRODUTO> produtos, vector<int> dem_periodo, int periodo, int n_produtos){
        for(int produto = 1; produto < n_produtos + 1; produto++){
            if(dem_periodo[produto] != 0 && produtos[produto - 1].GET_cod_recurso() == cod_recurso){
                cap_utilizada[periodo] += dem_periodo[produto] * produtos[produto - 1].GET_utilizacao();
            }
        }
    }

    int extra_capacidade(int n_periodos){
        for(int periodo = n_periodos; periodo > 0; periodo--)
            if(cap_utilizada[periodo] > cap_maxima[periodo])
                return periodo;

        return 0;
    }

    void imprime_dados(int n_periodos){
        cout << "recurso: " << this->cod_recurso << endl;
        cout << "\tcapacidade maxima:    ";
        for(int periodo = 1; periodo < n_periodos + 1; periodo++)
            cout << this->cap_maxima[periodo] << " ";
        cout << endl;
        cout << "\tcapacidade utilizada: ";
        for(int periodo = 1; periodo < n_periodos + 1; periodo++)
            cout << this->cap_utilizada[periodo] << " ";
        cout << endl << endl;
    }
};

#endif // S_RECURSO_H
