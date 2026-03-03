#include<stdio.h>

int main()
{
    int ponto_procurado=0;
    int vertice_direito_inferior_antigo=0,vertice_direito_inferior=0,vertice_direito_superior=0,vertice_esquerdo_inferior=0,vertice_esquerdo_superior=0;
    int eixo_x=0,eixo_y=0;
    int diferenca_esquerda=4,diferenca_direita=6,camada=0;
    scanf("%d",&ponto_procurado);
    while(1){
     if(vertice_esquerdo_inferior<=ponto_procurado && vertice_direito_inferior>=ponto_procurado){//caso entre a diagonal esquerda e a direita
            eixo_x+=ponto_procurado-vertice_esquerdo_inferior;
            break;
      }
      else if(vertice_esquerdo_inferior>ponto_procurado){//caso em que apos o incremento, o ponto procurado esta antes da diagonal esquerda
        vertice_esquerdo_superior=vertice_esquerdo_inferior-(2*camada);
        vertice_direito_superior=vertice_esquerdo_superior-(2*camada-1);
        vertice_direito_inferior_antigo=vertice_direito_superior-(2*camada-1);
        if(ponto_procurado<=vertice_esquerdo_inferior && vertice_esquerdo_superior<=ponto_procurado){//entre a vertice esquerdo inferior e o vertice esquerdo superior
            eixo_y+=vertice_esquerdo_inferior-ponto_procurado;
            break;
        }
        else{
         eixo_y+=vertice_esquerdo_inferior-vertice_esquerdo_superior;
        }
        if(ponto_procurado<=vertice_esquerdo_superior && ponto_procurado>=vertice_direito_superior){//entre o vertice esquerdo superior e o vertice direito superior
          eixo_x+=vertice_esquerdo_superior-ponto_procurado;
          break;
        }
        else{
          eixo_x+=vertice_esquerdo_superior-vertice_direito_superior;
        }
        if(ponto_procurado<=vertice_direito_superior && ponto_procurado>=vertice_direito_inferior_antigo){//entre vertice direito superior e o vertice direito inferior
          eixo_y+=ponto_procurado-vertice_direito_superior;
          break;
        }    
      }
    else if(vertice_esquerdo_inferior<ponto_procurado){
        camada++;//mede a camada atual da figura
        eixo_x--;//eixo x na diagonal esquerda
        eixo_y--;//eixo y na diagonal esquerda    
        vertice_esquerdo_inferior+=diferenca_esquerda;
        vertice_direito_inferior+=diferenca_direita;
        diferenca_esquerda+=8;//a cada camada da espira, a diferença entre a diagonal da camada anterior e a posterior é aumenta em 8 pontos
        diferenca_direita+=8;//a cada camada da espira, a diferença entre a diagonal da camada anterior e a posterior é aumenta em 8 pontos
    }
    }
    printf("(%d,%d)\n",eixo_x,eixo_y);
}