#!/bin/bash

 

export OMP_NUM_THREADS=1
echo 1
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat
 
export OMP_NUM_THREADS=2
echo 2
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat
 
export OMP_NUM_THREADS=3
echo 3
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat
 
export OMP_NUM_THREADS=4
echo 4
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat

export OMP_NUM_THREADS=5
echo 5
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat

export OMP_NUM_THREADS=6
echo 6
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat

export OMP_NUM_THREADS=7
echo 7
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat

export OMP_NUM_THREADS=8
echo 8
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat

export OMP_NUM_THREADS=9
echo 9
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat

export OMP_NUM_THREADS=10
echo 10
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat

export OMP_NUM_THREADS=11
echo 11
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat

export OMP_NUM_THREADS=12
echo 12
./pmv-OpenMP-a  20000 >> tiempos_9_a_segundaparte_segundotamanio.dat
