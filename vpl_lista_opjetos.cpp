#include<iostream>
#include<list>
#include<sstream>
#include<string>
using namespace std;

class ObjetoVpl{
    private:
    int id;
    static int contador_id;

    public:
     ObjetoVpl(int x):id(x){};
     ObjetoVpl():id(contador_id){contador_id++;};
     ~ObjetoVpl(){
     }

   void impressor_dados(){
    cout<<id<<" "<<this<<endl;
   }
   static ObjetoVpl* achar_ultimo(list<ObjetoVpl*> &lista_apontadores){
   return lista_apontadores.back();
  }
   static ObjetoVpl* achar_primeiro(list<ObjetoVpl*> &lista_apontadores){
    return lista_apontadores.front();
   }
   static void achar_i_esimo(int &posicao,list<ObjetoVpl*> &lista_apontadores){
    auto it=lista_apontadores.begin();
    advance(it,posicao-1);
    (*it)->impressor_dados();
   }
};

int ObjetoVpl::contador_id=1;

int main(){
    char comando;
    string linha;
    ObjetoVpl* apontador=nullptr;
    list<ObjetoVpl*>lista_apontadores;
    while(getline(cin,linha) && linha!="E"){
      stringstream ss(linha);
      ss>>comando;
        if(comando=='A'){
          lista_apontadores.push_back(new ObjetoVpl());
          apontador=ObjetoVpl::achar_ultimo(lista_apontadores);
          apontador->impressor_dados();
        }
        else if(comando=='C'){
            int id=0;
          if(ss>>id){
            if(id<0){
              lista_apontadores.push_front(new ObjetoVpl(id));
              apontador=ObjetoVpl::achar_primeiro(lista_apontadores);
              apontador->impressor_dados();
            }
            else
              cout<<"ERRO"<<endl;
         }
        }
       else if(comando=='R'){
        if(!lista_apontadores.empty()){
          apontador=ObjetoVpl::achar_primeiro(lista_apontadores);
          apontador->impressor_dados();
          delete apontador;//deleta os dados do objeto apontado
          lista_apontadores.pop_front();//retira ele da frente da lista encadeada
        }
        else
        cout<<"ERRO"<<endl;
       }
       else if(comando=='N'){
        cout<<lista_apontadores.size()<<endl;
       }
       else if(comando=='P'){
        int posicao=0;
        ss>>posicao;
        if(posicao>0 && posicao<=lista_apontadores.size()){
        ObjetoVpl::achar_i_esimo(posicao,lista_apontadores);
       }
        else
        cout<<"ERRO"<<endl;
       }
       else if(comando=='L'){
         for (ObjetoVpl* ptr:lista_apontadores){
            ptr->impressor_dados();
         }
         
       }
    }
    for (ObjetoVpl* ptr:lista_apontadores){
           delete ptr;
           lista_apontadores.pop_front();
         }
}