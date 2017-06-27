#include "s_planejamento.h"
#include "s_produto.h";
#include "s_recurso.h"

using namespace std;

#ifndef function_H
#define function_H

void leitura_produtos(vector<PRODUTO> &produtos, int n_produtos, char arquivo[]);

void leitura_recursos(vector<RECURSO> &recursos, int n_recursos, int n_periodos, char arquivo[]);

void leitura_demanda(PLANEJAMENTO &plano_producao, int n_produtos, int n_periodos, char arquivo[]);

void leitura_complexidade(int &n_produtos, int &n_recursos, int &n_periodos, char arquivo[]);

#endif // function_H
