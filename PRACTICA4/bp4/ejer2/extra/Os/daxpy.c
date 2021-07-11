#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <omp.h>


int main(int argc,char**argv)
{

	//Comprueba que la cantidad de argumentos es la correcta
    if(argc!=3){

         printf("\nFalta el numero de elementos del primera_matriz\n");
         exit(-1);
    }

    //Declaracion de variables
    double tiempo_antes, tiempo_despues, tiempo_ejecucion;


	/*
	 * Nucleo original
	 */
	double *x, *y, a= atoi(argv[2]);
	unsigned int N = atoi(argv[1]) ;

	//Reserva para vectores
	    x = (double*) malloc(N*sizeof(double));
	    y = (double*) malloc(N*sizeof(double));



	//Rellenar vectores
	    for(int i=0; i<N; i++){
			x[i] = i*4 ;
			y[i] = i+3;
	    }



	/* Función a optimizar */
	inline void daxpy (){
	    
	    int i;

	    // hacemos la multiplicacion
	    for (i=0; i<N; i++){

		y[i] = a*x[i] + y[i];

	    }

	}


	

    //Realiza las cuentas y se mide el tiempo antes y despues de hacerlo para calcular el tiempo de ejecucion
    tiempo_antes = omp_get_wtime();

    daxpy();
    

    tiempo_despues = omp_get_wtime();
    tiempo_ejecucion=tiempo_despues-tiempo_antes;
    
    //Muestra dimension y tiempo final
    printf("\nDimension: %d      y[0]: %f      y[%d]: %f       Tiempo: %11.9f segundos\n", N ,y[0], N-1, y[N-1], tiempo_ejecucion);
   


    return 0;

}

