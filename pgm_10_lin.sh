#!/bin/bash
echo "Enter Array"
read -a a
echo "Enter Element to Search"
read n
flag=0;
for i in ${a[*]}
do
 if [ $i -eq $n ]
then
	flag=1;
 fi
done
if [ $flag -eq 1 ]
then
	echo "ELEMENT FOUND"
else 
	echo "ELEMENT NOT FOUND"
fi

