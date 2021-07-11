#!/bin/bash

for ((P=100;P<=1200100;P+=80000))
do
   ./daxpy2 $P $P
done

