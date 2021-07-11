#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <omp.h>

main(int argc,char**argv)
{
	//Comprueba que la cantidad de argumentos es la correcta
    if(argc!=2){

         printf("\nFalta el numero de elementos del vector\n");
         exit(-1);
    }

    //Declaracion de variables
    unsigned int tamanio_total = atoi(argv[1]);
    double tiempo_antes, tiempo_despues, tiempo_ejecucion;

    //Reserva para vectores
    int *vector = (int*) malloc(tamanio_total*sizeof(int));
    int *vector_auxiliar = (int*) malloc(tamanio_total*sizeof(int));

    //Reserva para matrices
    int **matriz = (int **)malloc(tamanio_total*sizeof(int *));
    for(int i = 0; i<tamanio_total; i++)
    	matriz[i] = (int *) malloc (tamanio_total*sizeof(int));

    //Comprueba que la reserva de memoria fue correcta
    if(vector==0 || vector_auxiliar==0 || matriz==0){
	    printf("La reserva de espacio para la matriz y el vector ha dado fallo\n");
	    exit(-2);
    }

    //Comprueba que la reserva de memoria fue correcta
    for(int i=0; i<tamanio_total; i++)
	    if(matriz[i] == 0){
	        printf("La reserva de espacio ha dado fallo\n");
	        exit(-2);
	    }

	//Rellenar la matriz, vector y vector de resultados
    for(int i=0; i<tamanio_total; i++){
	    for(int j=i; j<tamanio_total; j++)
	        matriz[i][j] = j+3;
	    
	    vector[i] = 2*i;
	    vector_auxiliar[i] = 0;
    }

    //Realiza las cuentas y se mide el tiempo antes y despues de hacerlo para calcular el tiempo de ejecucion
    tiempo_antes = omp_get_wtime();

    for(int i=0; i<tamanio_total; i++)
	    for(int j=i; j<tamanio_total; j++) 
	    	vector_auxiliar[i] += matriz[i][j] * vector[i];
    

    tiempo_despues = omp_get_wtime();
	tiempo_ejecucion=tiempo_despues-tiempo_antes;
    
    if(tamanio_total<10){

        //Muestra la matriz
        printf("\nMatriz: \n");
        for(int i=0; i<tamanio_total; i++){
            printf("\t");
            for(int j=0; j<tamanio_total; j++)
                if(j >= i) printf("%d ", matriz[i][j]);
                else printf("0 ");

        printf("\n");

        }

        //Muestra el vactor por el que multiplica
        printf("\nVector: \n");
        printf("\t");
        for(int i=0; i<tamanio_total; i++) printf("%d ", vector[i]);
        printf("\n");

        //Muestra el vactor que contiene los resultados
        printf("\nDatos finales: \n");
        printf("\t");
        for(int i=tamanio_total-1; i>=0; i--) printf("%d  ", vector_auxiliar[i]);
        printf("\n");

    }
    

    //Muestra dimension y tiempo final
    printf("\nDimension de vector y matriz: %d   Tiempo: %11.9f segundos\n\n", tamanio_total, tiempo_ejecucion);
    printf("\nPrimer elemento (matriz[0][0]): %d    Ultimo elemento (matriz[%d][%d]): %d \n\n", matriz[0][0],tamanio_total-1,tamanio_total-1, matriz[tamanio_total-1][tamanio_total-1]);
    
    //libera espacio de la matriz
    for(int i=0; i<tamanio_total; i++) free(matriz[i]);
    free(matriz);

	//libera espacio del vector
	free(vector);
    free(vector_auxiliar);


    return 0;

}

