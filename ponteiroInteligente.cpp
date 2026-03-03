#include <iostream>
#include <memory>

class Teste{
   public:
   int atributo;
   Teste():atributo(0){
    std::cout<<"Construtor "<<atributo<<std::endl;
   }
   Teste(int n):atributo(n){
    std::cout<<"Construtor "<<atributo<<std::endl;
   }
   ~Teste(){
    std::cout<<"Destrutor "<<atributo<<std::endl;
   }
};

int main(){
    int n=0;
    std::cin>>n;

    if(n%2==0){
       for(int c=1;c<=n;c++){
        Teste* loop=new Teste(c);
        std::unique_ptr<Teste> loop_unique_pointer (new Teste(c));
       }
    }
    else{
        std::shared_ptr<Teste> shared_pointer(new Teste(0));
        for(int c=1;c<=n;c++){
          std::shared_ptr<Teste> loop_shared_pointer=shared_pointer;
          loop_shared_pointer->atributo=c;
        }
        std::cout<<shared_pointer.use_count()<<std::endl;
    }
    return 0;
}