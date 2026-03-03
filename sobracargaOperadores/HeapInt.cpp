#include "HeapInt.hpp"
#include <iostream>

   HeapInt::HeapInt():heap_int(new int(0)){}   
   HeapInt::HeapInt(int n):heap_int(new int(n)){}
   HeapInt::HeapInt(const HeapInt& parametro):heap_int(new int (*parametro.heap_int)){}
   HeapInt::~HeapInt(){};

   HeapInt& HeapInt::operator = (const HeapInt& v){
    *heap_int=*(v.heap_int);
    return *this;
   }

   HeapInt& HeapInt::operator = (int n){
    *heap_int = n;
    return *this;
   }

   HeapInt HeapInt::operator + (const HeapInt& v) const {
    return HeapInt(*heap_int+*v.heap_int);
   }

   HeapInt HeapInt::operator - (const HeapInt& v) const {
    return HeapInt(*heap_int - *v.heap_int);
   }

   bool HeapInt::operator == (const HeapInt& v) const {
    return (*heap_int==*v.heap_int);
   }

  std::istream& operator>>(std::istream& entrada, HeapInt& v){
      entrada >> *v.heap_int;
      return entrada;
  }

   std::ostream& operator << (std::ostream& saida,const HeapInt& v){
    return saida<<*(v.heap_int)<<" ";
   }
   
