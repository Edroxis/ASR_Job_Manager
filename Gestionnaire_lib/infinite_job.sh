#!/bin/bash
cpt = 0
i = 0
b=10000
while :
do
	if [ 10000 -eq "$i" ]
	then
		i=0;
	fi
	((i+=1));
	((cpt+=1));
done
exit 0
