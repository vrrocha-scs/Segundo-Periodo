#include<stdio.h>

int main()
{
    int ponto_procurado=0;
    int diagonal_dir_inf_antiga=0,vertice_dir_inf=0,vertice_dir_sup=0,vertice_esq_inf=0,vertice_esq_sup=0,vertice_pnt_esq_x=0,vertice_pnt_dir_x=0;
    int diagonal_esq=0,diagonal_dir=0;
    int eixo_x=0,eixo_y=0;
    int diferenca_esquerda=1,diferenca_direita=3,camada=0;
    scanf("%d",&ponto_procurado);
    while(1){
     if(diagonal_esq<=ponto_procurado && diagonal_dir>=ponto_procurado){//caso entre a diagonal esquerda e a direita
            eixo_x+=ponto_procurado-diagonal_esq;
            break;
      }
      else if(diagonal_esq>ponto_procurado){//caso em que apos o incremento, o ponto procurado esta antes da diagonal esquerda
        vertice_esq_inf=diagonal_esq-(camada-1);
        vertice_pnt_esq_x=vertice_esq_inf-camada;
        vertice_esq_sup=vertice_pnt_esq_x-(camada-1);
        vertice_dir_sup=vertice_esq_sup-(4*camada-4);
        vertice_pnt_dir_x=vertice_dir_sup-(camada-1);
        vertice_dir_inf=vertice_pnt_dir_x-(camada-1);
        if(ponto_procurado<=diagonal_esq && vertice_esq_inf<=ponto_procurado){//entre a diagonal esquerda e o vertice esquerdo inferior
            eixo_x+=ponto_procurado-diagonal_esq;
            break;
        }
        else{
         eixo_x-=diagonal_esq-vertice_esq_inf;
        }
        if(ponto_procurado<=vertice_esq_inf && ponto_procurado>=vertice_pnt_esq_x){//entre vertice esquerdo inferior e o vertice no eixo x esquerdo
          eixo_y+=vertice_esq_inf-ponto_procurado;
          eixo_x+=vertice_esq_inf-ponto_procurado;
          break;
        }
        else{
          eixo_x+=vertice_esq_inf-vertice_pnt_esq_x;
          eixo_y+=vertice_esq_inf-vertice_pnt_esq_x;
        }
        if(ponto_procurado<=vertice_pnt_esq_x && ponto_procurado>=vertice_esq_sup){//entre vertice no eixo x esquerdo e vertice esquerdo superior 
          eixo_y+=(vertice_pnt_esq_x-ponto_procurado);
          eixo_x-=(vertice_pnt_esq_x-ponto_procurado);
          break;
        }    
        else{
          eixo_x-=vertice_pnt_esq_x-vertice_esq_sup;
          eixo_y+=vertice_pnt_esq_x-vertice_esq_sup;
        }
        if(ponto_procurado<=vertice_esq_sup && ponto_procurado>=vertice_dir_sup){//entre vertice esquerdo superior e o vertice direito superior
          eixo_x+=vertice_esq_sup-ponto_procurado;
          break;
        }  
        else{
            eixo_x+=vertice_esq_sup-vertice_dir_sup;
        }
        if(ponto_procurado<=vertice_dir_sup && ponto_procurado>=vertice_pnt_dir_x){//entre  vertice direito superior  e o vertice no eixo x direito
          eixo_x-=vertice_dir_sup-ponto_procurado;
          eixo_y-=vertice_dir_sup-ponto_procurado;
          break;
        }  
        else{
            eixo_x-=vertice_dir_sup-vertice_pnt_dir_x;
            eixo_y-=vertice_dir_sup-vertice_pnt_dir_x;
        }
        if(ponto_procurado<=vertice_pnt_dir_x && ponto_procurado>=vertice_dir_inf){//entre o vertice no eixo x direito e o vertice direito inferior
          eixo_x+=vertice_pnt_dir_x-ponto_procurado;
          eixo_y-=vertice_pnt_dir_x-ponto_procurado;
          break;
        }  
        else{
            eixo_x+=vertice_pnt_dir_x-vertice_dir_inf;
            eixo_y-=vertice_pnt_dir_x-vertice_dir_inf;
        }
        if(ponto_procurado<=vertice_dir_inf && ponto_procurado>=diagonal_dir_inf_antiga){//entre o vertice direito inferior direito e a diagonal direita antiga
          eixo_x-=vertice_dir_inf-ponto_procurado;
          break;
        }  
      }
    else if(diagonal_esq<ponto_procurado){
        camada++;//mede a camada atual da figura
        eixo_x--;//eixo x na diagonal esquerda
        eixo_y--;//eixo y na diagonal esquerda
        diagonal_dir_inf_antiga=diagonal_dir;
        diagonal_esq+=diferenca_esquerda;
        diagonal_dir+=diferenca_direita;
        diferenca_esquerda+=12;//a cada camada da espira, a diferença entre a diagonal da camada anterior e a posterior é aumentada em 12 pontos
        diferenca_direita+=12;//a cada camada da espira, a diferença entre a diagonal da camada anterior e a posterior é aumentada em 12 pontos
    }
    }
    printf("(%d,%d)\n",eixo_x,eixo_y);
}