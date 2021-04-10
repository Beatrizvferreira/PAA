# include<stdio.h>
# include<stdlib.h >

float abastece(float m,float posto_abst)
{
    return m + posto_abst; // Novo ponto de partida do carro
}

int abastecido (int qnt_abst)
{
    return qnt_abst + 1; // Quantidade de vezes que foi abastecido
}

int verifica (float *D , float B , int n , float m ) // Verifica se eh possivel chegar no posto seguinte
{
    int i ;

    if (( B-D[n -1])>m || m<D[0])
        return 0;
    
    for (i=1; i<=n;i++)
    { 
        if ((D[i] - D[i-1])> m)
            return 0;
    }
    return 1;
}

void Num_minimo (float *D , float B , float m ,int n )
{
    int i , cont =0 , qnt_minima ;
    float posicao = m ;
    D[n]= B ;

    if (m>B)
    {
        qnt_minima = 0;
        printf ("\n%d", qnt_minima ) ;
    }
    else
    {
        if( verifica (D ,B ,n , m ) )// Verifico se ha a possibilidade de nao conseguir chegar no posto seguinte
    {
        for( i =1; i <= n ; i++)
        {
            if (posicao<D[i])
            {
                posicao = abastece (m , D[i-1]) ; // Nova posicao , depois de abastecido no posto D[i -1]
                printf (" abastece em %.2f \n",D[i-1]) ;
                cont = abastecido ( cont ) ;
            }
        }
        qnt_minima = cont ;
        printf ("\n%d", qnt_minima ) ;
    }
    else
        printf ("\n Nao eh possivel chegar na cidade B") ;
    }
}

void le_posicoes_postos ( float *D ,int n )
{
    int i ;
    printf ("Digite sequencialmente as posicoes dos postos :\n") ;
    for ( i =0; i < n ; i ++)
        scanf ("%f" ,&D[i]) ;
}

int main ()
{
    float B , m ; //B eh a distancia ate o destino e m eh a km que pode ser percorrida
    int i , n ; //n numero de postos de combustiveis
    float *D ; // Localizacao dos postos

    printf ("Digite a autonomia do tanque para viajar :\n") ;
    scanf ("%f" ,&m ) ;
    printf ("Digite a quantidade postos :\n") ;
    scanf ("%d" ,&n ) ;
    printf ("Digite a distancia da cidade A ate a cidade B:\n") ;

    scanf ("%f" ,&B ) ;
    D =( float *) malloc ( n * sizeof(float) ) ;
    le_posicoes_postos (D,n) ;
    Num_minimo (D,B,m,n) ;

    return 0;
}