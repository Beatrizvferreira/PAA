#include<stdio.h>
#include<stdlib.h>
 
int maior=0;
int cont=0;
 
int backtracking(int A[10][20],int x, int y,int *B,int *C,int tam)
{
    int Axis[]= {1,2,-2,-1},i,j,aux,flag=0;
 
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if((abs(Axis[i])!= abs(Axis[j])) && ((x+Axis[i])>=0) && ((y+Axis[j])>=0) && (A[x+Axis[i]][y+Axis[j]]==2))
            {
                flag++;
                if((x+Axis[i]<tam)&&(y+Axis[j]<20)) //Se o valor de x e y extrapolarem, não terão casas para atingirem.Daí não atualizo os novos valores de x e y
                {
                    A[x+Axis[i]][y+Axis[j]] = 0; //Coloco 0 nas casas que já foram alcançadas
 
                    cont++; //Contador que nos ajudará a encontrar o maior caminho possível
                   // printf("\ncontador=%d\n\n",cont);
                   // printf("\n flag =%d \n ",flag);
                    backtracking(A,x+Axis[i],y+Axis[j],B,C,tam); //Chama recursivamente o backtracking para a casa seguinte
                }
            }
 
            else
 
                flag++;
 
        }}
 
            if(flag==16)
            {
              //  printf("\n SEM SAIDA \n");
                A[x][y] = 2; //significa que não encontrou nenhuma saída
                if(maior<=cont)
                    maior=cont; //conta o número de casas que passou e guarda o valor do maior caminho possível
                cont=cont-1;
 
                // printf("\nmaior=%d\n",maior);
            }
 
    if(flag==16) //condição de parada, não conseguiu andar para nenhum lugar. Finaliza o caminho e procura outro
        return maior;
}
 
int main()
{
    int tam,A[10],B[10],C[10][20],i,j;
    int aux,cont=0,boxes=0;
 
 
    scanf("%d",&tam);
    for(i=0; i<tam; i++)
    {
        scanf("%d",&A[i]);
        scanf("%d",&B[i]);
    }
 
    for(i=0; i<tam; i++)
    {
        aux=A[i]+B[i];
        for(j=A[i]; j<aux; j++)
        {
            C[i][j]=2;
            boxes++; //quantidade de casas no tabuleiro
        }
    }
    // printf("boxes=%d",boxes);
//printf("\n");
    C[0][A[0]]=0;
 
    aux=A[tam-1]+B[tam-1];
 
    int maior;
    maior = backtracking(C,0,A[0],A,B,tam);
   // printf("\n \n %d \n \n",maior);
 
    aux=boxes-(maior+1);
    printf("%d\n",aux);
 
    //printf("\n\n cont = %d",cont);
    return 0;
}