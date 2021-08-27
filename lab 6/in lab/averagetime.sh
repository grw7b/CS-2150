#!/bin/bash
#averagetime.h
echo "Input dictionary file: "
read dictionary

echo "Input grid file: "
read grid

sum=0

t1 = `./a.out $dictionary $grid | tail -1`
((sum=sum+t1))

t2 = `./a.out $dictionary $grid | tail -1`
((sum=sum+t2))

t3 = `./a.out $dictionary $grid | tail -1`
((sum=sum+t3))

t4 = `./a.out $dictionary $grid | tail -1`
((sum=sum+t4))

t5 = `./a.out $dictionary $grid | tail -1`
((sum=sum+t5))

((average=sum/5))

echo "Average time was $average"