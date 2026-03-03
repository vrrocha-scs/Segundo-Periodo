#include "Onibus.hpp"
#include "Empresa.hpp"
#include <iostream>
#include <string>

onibus::onibus(std::string placa,int max_passageiros)
{
   _placa=placa;
   _max_passageiros=max_passageiros;
   _lotacao_atual=0;
}

void onibus::subir_passageiros(int novos_passageiros)
{
     if(_lotacao_atual+novos_passageiros<=_max_passageiros)
     {
        _lotacao_atual+=novos_passageiros;
        std::cout<<"passageiros subiram com sucesso"<<std::endl;
     }
     else
     std::cout<<"ERRO : onibus lotado"<<std::endl;
}

void onibus::descer_passageiro(int antigos_passageiros)
{
    if (_lotacao_atual-antigos_passageiros>=0)
    {
        _lotacao_atual-=antigos_passageiros;
        std::cout<<"passageiros desceram com sucesso"<<std::endl;
    }
    else
    std::cout<<"ERRO : faltam passageiros"<<std::endl; 
}

void onibus::transfere_passageiros(onibus* o2,int transferidos)
{   
     if(_lotacao_atual-transferidos<0 || o2->_lotacao_atual+transferidos>o2->_max_passageiros)
    std::cout<<"ERRO : transferencia cancelada"<<std::endl;
     else
    {
        _lotacao_atual-=transferidos;    
        o2->_lotacao_atual+=transferidos;
        std::cout<<"transferencia de passageiros efetuada"<<std::endl;
    }
} 

