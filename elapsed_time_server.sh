#!/bin/bash

time_sum=0
time_mean=0
pi_sum=0
pi_mean=0

cases=0
total_cases=120

rm -rf test
mkdir test
cd test
mkdir ttime
mkdir pi
cd ..


for c in 2 4 8 16
do
	for n in 3 4 5
	do
		for i in {1..10}
		do
			./build/server $c $n
            cases=$(($cases+1))
            printf "[%d/%d] cases (number_of_clients: %d,  number_of_points: %d)\n" $cases $total_cases $c $n
		done

		while read time_data
		do
			time_sum=$(($time_sum+$time_data))
		done < time_out.txt

        while read pi_data
		do
			# pi_sum=$(($pi_sum+$pi_data))
            pi_sum=$( echo "scale=10;$pi_sum+$pi_data" | bc )
		done < pi_out.txt

        time_mean=$( echo "scale=0;$time_sum/10" | bc ) # Média de 10 execuções para o caso "c n" aka Ponto no gráfico
        pi_mean=$( echo "scale=10;$pi_sum/10" | bc ) # Média de 10 execuções para o caso "c n" aka Ponto no gráfico
        

        echo $n $time_mean >> test/ttime/$c.txt    
        echo $n $pi_mean >> test/pi/$c.txt    

    
        time_mean=0
        time_sum=0
        pi_mean=0
        pi_sum=0
		rm time_out.txt
        rm pi_out.txt
	done
done 	
exit 0