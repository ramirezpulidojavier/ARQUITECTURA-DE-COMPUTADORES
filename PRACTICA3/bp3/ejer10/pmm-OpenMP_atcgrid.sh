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

echo "------------------------------------------------"
echo "Paralelo con 5 threads:"
export OMP_NUM_THREADS=5

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 6 threads:"
export OMP_NUM_THREADS=6

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 7 threads:"
export OMP_NUM_THREADS=7

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 8 threads:"
export OMP_NUM_THREADS=8

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 9 threads:"
export OMP_NUM_THREADS=9

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 10 threads:"
export OMP_NUM_THREADS=10

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 11 threads:"
export OMP_NUM_THREADS=11

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900

echo "------------------------------------------------"
echo "Paralelo con 12 threads:"
export OMP_NUM_THREADS=12

./pmm-OpenMP_salida_reducida  105
./pmm-OpenMP_salida_reducida  500
./pmm-OpenMP_salida_reducida  750
./pmm-OpenMP_salida_reducida  900