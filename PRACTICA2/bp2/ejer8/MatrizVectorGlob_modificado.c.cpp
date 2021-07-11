#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXIMO 67108864

int main(int argc, char** argv){
	
	if(argc<2){
		
		printf("Faltan elementos en el vector");
		exit(-1);
		
	}
	
	struct timespec tiempo1, tiempo2;
	double tiempo_total;
	
	unsigned int TOTAL = atoi(argv[1]);
	
	if(TOTAL>MAXIMO) TOTAL=MAXIMO;
	
	double matriz[TOTAL][TOTAL];
	double vector[TOTAL];
	double comp[TOTAL];
	int i, j;
	
	#pragma omp parallel for private(i,j)
	
	for(i=0; i<TOTAL; i++){
		
		for(j=0;j<TOTAL;j++){
			
			 matriz[i][j] = TOTAL*0.1+i*0.1+j*0.05;
			
		}
		
		vector[i]=TOTAL*0.1+j*0.1;
		comp[i]=0;
		
	}
	
	clock_gettime(CLOCK_REALTIME,&tiempo1);
	
	#pragma omp parallel for private(i,j)
	
	//mostrar los valores
	
	for(i=0;i<TOTAL;i++){
		
		for(j=0;j<TOTAL;j++){
			
			printf("%11.9f\n", matriz[i][j]);
			
		}
		
	}
	
	for(i=0;i<TOTAL;i++){
			
			printf("%11.9f\n", comp[i]);
			
	}
	
	for(i=0;i<TOTAL;i++){
			
			printf("%11.9f\n", vector[i]);
			
	}
	
	tiempo_total=(double)(tiempo2.tv_sec-tiempo1.tv_sec)+(double)((tiempo2.tv_nsec-tiempo1.tv_nsec)/(1.e+9));

	printf("El tamanio del vector y de la matriz son: %d \n", TOTAL);
	printf("El tiempo de ejecucion es: %11.9f\n", tiempo_total);
	
	return 0;		
}


