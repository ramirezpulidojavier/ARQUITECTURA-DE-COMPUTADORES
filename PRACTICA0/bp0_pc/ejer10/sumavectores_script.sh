#!/bin/bash

for ((P=65536;P<67108865;P=P*2))
do
   ./SumaVectores $P
done

