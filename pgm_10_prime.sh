#!/bin/bash
echo "Enter a number : "
read a
flag=0
c=2

while [ $c -lt $a ]
do
if [ `expr $a % $c` -eq 0 ] 
then
flag=1
fi
((c++))
done
if [ $a -eq 2 ] 
then
echo "Prime"
elif [ $flag -eq 0 ] 
then
echo "Prime"
else
echo "Not Prime"
fi
