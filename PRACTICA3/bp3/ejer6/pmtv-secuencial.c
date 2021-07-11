#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(int argc,char**argv)
{
	//Comprueba que la cantidad de argumentos es la correcta
    if(argc!=2){

         printf("\nFalta el numero de elementos del vector\n");
         exit(-1);
    }

    //Declaracion de variables
    unsigned int tamanio_total = atoi(argv[1]);
    struct timespec tiempo_antes, tiempo_despues;
    double tiempo_ejecucion;

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
	        matriz[i][j] = 1;
	    
	    vector[i] = 3;
	    vector_auxiliar[i] = 0;
    }

    //Realiza las cuentas y se mide el tiempo antes y despues de hacerlo para calcular el tiempo de ejecucion
    clock_gettime(CLOCK_REALTIME, &tiempo_antes);

    for(int i=0; i<tamanio_total; i++)
	    for(int j=i; j<tamanio_total; j++) 
	    	vector_auxiliar[i] += matriz[i][j] * vector[i];
    

    clock_gettime(CLOCK_REALTIME, &tiempo_despues);
	tiempo_ejecucion=(double)(tiempo_despues.tv_sec-tiempo_antes.tv_sec) + (double)((tiempo_despues.tv_nsec-tiempo_antes.tv_nsec)/(1.e+9));
    
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

    //Muestra dimension y tiempo final
    printf("\nDimension de vector y matriz: %d\n\nTiempo: %11.9f segundos\n\n", tamanio_total, tiempo_ejecucion);

    
    //libera espacio de la matriz
    for(int i=0; i<tamanio_total; i++) free(matriz[i]);
    free(matriz);

	//libera espacio del vector
	free(vector);


    return 0;

}
