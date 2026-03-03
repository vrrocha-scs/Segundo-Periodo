#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>

int main(){
    std::string palavra_proibida,frase_proibida;
    std::ifstream arquivo_proibido("palavras.txt");
    std::vector<std::string>frase_completa;
    std::map<std::string,int> contador_palavras;
    
    while(std::cin>>frase_proibida){
        frase_completa.push_back(frase_proibida);
    }

    if(arquivo_proibido.is_open()){
      while(arquivo_proibido>>palavra_proibida){
        for(int i=0;i<frase_completa.size();i++){
          if(frase_completa[i].find(palavra_proibida) != std::string::npos){
              std::string palavra_individual=frase_completa[i];
              contador_palavras[palavra_proibida]++;
              for(int j=0;j<palavra_individual.size();j++){
                if(isalnum(palavra_individual[j])){
                  palavra_individual[j]='*';
                }
              }
              frase_completa[i]=palavra_individual;
          }
        }
       }
    }

    for(auto it=frase_completa.begin();it!=frase_completa.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    for(auto it=contador_palavras.begin();it!=contador_palavras.end();it++){
       std::cout<<it->first<<" "<<it->second<<std::endl;
    }
}
