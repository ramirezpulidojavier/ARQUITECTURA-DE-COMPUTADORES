#!/bin/bash


export OMP_NUM_THREADS=1
echo 1
./pmv-OpenMP-a  10000 >> tiempos_9_a_segundaparte_primertamanio.dat
 
export OMP_NUM_THREADS=2
echo 2
./pmv-OpenMP-a  10000 >> tiempos_9_a_segundaparte_primertamanio.dat
 
export OMP_NUM_THREADS=3
echo 3
./pmv-OpenMP-a  10000 >> tiempos_9_a_segundaparte_primertamanio.dat
 
export OMP_NUM_THREADS=4
echo 4
./pmv-OpenMP-a  10000 >> tiempos_9_a_segundaparte_primertamanio.dat
 

export OMP_NUM_THREADS=1
echo 5
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat
 
export OMP_NUM_THREADS=2
echo 6
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat
 
export OMP_NUM_THREADS=3
echo 7
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat
 
export OMP_NUM_THREADS=4
echo 8
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat
