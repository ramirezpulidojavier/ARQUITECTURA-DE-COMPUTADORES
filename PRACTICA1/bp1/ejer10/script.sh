#!/bin/bash

for ((P=16384;P<67108865;P=P*2))
do
   ./Sumavectores_atcgrid $P
done

