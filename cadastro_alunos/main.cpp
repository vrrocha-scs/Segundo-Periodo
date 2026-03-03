#include "aluno.hpp"
#include<iostream>
#include<list>
#include<algorithm>
#include<iomanip>
using namespace std;

class ComparaAluno{
  public:
  bool operator()(const matricula* a,const matricula* b)const{
    return a->get_nome_aluno()<b->get_nome_aluno();
  }
};

int main(){
  list<matricula*> total_aluno;
  string frase;

  while(1){
    double notas=0;
    int matricula_auxiliar=0;
    vector<double> vector_auxiliar;
    string nome_auxiliar;
    cin>>nome_auxiliar;
    if(nome_auxiliar=="END"){
      break;
    }
    cin>>matricula_auxiliar;
    
    while (cin>>notas && notas!=-1)
    {
      vector_auxiliar.push_back(notas);
    }
    total_aluno.push_back(new matricula(matricula_auxiliar,nome_auxiliar,vector_auxiliar));
    }
    total_aluno.sort(ComparaAluno());
  for(auto it=total_aluno.begin();it!=total_aluno.end();it++){
     double media=(*it)->media_das_notas();
     int _maior_nota=(*it)->maior_nota();
     int _menor_nota=(*it)->menor_nota();

     cout<<(*it)->get_numero_matricula()<<" "<<(*it)->get_nome_aluno()<<" ";
     for (double n:(*it)->get_notas_alunos())
     {
      cout<<endl<<fixed<<setprecision(0)<<n<<" ";
     }
     cout<<endl<<fixed<<setprecision(2)<<media<<" "<<_maior_nota<<" "<<_menor_nota<<endl;
  }
  for(auto it=total_aluno.begin();it!=total_aluno.end();it++){
    delete *it;
  }
}