#!/bin/bash
echo "ENTER ARRAY : "
read -a a
n=${#a[*]}
for((i=1;i<n;i++))
do
   temp=${a[i]}
   j=$((i-1))
   while [ $temp -lt ${a[j]} ]
   do
      a[j+1]=${a[j]}
      let j--
      if [ $j == -1 ]
      then
         break
      fi
   done
   a[j+1]=$temp
done
echo "SORTED ARRAY"
echo ${a[*]}
