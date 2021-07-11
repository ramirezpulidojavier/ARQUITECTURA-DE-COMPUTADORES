#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <omp.h>


struct{

	int a;
	int b;

}s[5000];

int main(int argc,char**argv)
{

    double tiempo_antes, tiempo_despues, tiempo_ejecucion;
    int ii, i, X1, X2;
    int R[40000];


    //Realiza las cuentas y se mide el tiempo antes y despues de hacerlo para calcular el tiempo de ejecucion
    tiempo_antes = omp_get_wtime();

    for (ii=0; ii<40000;ii++) {
	X1=0; X2=0; 
	for(i=0; i<5000;i++)
		X1+=2*s[i].a+ii;
	for(i=0; i<5000;i++)
		X2+=3*s[i].b-ii;

	if(X1<X2)  R[ii]=X1;  else  R[ii]=X2;
	}

 

    tiempo_despues = omp_get_wtime();
    tiempo_ejecucion=tiempo_despues-tiempo_antes;
    
    //Muestra dimension y tiempo final
    printf("\nR[0]: %i"     , R[0]);
    printf("\nR[39999]: %i  ", R[39999]);
    printf("\nTiempo: %11.9f segundos\n\n", tiempo_ejecucion);


    return 0;

}

