#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc,char**argv){

	int i,n=20,tid, num_hebras; //se include una variable que contendra el numero de hebras
	int a[n],suma=0,sumalocal;

	if(argc<3){ //Se suma un parametro de entrada como piden en el enunciado
	
		fprintf(stderr,"[ERROR]-SON 3 ARGUMENTOS, INTRODUCE EL NUMERO DE ITERACIONES Y EL NUMERO DE HEBRAS: ./ejecutable [iteraciones] [nºhebras]\n");
		exit(-1);
		
	}

	num_hebras = atoi(argv[2]); //Se almacena el valor de las iteraciones en la variable correspondiente
	n =atoi(argv[1]); 
	

	if(n>20)n=20;

	for(i=0;i<n;i++){
		a[i]=i;
	}

	#pragma omp parallel num_threads(num_hebras) if(n>4) default(none) private(sumalocal,tid) shared(a,suma,n)//se incluye num_threads(x)	
	{	
		sumalocal=0;
		tid=omp_get_thread_num();

		#pragma omp for private(i) schedule(static) nowait
			for(i=0;i<n;i++)
			{   
				sumalocal +=a [i];
				printf(" thread %d suma de a[%d]=%d sumalocal=%d \n",tid,i,a[i],sumalocal);
			}
		#pragma omp atomic
			suma +=sumalocal;
		#pragma omp barrier
		#pragma omp master
			printf("thread master=%d imprime suma=%d\n",tid,suma);
	}
}
