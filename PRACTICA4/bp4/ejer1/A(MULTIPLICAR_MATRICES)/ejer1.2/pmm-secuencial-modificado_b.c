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

    //Declaro 8 vectores y uno para resultado
    int vector_resultado, primerv, segundov, tercerv, cuartov, quintov, sextov, septimov, octavov, repeticiones = tamanio_total/8;
    primerv = segundov = tercerv = cuartov = quintov = sextov = septimov = octavov = 0;


    //Reserva para matrices
    int **primera_matriz = (int**) malloc(tamanio_total*sizeof(int*));
    int **segunda_matriz = (int**) malloc(tamanio_total*sizeof(int*));
    int **matriz         = (int **)malloc(tamanio_total*sizeof(int*));
    
    for(int i = 0; i<tamanio_total; i++){
    	matriz[i]         = (int *) malloc (tamanio_total*sizeof(int));
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

	//Rellenar la matriz, primera_matriz y primera_matriz de resultados
    for(int i=0; i<tamanio_total; i++){
	    for(int j=0; j<tamanio_total; j++){
	        matriz[i][j]         =  0 ;
	        primera_matriz[i][j] = j*2;
	        segunda_matriz[i][j] = j+2;
        }
    }

    //Realiza las cuentas y se mide el tiempo antes y despues de hacerlo para calcular el tiempo de ejecucion
    tiempo_antes = omp_get_wtime();
    int aux;
    for(int i=0; i<tamanio_total; i++){
	for(int j=0; j<tamanio_total; j++){
	   aux = 0; 
	   for(int k=0; k<repeticiones; k++){

		primerv  += (primera_matriz[i][aux+0]*segunda_matriz[j][aux+0]);
		segundov += (primera_matriz[i][aux+1]*segunda_matriz[j][aux+1]);
		tercerv  += (primera_matriz[i][aux+2]*segunda_matriz[j][aux+2]);
		cuartov  += (primera_matriz[i][aux+3]*segunda_matriz[j][aux+3]);
		quintov  += (primera_matriz[i][aux+4]*segunda_matriz[j][aux+4]);
		sextov   += (primera_matriz[i][aux+5]*segunda_matriz[j][aux+5]);
		septimov += (primera_matriz[i][aux+6]*segunda_matriz[j][aux+6]);
		octavov  += (primera_matriz[i][aux+7]*segunda_matriz[j][aux+7]);
		aux += 8;

	   } 
               	
    		vector_resultado = primerv + segundov + tercerv + cuartov + quintov + sextov + septimov + octavov;
		matriz[i][j] = vector_resultado;

		for(aux = repeticiones*8 ; aux<tamanio_total; aux++){

			vector_resultado = vector_resultado + (segunda_matriz[j][aux]*primera_matriz[i][aux]);

		}

		matriz[i][j] = vector_resultado;
	  }
	}

    tiempo_despues = omp_get_wtime();
    tiempo_ejecucion=tiempo_despues-tiempo_antes;
    
    //Muestra dimension y tiempo final
    printf("\nDimension de las matrices: %d    Tiempo: %11.9f segundos\n\n", tamanio_total, tiempo_ejecucion);
    printf("\nPrimer elemento (matriz_resultado[0][0]) = %d,    Ultimo elemento (matriz_resultado[%d][%d]) = %d\n\n",matriz[0][0],tamanio_total-1,tamanio_total-1,matriz[tamanio_total-1][tamanio_total-1]);


    return 0;

}

