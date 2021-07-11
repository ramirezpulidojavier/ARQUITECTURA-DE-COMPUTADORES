#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){

	if(argc<=1){

		printf("Mete dos argumentos\n");
		exit(-1);

	}

	double t_ini;
	double t_fin;
	double resultado_final;
	double final;
	int i,j;
	unsigned int Dim= atoi(argv[1]);

	double *primer_vector=(double*) malloc(Dim*sizeof(double));
	double *segundo_vector=(double*) malloc(Dim*sizeof(double));
	double **M(double**) malloc(Dim*sizeof(double *));

	if( (M==NULL) || (segundo_vector==NULL) || (primer_vector==NULL)){

		printf("Error en la reserva\n");
		exit(-2);
	
	}

	for (i=0; i<Dim; i++){
		
		M[i] = (double*) malloc(Dim*sizeof(double));
		
		if (M[i]==NULL){
		
			printf("Error en la reserva\n");
			exit(-2);
		
		}
	
	}
	
	//Inicializacion
	#pragma omp parallel private(i)
	{
		#pragma omp for
		for(i=0; i<Dim; i++){
			
			primer_vector[i]=1;
		
		}

		#pragma omp for private(j)
		for(i=0; i<Dim; i++){
			
			for(j=0; j<Dim; j++)
				M[i][j]=1;
			
		}

		#pragma omp single
		{
			t_ini = omp_get_wtime();
		}


		for(i=0; i<Dim; i++){
			#pragma omp for reduction(+:final)
			for(j=0; j<Dim; j++){
			
				final+=(primer_vector[j]*M[i][j]);
			
			}
			#pragma omp single
			{
				segundo_vector[i]=final;
				final=0;
			}
			
			
		}

		#pragma omp single
		{
			t_fin = omp_get_wtime();
		}

	}
	
	resultado_final = t_fin-t_ini;

	printf("Tiempo: %11.9f\n ", resultado_final);
	printf("Tamanio: %u\n", Dim);
	printf("segundo_vector[0]=%8.6f\n",segundo_vector[0]);
	printf("segundo_vector[%d]=%8.6f\n", Dim-1,segundo_vector[Dim-1]);


	if (Dim<20){
		
		for(i=0; i<Dim; i++)
			printf("%f ", segundo_vector[i]);
		
	
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

