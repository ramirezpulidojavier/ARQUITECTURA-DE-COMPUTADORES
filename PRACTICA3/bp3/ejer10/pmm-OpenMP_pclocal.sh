#!/bin/bash
 
echo "Secuencial:"
./pmm-secuencia_salida_reducida  105
./pmm-secuencia_salida_reducida  500
./pmm-secuencia_salida_reducida  750
./pmm-secuencia_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 2 threads:"
export OMP_NUM_THREADS=2

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 3 threads:"
export OMP_NUM_THREADS=3

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 4 threads:"
export OMP_NUM_THREADS=4

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900