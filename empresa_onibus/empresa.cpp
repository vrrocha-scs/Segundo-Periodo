#include "empresa.hpp"
#include "onibus.hpp"
#include <iostream>
#include <string>
using namespace std;

empresa::empresa()
{
  _total_cadastrado = 0;
  for (int i = 0; i < 20; i++)
  {
    vetor[i] = nullptr;
  }
}

void empresa::adicionar_onibus(int capacidade_max,std::string placa)
{
  for(int i=0;i<_total_cadastrado;i++)
  {
    if(vetor[i]->_placa==placa)
    {
      std::cout<<"ERRO : VEICULO REPETIDO"<<std::endl;
      return;
    }
  }
  if (_total_cadastrado<20)
  {
    vetor[_total_cadastrado]=new onibus(placa,capacidade_max);
    _total_cadastrado++;
    std::cout<<"novo onibus cadastrado"<<std::endl;
  }
}

onibus* empresa::busca_onibus(std::string placa)
{
  for(int i=0;i<_total_cadastrado;i++)
  {
    if(placa==vetor[i]->_placa)
    {
      return vetor[i];
    }
  }
  return nullptr;
}

void empresa::imprime_estado()
{
  for(int i=0;i<_total_cadastrado;i++)
  {
    cout<<vetor[i]->_placa<<" "<<'('<<vetor[i]->_lotacao_atual<<'/'<<(vetor[i]->_max_passageiros)<<')'<<std::endl;
  } 
}