#include <iostream>
#include <string>
#include<fstream>
#include<ctype.h>
#include<sstream>
#include<map>
using namespace std;

int main()
{ string nome_arquivo;
  cin>>nome_arquivo;
   map<string,int> total;
   string palavra;
   string frase;
   ifstream arquivo(nome_arquivo);
   if(!arquivo.is_open())
   {
    cout<<"erro ao abrir arquivo de entrada"<<endl;
   }
   while (getline(arquivo,frase))
   {
    stringstream ss(frase);
    while(ss>>palavra)
    {
     string palavra_nova;
     for(char &c: palavra)
     {
        c=tolower(c);
        if(isalnum(c))
        {
          palavra_nova+=c;
        }
        else
        {
         total[palavra_nova]++;
         palavra_nova.clear();
        }
     }
     total[palavra_nova]++;
    }
   }
   arquivo.close();
   
   for(auto it=(total.begin());it!=total.end();it++)
   {
    cout<<it->first<<" "<<it->second<<endl;
   }
  

}