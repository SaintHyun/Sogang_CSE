#!/bin/sh 

read -p "working directory: " name

if [ "$name" = "\n" ]
then 
	for i in *
	do
		if [ -f $i ]
		then		
			before=i
			mv $i `echo $i | tr '[:upper:] [:lower:]' '[:lower:] [:upper:]'`
		fi
	done
	
elif cd "$name" 
then
	for i in *
	do
		if [ -f $i ]
		then			
			mv $i `echo $i|tr '[:upper:] [:lower:]' '[:lower:] [:upper:]'`
		fi
	done

else
	echo "wrong direction"
fi
