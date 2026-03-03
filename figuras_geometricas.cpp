#include<iostream>
#include<string>
#include<cmath>
#include<list>
#include<iomanip>

class Ponto{
    private:
    int coordenada_x,coordenada_y;
    public:
    Ponto(int c1,int c2):coordenada_x(c1),coordenada_y(c2){}
    int get_x(){
        return coordenada_x;
    }
    int get_y(){
      return coordenada_y;
    }
};

class Figuras_geometricas{
protected:
    Ponto centro;
public:
    virtual float Calcula_area()=0;
    virtual void Imprime_centro(){
        std::cout<<centro.get_x()<<" "<<centro.get_y()<<" ";
    }
     Figuras_geometricas(int c1,int c2):centro(c1,c2){}
};

class Triangulo :public Figuras_geometricas{
private:
 int base,altura;
public:
  float Calcula_area() override {
   return (base*altura)/2.00;
  }
   void Imprime_centro() override{
    Figuras_geometricas::Imprime_centro();
    std::cout<<"TRIANGULO"<<std::endl;
  }
  Triangulo(int c1,int c2,int b,int h):Figuras_geometricas(c1,c2),base(b),altura(h){}
};

class Retangulo :public Figuras_geometricas{
private:
 int lado1, lado2;
public:
  float Calcula_area() override {
   return lado1*lado2;
  }
   void Imprime_centro() override{
    Figuras_geometricas::Imprime_centro();
    std::cout<<"RETANGULO"<<std::endl;
  }
  Retangulo(int c1, int c2,int l1,int l2):Figuras_geometricas(c1,c2),lado1(l1),lado2(l2){}
};

class Circulo :public Figuras_geometricas{
private:
 int raio;
public:
  float Calcula_area() override {
   return raio*raio*M_PI;
  }
  void Imprime_centro() override{
    Figuras_geometricas::Imprime_centro();
    std::cout<<"CIRCULO"<<std::endl;
  }
   Circulo(int c1, int c2,int p1):Figuras_geometricas(c1,c2),raio(p1){}
};



int main(){
     char comando;
     std::list<Figuras_geometricas*> figuras;
    while(std::cin>>comando && comando!= 'E'){  
     int c1=0,c2=0,p1=0,p2=0;
     if(comando=='R'){
       std::cin>>c1>>c2>>p1>>p2;
       Retangulo* ret=new Retangulo(c1,c2,p1,p2);
       figuras.push_back(ret);
     } 
     else if(comando=='C'){
       std::cin>>c1>>c2>>p1;
       Circulo* cir=new Circulo(c1,c2,p1);
       figuras.push_back(cir);
     }
     else if(comando=='T'){
       std::cin>>c1>>c2>>p1>>p2;
       Triangulo* tri=new Triangulo(c1,c2,p1,p2);
       figuras.push_back(tri);
     }
     else if(comando=='D'){
       for(Figuras_geometricas* ptr:figuras)
       {
        ptr->Imprime_centro();
       }
     }
     else if(comando=='A'){
        float area=0;
        for(Figuras_geometricas* ptr:figuras){
        area+=(ptr->Calcula_area());
        }
         std::cout<<std::fixed<<std::setprecision(2)<<area<<std::endl;
     }
    }
}