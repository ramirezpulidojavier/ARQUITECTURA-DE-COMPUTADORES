#!/bin/bash

for ((P=100;P<=1200100;P+=80000))
do
   ./daxpys_tiempo $P $P >> cuentas.dat
done

