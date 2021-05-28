#!/bin/bash

sum=0
mean=0
cases=0
rm -rf time_test
mkdir time_test
for c in 16
do
	for n in 3
	do
		for i in {1..10}
		do
            echo $c $n
			./build/server $c $n --exectime >> $n.txt 	
            cases=$(($cases+1))
            # cases / 320 * 100
            #printf "[%d/320] cases (number_of_clients: %d,  number_of_points: %d) -> %ld\n" $cases $c $n
		done

		while read data
		do
            echo $data
			sum=$(($sum+$data))
		done < $n.txt

        mean=$( echo "scale=0;$sum/10" | bc ) # Média de 10 execuções para o caso "c n" aka Ponto no gráfico

        echo $n $mean >> time_test/$c.txt    
    
        mean=0
        sum=0
		rm out.txt
	done
done 	
exit 0