#include<stdio.h>
#include<stdlib.h>
 
typedef struct
{
    int p;
}Tbox;
 
int LerDados()
{
    int aux;
    scanf("%d",&aux);
    return aux;
}
 
int main()
{
 
    int i, j = 0, A, E;
    int aux, max, dist, flag=0, cont=0;
    Tbox *num;
 
    E = LerDados(); // Tamanho da Escala
    A = LerDados(); // Tamanho do Acorde
 
    num = (Tbox*) malloc(A*sizeof(Tbox));
 
      for (i=0; i<A; i++) //Entrada contém A inteiros distintos X, (0 <= X1 < X2 < ... < XA < A)
      {
        num[i].p = LerDados();
      }
 
     aux = num[0].p;
     max = E/A;
 
      for (i = 0; i < A; i++) //Retorno o ponto inicial para a origem e os demais diminuem proporcionalmente
      {
        (num[i].p) = (num[i].p) - aux;
      }
 
      while ((flag == 0) && (cont != max))
      {
        j = 0;
        cont++;
 
           for (i=0; i<A; i++)
           {
             aux=((i+1)*max)%E; //Aqui defino os intervalos
               if (aux != 0)
                 {
                    if ((num[i].p < aux) && (num[i + 1].p >= aux)) //Condição para verificar se existe um único ponto em cada intervalo
                      j++;
 
                    else //Caso não, eu paro o for para poder andar com todos os pontos e verificar novamente
                      i = A;
                 }
               else //Caso especial, onde o meu último ponto está no final da reta/círculo e jogo-o para o ínicio
                 {
                    if ((num[i].p >= aux) && ((num[0].p >= aux)&&(num[0].p<= max))) //(num[0].p <= aux+max)
                       j++;
 
                    else
                        i = A;
                 }
            }
 
        if(j!=A) //Se j!=A significa que existem mais pontos em um intervalo do que deveria
         {
            for (i = 0; i < A; i++) //Andar com todos os pontos
            {
                if (num[i].p != (E-1))
                {
                    num[i].p++;
                }
                else
                    num[i].p = 0; //Caso em que o meu ultimo ponto está no final do circulo
            }
         }
        else //Existe um ponto em cada intervalo de tamanhos iguais. Sucesso!
            flag = 1;
 
    }
 
    if(flag == 1)
        printf("S");
    else
        printf("N");
 
    free(num);
 
    return 0;
}