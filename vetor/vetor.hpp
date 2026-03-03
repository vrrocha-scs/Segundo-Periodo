#ifndef VETOR_H
#define VETOR_H
#include <vector>
#include <iostream>

template<typename T>
class Vetor{
 private:
    T* array;
    int tamanho;
    int tamanho_atual;
 public:
    Vetor(int n):tamanho(n),tamanho_atual(0){
       array=new T[tamanho];
    }
    Vetor(const Vetor& parametro):tamanho(parametro.tamanho),tamanho_atual(parametro.tamanho_atual){
        array=new T[tamanho];
        for(int i=0;i<tamanho_atual;i++){
            array[i]=parametro.array[i];
        }
    }
    ~Vetor(){
        delete[] array;
    }

    void SetElemento(int i,T x){
        array[i]=x;
    }
    T GetElemento(int i){
     return array[i];
    }
    void AdicionaElemento(T x){
        if(tamanho_atual<tamanho){
            array[tamanho_atual]=x;
            tamanho_atual++;
        }
    }
    void Imprime(){
        for(int i=0;i<tamanho_atual;i++){
          std::cout<<array[i]<<" ";
        }
        std::cout << std::endl;
    }
};


#endif 