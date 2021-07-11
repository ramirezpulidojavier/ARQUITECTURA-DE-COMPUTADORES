/* SumaVectores.c 
 Suma de dos vectores: v3 = v1 + v2
 
 Para compilar usar (-lrt: real time library, es posible que no sea necesario usar -lrt):  
	gcc  -O2  SumaVectores.c -o SumaVectores -lrt
	gcc  -O2 -S SumaVectores.c -lrt 

 Para ejecutar use: SumaVectoresC longitud
		
*/ 

#include <stdlib.h>	// biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h>	// biblioteca donde se encuentra la función printf()
#include <time.h>	// biblioteca donde se encuentra la función clock_gettime() 
#include <omp.h>
//Sólo puede estar definida una de las tres constantes VECTOR_ (sólo uno de los ... 
//tres defines siguientes puede estar descomentado):
//#define VECTOR_LOCAL	// descomentar para que los vectores sean variables ...
			// locales (si se supera el tamaño de la pila se ...
			// generará el error "Violación de Segmento")
#define VECTOR_GLOBAL // descomentar para que los vectores sean variables ...
			// globales (su longitud no estará limitada por el ...
			// tamaño de la pila del programa)
//#define VECTOR_DYNAMIC	// descomentar para que los vectores sean variables ...
			// dinámicas (memoria reutilizable durante la ejecución)

#ifdef VECTOR_GLOBAL
#define MAX 33554432	//=2^25
   
double v1[MAX], v2[MAX], v3[MAX]; 
#endif
int main(int argc, char** argv){ 
  
  int i,k,j,l; 

  struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecución

  //Leer argumento de entrada (nº de componentes del vector)
  if (argc<2){	
    printf("Faltan nº componentes del vector\n");
    exit(-1);
  }
  
  unsigned int N = atoi(argv[1]);	// Máximo N =2^32-1=4294967295 (sizeof(unsigned int) = 4 B)
  printf("Tamaño Vectores:%u (%lu B)\n",N, sizeof(unsigned int)); 
  #ifdef VECTOR_LOCAL
  double v1[N], v2[N], v3[N];   // Tamaño variable local en tiempo de ejecución ...
				// disponible en C a partir de C99 
  #endif
  #ifdef VECTOR_GLOBAL
  if (N>MAX) N=MAX;
  #endif
  #ifdef VECTOR_DYNAMIC
  double *v1, *v2, *v3;
  v1 = (double*) malloc(N*sizeof(double));// malloc necesita el tamaño en bytes
  v2 = (double*) malloc(N*sizeof(double));
  v3 = (double*) malloc(N*sizeof(double));
  if ((v1 == NULL) || (v2 == NULL) || (v2 == NULL)) {	
    printf("No hay suficiente espacio para los vectores \n");
    exit(-2);
  }
  #endif

  //Inicializar vectores

  double t_inicial, t_final, t_total;

  #pragma omp parallel
  {
    #pragma omp sections
     {
	#pragma omp section  
  	for(i=0; i<N/4; i++){ 
 	   v1[i] = N*0.1+i*0.1; v2[i] = N*0.1-i*0.1;
 	 } 
 
	#pragma omp section
	for(j=N/4; j<N/2; j++){
	   v1[j] = N*0.1+j*0.1; v2[j] = N*0.1-j*0.1;
	}

	#pragma omp section
	for(k=N/2; k<3*N/4; k++){
	   v1[k] = N*0.1+k*0.1; v2[k] = N*0.1-k*0.1;
	}

	#pragma omp section
	for(l=3*N/4; l<N; l++){
	   v1[l] = N*0.1+l*0.1; v2[l] = N*0.1-l*0.1;
	}
     }

	#pragma omp single
	t_inicial = omp_get_wtime();

	#pragma omp sections
	{

	  #pragma omp section 
  	   for(i=0; i<N/4; i++) 
            v3[i] = v1[i] + v2[i]; 
	 
	#pragma omp section 
  	   for(j=N/4; j<N/2; j++) 
            v3[j] = v1[j] + v2[j];

	#pragma omp section 
  	   for(k=N/2; k<3*N/4; k++) 
            v3[k] = v1[k] + v2[k];

	#pragma omp section 
  	   for(l=3*N/4; l<N; l++) 
            v3[l] = v1[l] + v2[l];
       }

	#pragma omp single
	 t_final = omp_get_wtime();
       }

	t_total = t_final - t_inicial;

  //Imprimir resultado de la suma y el tiempo de ejecución
  #ifdef PRINTF_ALL
  printf("Tiempo:%11.9f\t / Tamaño Vectores:%u\n",t_total,N);  
  }
  #else
    printf("Tiempo:%11.9f\t / Tamaño Vectores:%u\n",t_total,N);
 

  #endif
  return 0; 
}

