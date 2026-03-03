#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
   int qnd_termos;
   int pos_procurada;
   string chave; 
   string possivel_chave;
   string variavel="*****";
   string lixo;
   ifstream in("palavras.txt",fstream::in);

   if(!in.is_open())
     {cout<<"erro de saida"<<endl;
     return 0;}
  
   in>>qnd_termos;
   cin>>pos_procurada;

   for(int i=0;i<pos_procurada+1;i++)
      getline(in,chave);

   for(int i=0;i<5;i++)
   {
    cin>>possivel_chave;
    variavel="*****";
    if(possivel_chave==chave)
    {   
        cout<<chave<<'('<<lixo<<')'<<endl;
        cout<<"GANHOU!"<<endl;
        return 0;
    }
      for(int j=0;j<5;j++)
      {
       int achou=0;
       for(int k=0;k<5;k++)
       {
          if(possivel_chave[j]==chave[k] && j==k)
          {
           achou=1;
           variavel[j]=chave[k];
           break;
          }
          else if(possivel_chave[j]==chave[k] && j!=k)
          {
            achou=1;
            variavel[j]=tolower(chave[k]);
            break;
          }
       }
       if(achou==0)
       {
        variavel[j]='*';
        if(lixo.find(possivel_chave[j])== string::npos)
          lixo+=possivel_chave[j]; 
       }
    }
     cout<<variavel<<'('<<lixo<<')'<<endl;
    }
     if(possivel_chave!=chave)
     cout<<"PERDEU! ZEBRA"<<endl;
     return 0;
}