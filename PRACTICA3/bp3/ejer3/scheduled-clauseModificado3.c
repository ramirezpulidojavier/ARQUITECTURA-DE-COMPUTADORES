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
	omp_get_schedule(&version, &run_sched_var);

  for(i=0;i<n;i++) a[i]=i;

  #pragma omp parallel for firstprivate(suma) lastprivate(suma)schedule(dynamic,chunk)
  for(i=0;i<n;i++){
    suma =suma +a[i];
    printf(" thread %d suma a[%d]=%d suma=%d \n",omp_get_thread_num(),i,a[i],suma);
  }
  #pragma omp single   //Solo realizará lo siguiente la hebra que llegue antes a esta clausula. Otra opcion seria poner un identificador cualquiera 
  					   //y que unicamente esa hebra entre en el if que contenga el codigo siguiente
	if(version == omp_sched_static) printf("\nVersion: estatica\n");
	if(version == omp_sched_guided) printf("\nVersion: guided\n");
	if(version == omp_sched_dynamic) printf("\nVersion: dinamica\n");
	printf("Y el valor de las variables es: \n");	
	printf("\tLa hebra %d muestra dyn-var %d \n", omp_get_thread_num(), dyn_var);
	printf("\tLa hebra %d muestra nthreads_var %d \n", omp_get_thread_num(), nthreads_var);
	printf("\tLa hebra %d muestra thread_limit_var %d \n", omp_get_thread_num(), thread_limit_var);
	printf("\tLa hebra %d muestra run-sched-var mod %d \n", omp_get_thread_num(), run_sched_var );
	
	

  printf("\nFuera de 'parallel for' las variables son:");
if(version == omp_sched_static) printf("\nVersion: estatica\n");
	if(version == omp_sched_guided) printf("\nVersion: guided\n");
	if(version == omp_sched_dynamic) printf("\nVersion: dinamica\n");
  printf("\tsuma=%d\n\tdyn-var %d\n\tnthreads-var %d\n\tthread-limit-var %d\n\trun-sched-var mod %d\n",suma,dyn_var,nthreads_var, thread_limit_var, run_sched_var);
	

}
