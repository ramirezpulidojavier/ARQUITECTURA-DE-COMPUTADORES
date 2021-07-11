#include<stdio.h>
#include<stdlib.h>
#ifdef _OPENMP
 #include<omp.h>
#else
 #define omp_get_thread_num() 0
#endif

main(int argc,char**argv)
{
  int i,n=200,chunk,a[n],suma=0;
  
  if(argc!=3){
     fprintf(stderr,"\nTienes que poner: ./ejecutables iteraciones chunck\n");
     exit(-1);

  }

  n =atoi(argv[1]); if(n>200) n=200;chunk=atoi(argv[2]);
	omp_sched_t version;
	int run_sched_var;
	int nthreads_var = omp_get_max_threads(), dyn_var = omp_get_dynamic(), thread_limit_var = omp_get_thread_limit();
	

  for(i=0;i<n;i++) a[i]=i;

  #pragma omp parallel for firstprivate(suma) lastprivate(suma)schedule(dynamic,chunk)
  for(i=0;i<n;i++){
    suma =suma +a[i];
    printf(" thread %d suma a[%d]=%d suma=%d \n",omp_get_thread_num(),i,a[i],suma);
	printf("Numero de hebras: omp_get_num_threads() = %d\n", omp_get_num_threads());
  };

  #pragma omp parallel for firstprivate(suma) lastprivate(suma)schedule(dynamic,chunk)
  for(i=0;i<n;i++){
    suma =suma +a[i];
    printf(" thread %d suma a[%d]=%d suma=%d \n",omp_get_thread_num(),i,a[i],suma);
  }
	#pragma omp single 
	omp_get_schedule(&version, &run_sched_var); //Se actualizan las variables 

	printf("\nValores actuales: ");
	printf("\ndyn-var: %d ", omp_get_dynamic());
	printf("\nnthreads-var: %d ", omp_get_dynamic());
	printf("\nrun-sched-var: ");
	printf("\n\ttipo: %d", version);
	printf("\n\tmodificacion: %d", run_sched_var);
	printf("\n");

	omp_set_dynamic(1);
	omp_set_num_threads(5);
	omp_set_schedule(omp_sched_static, 2*chunk);

	omp_get_schedule(&version, &run_sched_var); //Se actualizan las variables tras los cambios

	printf("\nValores modificados: ");
	printf("\ndyn-var: %d ", omp_get_dynamic());
	printf("\nnthreads-var: %d ", omp_get_dynamic());
	printf("\nrun-sched-var: ");
	printf("\n\ttipo: %d", version);
	printf("\n\tmodificacion: %d", run_sched_var);
	printf("\n");

  printf("Fuera de 'parallel for' suma=%d\n",suma);

}
