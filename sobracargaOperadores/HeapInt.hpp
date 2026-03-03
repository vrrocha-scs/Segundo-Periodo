#ifndef HEAPINT_H
#define HEAPINT_H
#include <memory>
#include <iostream>

class HeapInt{
   private:
   std::unique_ptr<int> heap_int;
   public:

   HeapInt();
   HeapInt(int n);
   HeapInt(const HeapInt& parametro);
   ~HeapInt();
   
   HeapInt& operator = (const HeapInt&);
   HeapInt& operator = (int);
   HeapInt operator + (const HeapInt&) const;  
   HeapInt operator - (const HeapInt&) const;
   bool operator == (const HeapInt&) const;
   friend std::istream& operator >> (std::istream&, HeapInt&);
   friend std::ostream& operator << (std::ostream&,const HeapInt&);
};
#endif