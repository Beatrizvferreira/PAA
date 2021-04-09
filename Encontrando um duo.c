#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
 
int LerDados()
{
    int aux;
    scanf("%d",&aux);
    return aux;
}
 
int main()
{
    int num,j=0,i,flag=1,tam;
    int cont=0,cont2=0,A[MAX],B[MAX];
    int *contador;// = (int*)calloc(MAX,sizeof(int));
 
    scanf("%d",&num);
    contador = (int*)calloc(num,sizeof(int));
 
    tam=num;
    for(i=0; i<num; i++)
    {
        A[i]=LerDados();
        B[i]=LerDados();
        contador[B[i]-1] = contador[B[i]-1] + 1;
    }
 
    int aux;
    while(flag==1)
    {
        i=0;
        flag = 0;
        while(i < num)
        {
            if(contador[i]==0) ///Coloco contador negativo para saber que já foi removido
            {
                contador[i] = -1;
                contador[B[i]-1]--;
                flag=1;
            }
            else i++;
        }
    }
 
    printf("\n");
    for(i=0; i<num; i++)
    {
        if(contador[i]!=-1)
            printf("%d ",A[i]);
    }
 
    return 0;
}