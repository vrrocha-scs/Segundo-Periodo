#include "aluno.hpp"
#include <iostream>
#include<algorithm>

matricula::matricula(int numero_matricula,std::string nome_aluno,std::vector<double> notas_alunos):_nome_aluno(nome_aluno),_numero_matricula(numero_matricula),_notas_alunos(notas_alunos){};

double matricula::media_das_notas(){
    double media=0;
  for(auto it=_notas_alunos.begin();it!=_notas_alunos.end();it++){
    media+=*it;
  }
  return media/_notas_alunos.size();
}
int matricula::maior_nota(){
   return *max_element(_notas_alunos.begin(),_notas_alunos.end());
}
int matricula::menor_nota(){
    return *min_element(_notas_alunos.begin(),_notas_alunos.end());
}
int matricula::get_numero_matricula(){
  return this->_numero_matricula;
};
std::string matricula::get_nome_aluno() const{
  return this->_nome_aluno;
};
std::vector<double> matricula::get_notas_alunos(){
  return this->_notas_alunos;
}