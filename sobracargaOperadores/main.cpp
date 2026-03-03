#include "HeapInt.hpp"
#include<iostream>
using namespace std;

int main(){
    HeapInt a(10);
   HeapInt b;

   cin >> b;
   if (a==b)
      cout << "Bingo!" << endl;

   HeapInt c = a;
   HeapInt d;
   HeapInt e;
   
   d = 5;
   e = a + b + c + d;
   cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}