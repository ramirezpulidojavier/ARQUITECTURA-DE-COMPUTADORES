#!/bin/bash

for (( i = 65536; i <= 67108864 ; i*=2 )); do
    time ./SumaVectores_ejer7 $i 
done
