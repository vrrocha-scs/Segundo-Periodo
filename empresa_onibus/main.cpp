#include "empresa.hpp"
#include "onibus.hpp"
#include<iostream>
#include<string>
using namespace std;  

int main()
{   empresa e;
    string onibus_procurado;
    string onibus_a_tranferir;
    int lotacao_a_cadastrar;
    char operacao;
    int subiram=0,desceram=0,transferidos=0;

    while(cin>>operacao && operacao!='F')
    {
        if(operacao=='C')
        {
            cin>>onibus_procurado;
            cin>>lotacao_a_cadastrar;
            e.adicionar_onibus(lotacao_a_cadastrar ,onibus_procurado);
        }
        if(operacao=='S')
        {
            cin>>onibus_procurado;
            cin>>subiram;
            onibus* o=e.busca_onibus(onibus_procurado);
            if(o!=nullptr)
              o->subir_passageiros(subiram);
            else
              cout<<"erro ao encontrar onibus"<<endl;
        }
        if(operacao=='D')
        {
            cin>>onibus_procurado;
            cin>>desceram;
            onibus* o=e.busca_onibus(onibus_procurado);
            if(o!=nullptr)
              o->descer_passageiro(desceram);
            else
             cout<<"erro ao encontrar onibus"<<endl;
        }
        if(operacao=='T')
        {
          cin>>onibus_procurado;
          cin>>onibus_a_tranferir;
          cin>>transferidos;
          onibus* o=e.busca_onibus(onibus_procurado);
          onibus* o2=e.busca_onibus(onibus_a_tranferir);
          if(o!=nullptr && o2!=nullptr)
          {
            o->transfere_passageiros(o2,transferidos);
          }
        }
        if(operacao=='I')
        {
        e.imprime_estado();
        }
    }
}