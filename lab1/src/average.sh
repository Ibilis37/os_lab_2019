#!/bin/sh
result=0.0
average=0
if [ $# -eq 0]; then
echo "No parameters found"
else
echo Start
for param in "$@";
do average=$(($average+${param}))
done
average=$(($average*100))
result=$(($average/$#))
res1_=$(($result/100))
res2_=$(($result/10))
res2_=$(($res2_%10))
res3_=$(($result%10))
echo "$res1_.$res2_$res3_"
exit
fi
