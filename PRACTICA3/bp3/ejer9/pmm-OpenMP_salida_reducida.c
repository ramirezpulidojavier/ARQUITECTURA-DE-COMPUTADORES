#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
    #define omp_get_num_threads() 1
    #define omp_set_num_threads(int)
    #define omp_in_parallel() 0
    #define omp_set_dynamic(int)
#endif

main(int argc,char**argv)
{

	//Comprueba que la cantidad de argumentos es la correcta
    if(argc!=2){

         printf("\nFalta el numero de elementos del primera_matriz\n");
         exit(-1);
    }

    //Declaracion de variables
    unsigned int tamanio_total = atoi(argv[1]);
    double tiempo_antes, tiempo_despues, tiempo_ejecucion;

    //Reserva para matrices
    int **primera_matriz = (int**) malloc(tamanio_total*sizeof(int * ));
    int **segunda_matriz = (int**) malloc(tamanio_total*sizeof(int * ));
    int **matriz = (int **)malloc(tamanio_total*sizeof(int *));
    
    for(int i = 0; i<tamanio_total; i++){
    	matriz[i] = (int *) malloc (tamanio_total*sizeof(int));
        primera_matriz[i] = (int *) malloc (tamanio_total*sizeof(int));
        segunda_matriz[i] = (int *) malloc (tamanio_total*sizeof(int));
    }

    //Comprueba que la reserva de memoria fue correcta
    if(primera_matriz==0 || segunda_matriz==0 || matriz==0){
	    printf("La reserva de espacio para las matrices ha dado fallo\n");
	    exit(-2);
    }

    //Comprueba que la reserva de memoria fue correcta
    for(int i=0; i<tamanio_total; i++)
	    if(primera_matriz[i]==0 || segunda_matriz[i]==0 || matriz[i]==0){
	        printf("La reserva de espacio ha dado fallo\n");
	        exit(-2);
	    }

	int j,k;
    #pragma omp parallel for private(j)
    for(int i=0; i<tamanio_total; i++){
	    for(j=0; j<tamanio_total; j++){
	        matriz[i][j] = 0;
	        primera_matriz[i][j] = i+2;
	        segunda_matriz[i][j] = i+9;
        }
    }

    //Realiza las cuentas y se mide el tiempo antes y despues de hacerlo para calcular el tiempo de ejecucion
    tiempo_antes = omp_get_wtime();

    
    #pragma omp parallel for private(j,k)
    for(int i=0; i<tamanio_total; i++)
	    for( j=0; j<tamanio_total; j++) 
	    	for( k=0; k<tamanio_total; k++) 
                matriz[i][j] += primera_matriz[i][k] * segunda_matriz[k][j];
    

    tiempo_despues = omp_get_wtime();
	tiempo_ejecucion=tiempo_despues-tiempo_antes;
    

    //Muestra dimension y tiempo final
    printf("\nDimension de las matrices: %d    Tiempo: %11.9f segundos\n\n", tamanio_total, tiempo_ejecucion);
    printf("\nPrimer elemento (matriz_resultado[0][0]) = %d,    Ultimo elemento (matriz_resultado[%d][%d]) = %d\n\n",
	matriz[0][0],tamanio_total-1,tamanio_total-1,matriz[tamanio_total-1][tamanio_total-1]);


    return 0;

}

