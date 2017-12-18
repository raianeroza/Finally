#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 200

void imprime(double M[N][N])
{
     int i, j;
     
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++){
			printf("%lf\t", M[i][j]);
		}
		printf("\n");
		
	}
}
void potencial(double Masc[N][N], double pot[N][N])
{
	int i, j, t;
	
	for(j=0; j<N; j++)
	{	
		pot[N-1][j] = 100;
	}
	
	for(t=0; t<20000; t++)	
	{		
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				if(Masc[i][j]==0)
				{
					pot[i][j] = (pot[i+1][j] + pot[i-1][j] + pot[i][j+1]+ pot[i][j-1])/ 4.0;	
				}
			}
		}
	}
}

void mascara(double Masc[N][N])
{
	int i;
	
	for(i=0; i<N; i++)
		Masc[N-1][i] = 1.0;
	
	for(i=N/4; i<200-(N/4); i++)			//T no meio da matriz
		Masc[N/2][i] = 1.0;	
		
	for(i=1; i<N/2; i++)
		Masc[i][N/2] = 1.0;
}

main()
{	

	double Masc[N][N] = {0}, pot[N][N] = {0};
	int i, j, t; 
	
	//máscara
	mascara(Masc);

	//função potencial
	potencial(Masc, pot);
	imprime(pot);
}
	
