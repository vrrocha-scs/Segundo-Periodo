#include<stdio.h>

int main()
{
     int ponto_procurado=0;
     int diagonal_dir=0,diagonal_esq=0,diagonal_dir_antiga=0,vertice_dir_antigo=0;
    int eixo_x=0,eixo_y=0;
     int diferenca_esquerda=5,diferenca_direita=7,diferenca_superior=0;
    scanf("%d",&ponto_procurado);
     int vertice_esquerdo=0,vertice_dir=1,vertice_superior=0;
    while(1){
      if(diagonal_esq<=ponto_procurado && diagonal_dir>=ponto_procurado){//caso entre a diagonal esquerda e a direita
            eixo_x+=ponto_procurado-diagonal_esq;
            break;
      }
      else if(diagonal_esq>ponto_procurado){//caso em que, apos o incremento, o ponto procurado esta antes da diagonal esquerda
        if(ponto_procurado<=diagonal_esq && vertice_esquerdo<=ponto_procurado){//entre a diagonal esquerda e o vertice esquerdo 
            eixo_x+=ponto_procurado-diagonal_esq;
            break;
        }
        else{
         eixo_x+=vertice_esquerdo-diagonal_esq;
        }
        if(ponto_procurado<=vertice_esquerdo && ponto_procurado>=vertice_superior){//entre vertice esquerdo e o vertice superior
          eixo_y+=vertice_esquerdo-ponto_procurado;
          eixo_x+=vertice_esquerdo-ponto_procurado;
          break;
        }
        else{
          eixo_x=0;
          eixo_y+=vertice_esquerdo-vertice_superior;
        }
        if(ponto_procurado<=vertice_superior && ponto_procurado>=vertice_dir_antigo){//entre vertice superior e o vertice direito
          eixo_x+=vertice_superior-ponto_procurado;
          eixo_y+=ponto_procurado-vertice_superior;
          break;
        }
        else{
          eixo_x+=vertice_superior-vertice_dir_antigo;
          eixo_y+=vertice_dir_antigo-vertice_superior;
        }
        if(ponto_procurado<=vertice_dir && ponto_procurado>=diagonal_dir_antiga){//entre o vertice direito e a diagonal direita da camada anterior
          eixo_x+=-(vertice_dir_antigo-ponto_procurado);
          break;
        }
            
      }
    else if(diagonal_esq<ponto_procurado){
        diferenca_superior-=2;//mede a distancia entre o vertice a esquerda e o vertice superior 
        eixo_x--;//eixo x na diagonal esquerda
        eixo_y--;//eixo y na diagonal esquerda
        diagonal_esq+=diferenca_esquerda;
        diagonal_dir_antiga=diagonal_dir;//marca onde esta a diagonal direita antes do aumento da camada
        diagonal_dir+=diferenca_direita;
        vertice_esquerdo=diagonal_esq+eixo_x;
        vertice_dir_antigo=vertice_dir;
        vertice_dir=diagonal_dir-eixo_x+1;
        vertice_superior=vertice_esquerdo+diferenca_superior;
        diferenca_esquerda+=8;//a cada camada da espira, a diferença entre a diagonal da camada anterior e a posterior é aumenta em 8 pontos
        diferenca_direita+=8;//a cada camada da espira, a diferença entre a diagonal da camada anterior e a posterior é aumenta em 8 pontos
    }
    }
    printf("(%d,%d)\n",eixo_x,eixo_y);
}