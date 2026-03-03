#ifndef ALUNO_H
#define ALUNO_H
#include<string>
#include<vector>


class matricula{
private:    
int _numero_matricula;
std::string _nome_aluno;
std::vector<double> _notas_alunos;

public:
matricula(int,std::string,std::vector<double>);

double media_das_notas();
int maior_nota();
int menor_nota();
int get_numero_matricula();
std::string get_nome_aluno() const;
std::vector<double> get_notas_alunos();
};

#endif