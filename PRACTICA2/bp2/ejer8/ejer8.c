#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){

	double t_ini, t_fin, resultado_final, final;
	int i,j;
	

	if(argc<=1){

		printf("Tienen que ser dos argumentos\n");
		exit(-1);

	}

	unsigned int N= atoi(argv[1]);

	double *primer_vector, *segundo_vector, **M;
	
	segundo_vector=(double*) malloc(N*sizeof(double));
	primer_vector=(double*) malloc(N*sizeof(double));
	M = (double**) malloc(N*sizeof(double *));

	if((M==NULL)|| (segundo_vector==NULL) || (primer_vector==NULL) ){

		printf("Fallo reservando los vectores\n");
		exit(-2);
	
	}

	for (i=0; i<N; i++){
		
		M[i] = (double*) malloc(N*sizeof(double));
		
		if (M[i]==NULL){
			
			printf("Fallo reservando los vectores\n");
			exit(-2);
		
		}
		
	}

	//Inicializar matriz y vectores

	for(i=0; i<N; i++){
		
		for(j=0; j<N; j++){
			
			M[i][j]=1;
		
		}
	
	}

	for(i=0; i<N; i++){
		
		primer_vector[i]=1;
	
	}

	t_ini = omp_get_wtime();

	for(i=0; i<N; i++){
		
		final=0;
		
		for(j=0; j<N; j++){
		
			final+=(primer_vector[j] * M[i][j]);
		
		}
		
		segundo_vector[i]=final;
	
	}

	t_fin = omp_get_wtime();
	
	
	resultado_final = t_fin-t_ini;

	printf("Tiempo(seg.): %11.9f    Tamanio:%u     segundo_vector[0]=%8.6f      segundo_vector[%d]=%8.6f\n", resultado_final,N,segundo_vector[0],N-1,segundo_vector[N-1]);

	if (N<20){
		
		for(i=0; i<N; i++)
			printf("%f ", segundo_vector[0]);
	
	}
	
	printf("\n");


	//liberar memoria
	
	free(segundo_vector);
	
	free(primer_vector); 
	
	//liberar memoria de la matriz

	for(j=0; j<N; j++)   free(M[j]);
	
	free(M);

	
	
	return 0;


}
