
//gcc -fopenmp -O2 single.c -o single

#include <stdio.h>
#include <omp.h>
int main() {

	int n = 9, i, a, b[n];
	
	for (i=0; i<n; i++) 
		b[i] = -1;
	
	#pragma omp parallel
	{
		#pragma omp single
		{ 
			printf("Introduce valor de inicialización a: ");
			scanf("%d", &a );
			printf("Single ejecutada por el thread %d\n", omp_get_thread_num());
		}
		
		#pragma omp for
			for (i=0; i<n; i++)
				b[i] = a;
	
		#pragma omp single
		{
			printf("La hebra %d muestra los datos:\n", omp_get_thread_num());
	
			for(i=0;i<n;i++) printf("b[%d] = %d .Ejecutada por la hebra %d\n",i,b[i],omp_get_thread_num());

		
		}



	}
	
	
}
