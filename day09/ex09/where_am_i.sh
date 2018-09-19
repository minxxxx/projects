addr=$(ifconfig | grep "inet " | awk '{print $2}')
ls=$(ifconfig | grep "inet " | wc -l | sed 's/ //g')

if test -z $ls
then
	echo "Je suis perdu!\n"
else
	for ip in $addr
	do
		echo $ip
	done
fi
