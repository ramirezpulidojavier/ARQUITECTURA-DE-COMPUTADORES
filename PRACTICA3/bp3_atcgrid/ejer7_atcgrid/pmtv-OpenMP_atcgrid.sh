#!/bin/bash

#Declaracion de array con los tipos que hay
declare -a versiones=("dynamic" "static" "guided")

#Numero de hebras
export OMP_NUM_THREADS=12

#for que recurra cada tipo de los delarados en el vector
for i in "${versiones[@]}"
do
	echo -e
	echo "************************************************$i************************************************"
	echo -e
	let j=0
	#bucle que se hace 3 veces para probar cada tipo de los disponibles
	while [ $j -le 3 ];do  
		 #Si es 0 coincide con dinamico
		if [ $j -eq 0 ] 
		then
			echo "Chunck: 1" 
			echo "Tipo: $i"
			export OMP_SCHEDULE="$i,1"
		#Si es 1 coincide con estatico
		elif [ $j -eq 1 ] 
		then
			echo "Chunck: Por defecto" 
			echo "Tipo: $i"
			export OMP_SCHEDULE="$i"
		#Si es 2 coincide con guided
		elif [ $j -eq 2 ] 
		then
			echo "Chunck: 64" 
			echo "Tipo: $i"
			export OMP_SCHEDULE="$i,64"
		fi
		
		#Ejecutamos para 1536
		./pmtv-OpenMP 15360
		echo "-----------------------------------------------------------------------------------"

		#Aumentamos el valor de j para el bucle
		let j=$j+1
	done
done
