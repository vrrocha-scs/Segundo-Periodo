#ifndef EMPRESA_H
#define EMPRESA_H
#include<string>
#include "onibus.hpp"

struct empresa
{
    onibus* vetor[20];
    int _total_cadastrado;

    empresa();
    void adicionar_onibus(int,std::string);
    onibus* busca_onibus(std::string);
    void imprime_estado();
};



#endif