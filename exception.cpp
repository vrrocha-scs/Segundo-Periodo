#include<iostream>
#include<vector>

class NegativeResultException:public std::exception{
  public:
  int atributo;
  NegativeResultException(int n):atributo(n){};
   virtual const char* what() const throw(){
    return "Erro: Resultado Negativo.";
  }
};


int main(){
   std::vector<int> vector_teste{-20,-10,0,10,20};
   int n=0;
   try{
    std::cin>>n;
    int elemento=vector_teste.at(n);
    if(elemento<0){
        throw NegativeResultException(elemento);
    }
    if(elemento==0){
        throw std::logic_error("Erro: O resultado não deve ser zero");
    }
    std::cout<<elemento<<std::endl;
   }

   catch(std::out_of_range& e){
    std::cout<<"Erro: Parametro invalido"<<std::endl;
   }
   catch(std::logic_error& e){
    std::cout<<e.what()<<std::endl;
   }
   catch(NegativeResultException& e){
    std::cout<<e.what()<<std::endl<<e.atributo<<std::endl;
   }
}