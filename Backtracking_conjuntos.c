#include<stdio.h>
#include<stdlib.h>

backtracking(int A[][],int k,tam){

    int i,cont=0;
    A[0][0]=-1;
    if(k==tam){

    printf("%d ",cont);

   else{
     A[k]=1;
     backtracking(A,i+1)
     A[k]=0;
     backtracking(A,i+1)
    }
}

int main(){

int tam,A,B,C,i,j;

C=(int**) calloc(tam,sizeof(int));

scanf("%d",&tam);
A=(int*) malloc(tam*sizeof(int));
B=(int*) malloc(tam*sizeof(int));

for(i=0;i<tam;i++){

scanf("%d",&A[i]);
scanf("%d",&B[i]);

}

for(i=0;i<tam;i++){
for(j=A[i];j<B[i];j++){
C[i][j]=1;
j++;

}}

//backtracking(C,0,tam);

}

return 0;

}

