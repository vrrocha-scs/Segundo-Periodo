#ifndef ONIBUS_H
#define ONIBUS_H
#include<string>


struct onibus
{
    std::string _placa;
    int _max_passageiros;
    int _lotacao_atual;

    onibus(std::string,int);
    void subir_passageiros(int);
    void descer_passageiro(int);
    void transfere_passageiros(onibus*,int);
};


#endif